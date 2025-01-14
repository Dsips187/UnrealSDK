﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/Content/BeamContentSubsystem.h"

#include "HttpModule.h"
#include "BeamNotifications/SubSystems/BeamContentNotifications.h"
#include "Interfaces/IHttpResponse.h"
#include "Content/DownloadContentState.h"
#include "Kismet/GameplayStatics.h"

#if WITH_EDITOR
#include "BeamableCoreRuntimeEditor/Public/Subsystems/Content/BeamEditorContent.h"
#endif

void DescendLookingForContentLinks(const FString& TypeName, const FString& ContentTypeId, const FProperty* Property, TArray<const FProperty*>& TreePath,
                                   TArray<TArray<const FProperty*>>& FoundPathsToLinks,
                                   TArray<TArray<const FProperty*>>& FoundPathsToRecursiveProps, TArray<UClass*>& FoundRecursiveTypes)
{
	TreePath.Push(Property);

	TArray<FString> PathToProp;
	for (const FProperty* PathLink : TreePath)
		PathToProp.Add(PathLink->GetName());
	const auto PathStr = FString::Join(PathToProp, TEXT("."));

	// Recursive DFS of the property tree 
	if (const auto StructProperty = CastField<FStructProperty>(Property))
	{
		// TODO: Leaf nodes should be either FBeamContentLink OR FOptionalBeamContentLink (we should then handle both these leaf properties at runtime) 
		if (StructProperty->Struct == FBeamContentLink::StaticStruct())
		{
			// Copy the current tree path into the output paths to ContentLinks.
			FoundPathsToLinks.Add(TArray{TreePath});
			UE_LOG(LogBeamContent, Verbose, TEXT("Found Content Link in ContentType - TYPE=%s, TYPE_ID=%s, PATH_TO_LINK_FIELD=%s"), *TypeName, *ContentTypeId, *PathStr);
		}
		else
		{
			for (TFieldIterator<FProperty> ObjPropIt(StructProperty->Struct); ObjPropIt; ++ObjPropIt)
			{
				UE_LOG(LogBeamContent, Verbose, TEXT("Starting with Struct Field - TYPE=%s, TYPE_ID=%s, PATH_TO_LINK_FIELD=%s.%s"), *TypeName, *ContentTypeId, *PathStr, *ObjPropIt->GetName());
				DescendLookingForContentLinks(TypeName, ContentTypeId, *ObjPropIt, TreePath, FoundPathsToLinks, FoundPathsToRecursiveProps, FoundRecursiveTypes);
				UE_LOG(LogBeamContent, Verbose, TEXT("Done with Struct Field - TYPE=%s, TYPE_ID=%s, PATH_TO_LINK_FIELD=%s.%s"), *TypeName, *ContentTypeId, *PathStr, *ObjPropIt->GetName());
			}
		}
	}
	else if (CastField<FClassProperty>(Property))
	{
		// We do nothing when we bump into UClass fields here.
		return;
	}
	else if (const auto ObjectProperty = CastField<FObjectProperty>(Property))
	{
		// We do not need to go looking through recursive types.
		const auto bIsRootType = ObjectProperty->PropertyClass.GetName().Equals(TypeName);
		if (const int32 RecursiveIdx = TreePath.IndexOfByPredicate([Property](const FProperty* PropInTree) { return PropInTree->SameType(Property); }); RecursiveIdx != INDEX_NONE || bIsRootType)
		{
			FoundPathsToRecursiveProps.Add(TArray{TreePath});
			FoundRecursiveTypes.Add(ObjectProperty->PropertyClass);

			UE_LOG(LogBeamContent,
			       Verbose,
			       TEXT(
				       "Found recursive property inside a UObject field (the type of this property has a pointer to itself). We process this as a special case later. - TYPE=%s, TYPE_ID=%s, PATH_TO_RECURSIVE_FIELD=%s, RECURSIVE_TYPE=%s"
			       ),
			       *TypeName, *ContentTypeId, *PathStr, *ObjectProperty->PropertyClass.GetName()
			);
			TreePath.Pop();
			return;
		}

		for (TFieldIterator<FProperty> ObjPropIt(ObjectProperty->PropertyClass); ObjPropIt; ++ObjPropIt)
		{
			UE_LOG(LogBeamContent, Verbose, TEXT("Start with Object Field - TYPE=%s, TYPE_ID=%s, PATH_TO_FIELD=%s.%s"), *TypeName, *ContentTypeId, *PathStr, *ObjPropIt->GetName());
			DescendLookingForContentLinks(TypeName, ContentTypeId, *ObjPropIt, TreePath, FoundPathsToLinks, FoundPathsToRecursiveProps, FoundRecursiveTypes);
			UE_LOG(LogBeamContent, Verbose, TEXT("Start with Object Field - TYPE=%s, TYPE_ID=%s, PATH_TO_FIELD=%s.%s"), *TypeName, *ContentTypeId, *PathStr, *ObjPropIt->GetName());
		}
	}
	// If its an array of structs or objects, we descend into the array's type.
	else if (const auto ArrayProperty = CastField<FArrayProperty>(Property))
	{
		if (CastField<FClassProperty>(Property))
		{
			// We do nothing when we bump into UClass fields here.
			return;
		}

		if (const auto ArrayObjectProperty = CastField<FObjectProperty>(ArrayProperty->Inner))
		{
			// We do not need to go looking through recursive types.
			const auto bIsRootType = ArrayObjectProperty->PropertyClass.GetName().Equals(TypeName);
			const int32 RecursiveIdx = TreePath.IndexOfByPredicate([ArrayObjectProperty](const FProperty* PropInTree)
			{
				if (const auto InTree = CastField<FObjectProperty>(PropInTree)) return InTree->PropertyClass == ArrayObjectProperty->PropertyClass;
				return false;
			});

			if (RecursiveIdx != INDEX_NONE || bIsRootType)
			{
				FoundPathsToRecursiveProps.Add(TArray{TreePath});
				FoundRecursiveTypes.Add(ArrayObjectProperty->PropertyClass);

				UE_LOG(LogBeamContent,
				       Verbose,
				       TEXT(
					       "Found recursive property inside an array's type (the type of this property has a pointer to itself). We process this as a special case later. - TYPE=%s, TYPE_ID=%s, PATH_TO_RECURSIVE_FIELD=%s, RECURSIVE_TYPE=%s"
				       ),
				       *TypeName, *ContentTypeId, *PathStr, *ArrayObjectProperty->PropertyClass.GetName());

				TreePath.Pop();
				return;
			}

			for (TFieldIterator<FProperty> ObjPropIt(ArrayObjectProperty->PropertyClass); ObjPropIt; ++ObjPropIt)
			{
				UE_LOG(LogBeamContent, Verbose, TEXT("Start with Object Field [Array] - TYPE=%s, TYPE_ID=%s, PATH_TO_FIELD=%s.%s"), *TypeName, *ContentTypeId, *PathStr, *ObjPropIt->GetName());
				DescendLookingForContentLinks(TypeName, ContentTypeId, *ObjPropIt, TreePath, FoundPathsToLinks, FoundPathsToRecursiveProps, FoundRecursiveTypes);
				UE_LOG(LogBeamContent, Verbose, TEXT("End with Object Field [Array] - TYPE=%s, TYPE_ID=%s, PATH_TO_FIELD=%s.%s"), *TypeName, *ContentTypeId, *PathStr, *ObjPropIt->GetName());
			}
		}

		if (const auto ArrayStructProperty = CastField<FStructProperty>(ArrayProperty->Inner))
		{
			if (ArrayStructProperty->Struct->IsChildOf(FBeamContentLink::StaticStruct()))
			{
				// Copy the current tree path into the output paths to ContentLinks.
				FoundPathsToLinks.Add(TArray{TreePath});
				UE_LOG(LogBeamContent, Verbose, TEXT("Found Content Link Array in ContentType  - TYPE=%s, TYPE_ID=%s, PATH_TO_LINK_FIELD=%s"), *TypeName, *ContentTypeId, *PathStr);
			}
			else
			{
				for (TFieldIterator<FProperty> ObjPropIt(ArrayStructProperty->Struct); ObjPropIt; ++ObjPropIt)
				{
					UE_LOG(LogBeamContent, Verbose, TEXT("Start with Struct Field [Array] - TYPE=%s, TYPE_ID=%s, PATH_TO_FIELD=%s.%s"), *TypeName, *ContentTypeId, *PathStr, *ObjPropIt->GetName());
					DescendLookingForContentLinks(TypeName, ContentTypeId, *ObjPropIt, TreePath, FoundPathsToLinks, FoundPathsToRecursiveProps, FoundRecursiveTypes);
					UE_LOG(LogBeamContent, Verbose, TEXT("End with Struct Field [Array] - TYPE=%s, TYPE_ID=%s, PATH_TO_FIELD=%s.%s"), *TypeName, *ContentTypeId, *PathStr, *ObjPropIt->GetName());
				}
			}
		}
	}
	// If its an map of FString, we descend into the map's value type.
	else if (const auto MapProperty = CastField<FMapProperty>(Property))
	{
		if (CastField<FClassProperty>(Property))
		{
			// We do nothing when we bump into UClass fields here.
			return;
		}

		if (const auto MapObjectProperty = CastField<FObjectProperty>(MapProperty->ValueProp))
		{
			// We do not need to go looking through recursive types.
			const auto bIsRootType = MapObjectProperty->PropertyClass.GetName().Equals(TypeName);
			const int32 RecursiveIdx = TreePath.IndexOfByPredicate([MapObjectProperty](const FProperty* PropInTree)
			{
				if (const auto InTree = CastField<FObjectProperty>(PropInTree)) return InTree->PropertyClass == MapObjectProperty->PropertyClass;
				return false;
			});

			if (RecursiveIdx != INDEX_NONE || bIsRootType)
			{
				FoundPathsToRecursiveProps.Add(TArray{TreePath});
				FoundRecursiveTypes.Add(MapObjectProperty->PropertyClass);

				UE_LOG(LogBeamContent,
				       Verbose,
				       TEXT(
					       "Found recursive property inside a map's value type (the type of this property has a pointer to itself). We process this as a special case later. - TYPE=%s, TYPE_ID=%s, PATH_TO_RECURSIVE_FIELD=%s, RECURSIVE_TYPE=%s"
				       ),
				       *TypeName, *ContentTypeId, *PathStr, *MapObjectProperty->PropertyClass.GetName());

				TreePath.Pop();
				return;
			}

			for (TFieldIterator<FProperty> ObjPropIt(MapObjectProperty->PropertyClass); ObjPropIt; ++ObjPropIt)
			{
				UE_LOG(LogBeamContent, Verbose, TEXT("Start with Object Field [Map] - TYPE=%s, TYPE_ID=%s, PATH_TO_FIELD=%s.%s"), *TypeName, *ContentTypeId, *PathStr, *ObjPropIt->GetName());
				DescendLookingForContentLinks(TypeName, ContentTypeId, *ObjPropIt, TreePath, FoundPathsToLinks, FoundPathsToRecursiveProps, FoundRecursiveTypes);
				UE_LOG(LogBeamContent, Verbose, TEXT("End with Object Field [Map] - TYPE=%s, TYPE_ID=%s, PATH_TO_FIELD=%s.%s"), *TypeName, *ContentTypeId, *PathStr, *ObjPropIt->GetName());
			}
		}

		if (const auto MapStructProperty = CastField<FStructProperty>(MapProperty->ValueProp))
		{
			if (MapStructProperty->Struct->IsChildOf(FBeamContentLink::StaticStruct()))
			{
				// Copy the current tree path into the output paths to ContentLinks.
				FoundPathsToLinks.Add(TArray{TreePath});
				UE_LOG(LogBeamContent, Verbose, TEXT("Found Content Link Map in ContentType - TYPE=%s, TYPE_ID=%s, PATH_TO_LINK_FIELD=%s"), *TypeName, *ContentTypeId, *PathStr);
			}
			else
			{
				for (TFieldIterator<FProperty> ObjPropIt(MapStructProperty->Struct); ObjPropIt; ++ObjPropIt)
				{
					UE_LOG(LogBeamContent, Verbose, TEXT("Start with Struct Field [Map] - TYPE=%s, TYPE_ID=%s, PATH_TO_FIELD=%s.%s"), *TypeName, *ContentTypeId, *PathStr, *ObjPropIt->GetName());
					DescendLookingForContentLinks(TypeName, ContentTypeId, *ObjPropIt, TreePath, FoundPathsToLinks, FoundPathsToRecursiveProps, FoundRecursiveTypes);
					UE_LOG(LogBeamContent, Verbose, TEXT("End with Struct Field [Map] - TYPE=%s, TYPE_ID=%s, PATH_TO_FIELD=%s.%s"), *TypeName, *ContentTypeId, *PathStr, *ObjPropIt->GetName());
				}
			}
		}
	}
	else
	{
		UE_LOG(LogBeamContent, Verbose, TEXT("Skipping Property as isn't a Content Link and can't contain one - TYPE=%s, TYPE_ID=%s, PATH_TO_FIELD=%s"), *TypeName, *ContentTypeId,
		       *FString::Join(PathToProp, TEXT(".")));
	}
	TreePath.Pop();
}

void ChaseContentLinkProperty(void* RootObj, TArray<const FProperty*> PathToLink, TArray<FBeamContentId>& OutLinksToFetch)
{
	if (!PathToLink.Num()) return;

	// Build the path to the content link from the recursive property root.	
	TArray<FString> PathStr;
	FBeamContentLink FoundLink;

	const auto CurrProp = PathToLink[0];

	if (CastField<FClassProperty>(CurrProp))
	{
		// We do nothing when we bump into UClass fields here.
		return;
	}

	if (const auto StructProp = CastField<FStructProperty>(CurrProp))
	{
		if (StructProp->Struct->IsChildOf(FBeamContentLink::StaticStruct()))
		{
			StructProp->GetValue_InContainer(RootObj, &FoundLink);
			OutLinksToFetch.AddUnique(FBeamContentId{FoundLink.AsString});

			UE_LOG(LogBeamContent, Warning, TEXT("Found Content Link with Id. CONTENT_LINK_ID=%s"), *FoundLink.AsString);
			return;
		}

		int32 Size = StructProp->Struct->GetPropertiesSize();
		int32 Alignment = StructProp->Struct->GetMinAlignment();

		uint8* StructCopy = (uint8*)FMemory::Malloc(Size, Alignment);
		FMemory::Memzero(StructCopy, Size);

		if (!StructProp->HasAnyPropertyFlags(CPF_ZeroConstructor))
			StructProp->InitializeValue_InContainer(StructCopy);

		StructProp->GetValue_InContainer(RootObj, StructCopy);

		PathToLink.RemoveAt(0);
		ChaseContentLinkProperty(StructCopy, PathToLink, OutLinksToFetch);
		FMemory::Free(StructCopy);
		return;
	}

	if (const auto ObjProp = CastField<FObjectProperty>(CurrProp))
	{
		if (const auto Obj = ObjProp->GetObjectPropertyValue_InContainer(RootObj))
		{
			PathToLink.RemoveAt(0);
			ChaseContentLinkProperty(Obj, PathToLink, OutLinksToFetch);
		}
		return;
	}

	if (const auto ArrayProperty = CastField<FArrayProperty>(CurrProp))
	{
		const FScriptArray* Val = ArrayProperty->GetPropertyValuePtr(ArrayProperty->ContainerPtrToValuePtr<void>(RootObj));
		FScriptArrayHelper ArrayHelper(ArrayProperty, Val);

		if (CastField<FClassProperty>(ArrayProperty->Inner))
		{
			// We do nothing when we bump into UClass fields here.
			return;
		}

		if (const auto ArrayStructProp = CastField<FStructProperty>(ArrayProperty->Inner))
		{
			if (ArrayStructProp->Struct->IsChildOf(FBeamContentLink::StaticStruct()))
			{
				for (int i = 0; i < ArrayHelper.Num(); ++i)
				{
					const FBeamContentLink* Data = reinterpret_cast<const FBeamContentLink*>(ArrayHelper.GetRawPtr(i));
					const FString* UnderlyingString = static_cast<const FString*>(Data->GetAddr(0));
					OutLinksToFetch.AddUnique(FBeamContentId{*UnderlyingString});
					UE_LOG(LogBeamContent, Warning, TEXT("Found Content Link with Id inside Array. CONTENT_LINK_ID=%s"), *Data->AsString);
				}
				return;
			}

			PathToLink.RemoveAt(0);
			for (int Index = 0; Index < ArrayHelper.Num(); ++Index)
			{
				const auto StructPtr = ArrayHelper.GetRawPtr(Index);
				ChaseContentLinkProperty(StructPtr, PathToLink, OutLinksToFetch);
			}
		}

		if (CastField<FObjectProperty>(ArrayProperty->Inner))
		{
			PathToLink.RemoveAt(0);
			for (int Index = 0; Index < ArrayHelper.Num(); ++Index)
			{
				if (UObject* InstancedObject = *reinterpret_cast<UObject**>(ArrayHelper.GetRawPtr(Index)))
				{
					ChaseContentLinkProperty(InstancedObject, PathToLink, OutLinksToFetch);
				}
			}
		}
		return;
	}

	if (const auto MapProperty = CastField<FMapProperty>(CurrProp))
	{
		const FScriptMap* Val = MapProperty->GetPropertyValuePtr(MapProperty->ContainerPtrToValuePtr<void>(RootObj));
		FScriptMapHelper MapHelper(MapProperty, Val);

		if (CastField<FClassProperty>(MapProperty->ValueProp))
		{
			// We do nothing when we bump into UClass fields here.
			return;
		}

		if (const auto MapStructProp = CastField<FStructProperty>(MapProperty->ValueProp))
		{
			if (MapStructProp->Struct->IsChildOf(FBeamContentLink::StaticStruct()))
			{
				for (int i = 0; i < MapHelper.Num(); ++i)
				{
					const FBeamContentLink* Data = reinterpret_cast<const FBeamContentLink*>(MapHelper.GetValuePtr(i));
					const FString* UnderlyingString = static_cast<const FString*>(Data->GetAddr(0));
					OutLinksToFetch.AddUnique(FBeamContentId{*UnderlyingString});
					UE_LOG(LogBeamContent, Warning, TEXT("Found Content Link with Id inside Map. CONTENT_LINK_ID=%s"), *Data->AsString);
				}
				return;
			}

			PathToLink.RemoveAt(0);
			for (int Index = 0; Index < MapHelper.Num(); ++Index)
			{
				const auto StructPtr = MapHelper.GetValuePtr(Index);
				ChaseContentLinkProperty(StructPtr, PathToLink, OutLinksToFetch);
			}
		}

		if (CastField<FObjectProperty>(MapProperty->ValueProp))
		{
			PathToLink.RemoveAt(0);
			for (int Index = 0; Index < MapHelper.Num(); ++Index)
			{
				if (UObject* InstancedObject = *reinterpret_cast<UObject**>(MapHelper.GetValuePtr(Index)))
				{
					ChaseContentLinkProperty(InstancedObject, PathToLink, OutLinksToFetch);
				}
			}
		}
	}
}

void ChaseRecursiveRoots(UClass* RecursiveType, const TArray<TArray<const FProperty*>>& PathsToRecursiveSelvesFromRecursiveRoot, TArray<const FProperty*> CurrentPathToSelfFromRoot, void* RootObj,
                         TArray<UObject*>& OutRecursiveRoots)
{
	if (!CurrentPathToSelfFromRoot.Num()) return;

	// Build the path to the content link from the recursive property root.	
	TArray<FString> PathStr;
	FBeamContentLink FoundLink;

	const auto CurrProp = CurrentPathToSelfFromRoot[0];


	if (CastField<FClassProperty>(CurrProp))
	{
		// We do nothing when we bump into UClass fields here.
		return;
	}

	if (const auto StructProp = CastField<FStructProperty>(CurrProp))
	{
		int32 Size = StructProp->Struct->GetPropertiesSize();
		int32 Alignment = StructProp->Struct->GetMinAlignment();

		uint8* StructCopy = (uint8*)FMemory::Malloc(Size, Alignment);
		FMemory::Memzero(StructCopy, Size);

		if (!StructProp->HasAnyPropertyFlags(CPF_ZeroConstructor))
			StructProp->InitializeValue_InContainer(StructCopy);

		StructProp->GetValue_InContainer(RootObj, StructCopy);

		CurrentPathToSelfFromRoot.RemoveAt(0);
		ChaseRecursiveRoots(RecursiveType, PathsToRecursiveSelvesFromRecursiveRoot, CurrentPathToSelfFromRoot, StructCopy, OutRecursiveRoots);
		FMemory::Free(StructCopy);
		return;
	}

	if (const auto ObjProp = CastField<FObjectProperty>(CurrProp))
	{
		if (const auto InstancedObject = ObjProp->GetObjectPropertyValue_InContainer(RootObj))
		{
			if (RecursiveType == ObjProp->PropertyClass)
			{
				OutRecursiveRoots.Add(InstancedObject);
				for (const auto& ToRecursiveSelvesFromRecursiveRoot : PathsToRecursiveSelvesFromRecursiveRoot)
				{
					ChaseRecursiveRoots(RecursiveType, PathsToRecursiveSelvesFromRecursiveRoot, ToRecursiveSelvesFromRecursiveRoot, InstancedObject, OutRecursiveRoots);
				}
			}
			else
			{
				CurrentPathToSelfFromRoot.RemoveAt(0);
				ChaseRecursiveRoots(RecursiveType, PathsToRecursiveSelvesFromRecursiveRoot, CurrentPathToSelfFromRoot, InstancedObject, OutRecursiveRoots);
			}
		}
		return;
	}

	if (const auto ArrayProperty = CastField<FArrayProperty>(CurrProp))
	{
		const FScriptArray* Val = ArrayProperty->GetPropertyValuePtr(ArrayProperty->ContainerPtrToValuePtr<void>(RootObj));
		FScriptArrayHelper ArrayHelper(ArrayProperty, Val);

		if (const auto ArrayStructProp = CastField<FStructProperty>(ArrayProperty->Inner))
		{
			CurrentPathToSelfFromRoot.RemoveAt(0);
			for (int Index = 0; Index < ArrayHelper.Num(); ++Index)
			{
				const auto StructPtr = ArrayHelper.GetRawPtr(Index);
				ChaseRecursiveRoots(RecursiveType, PathsToRecursiveSelvesFromRecursiveRoot, CurrentPathToSelfFromRoot, StructPtr, OutRecursiveRoots);
			}
		}
		else if (CastField<FClassProperty>(ArrayProperty->Inner))
		{
			// We do nothing when we bump into UClass fields here.
			return;
		}
		else if (const auto ArrayObjProp = CastField<FObjectProperty>(ArrayProperty->Inner))
		{
			CurrentPathToSelfFromRoot.RemoveAt(0);
			for (int Index = 0; Index < ArrayHelper.Num(); ++Index)
			{
				if (UObject* InstancedObject = *reinterpret_cast<UObject**>(ArrayHelper.GetRawPtr(Index)))
				{
					if (RecursiveType == ArrayObjProp->PropertyClass)
					{
						OutRecursiveRoots.Add(InstancedObject);
						for (const auto& ToRecursiveSelvesFromRecursiveRoot : PathsToRecursiveSelvesFromRecursiveRoot)
						{
							ChaseRecursiveRoots(RecursiveType, PathsToRecursiveSelvesFromRecursiveRoot, ToRecursiveSelvesFromRecursiveRoot, InstancedObject, OutRecursiveRoots);
						}
					}
					else
					{
						CurrentPathToSelfFromRoot.RemoveAt(0);
						ChaseRecursiveRoots(RecursiveType, PathsToRecursiveSelvesFromRecursiveRoot, CurrentPathToSelfFromRoot, InstancedObject, OutRecursiveRoots);
					}
				}
			}
		}
		return;
	}

	if (const auto MapProperty = CastField<FMapProperty>(CurrProp))
	{
		const FScriptMap* Val = MapProperty->GetPropertyValuePtr(MapProperty->ContainerPtrToValuePtr<void>(RootObj));
		FScriptMapHelper MapHelper(MapProperty, Val);

		if (const auto MapStructProp = CastField<FStructProperty>(MapProperty->ValueProp))
		{
			CurrentPathToSelfFromRoot.RemoveAt(0);
			for (int Index = 0; Index < MapHelper.Num(); ++Index)
			{
				const auto StructPtr = MapHelper.GetValuePtr(Index);
				ChaseRecursiveRoots(RecursiveType, PathsToRecursiveSelvesFromRecursiveRoot, CurrentPathToSelfFromRoot, StructPtr, OutRecursiveRoots);
			}
		}
		else if (CastField<FClassProperty>(MapProperty->ValueProp))
		{
			// We do nothing when we bump into UClass fields here.
			return;
		}
		else if (const auto MapObjProp = CastField<FObjectProperty>(MapProperty->ValueProp))
		{
			CurrentPathToSelfFromRoot.RemoveAt(0);
			for (int Index = 0; Index < MapHelper.Num(); ++Index)
			{
				if (UObject* InstancedObject = *reinterpret_cast<UObject**>(MapHelper.GetValuePtr(Index)))
				{
					if (RecursiveType == MapObjProp->PropertyClass)
					{
						OutRecursiveRoots.Add(InstancedObject);
						for (const auto& ToRecursiveSelvesFromRecursiveRoot : PathsToRecursiveSelvesFromRecursiveRoot)
						{
							ChaseRecursiveRoots(RecursiveType, PathsToRecursiveSelvesFromRecursiveRoot, ToRecursiveSelvesFromRecursiveRoot, InstancedObject, OutRecursiveRoots);
						}
					}
					else
					{
						CurrentPathToSelfFromRoot.RemoveAt(0);
						ChaseRecursiveRoots(RecursiveType, PathsToRecursiveSelvesFromRecursiveRoot, CurrentPathToSelfFromRoot, InstancedObject, OutRecursiveRoots);
					}
				}
			}
		}
		return;
	}
}

void UBeamContentSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ContentApi = GEngine->GetEngineSubsystem<UBeamContentApi>();
}

void UBeamContentSubsystem::InitializeWhenUnrealReady_Implementation(FBeamOperationHandle& ResultOp)
{
	// Grab all existing ContentObject classes so we can correctly deserialize content we fetch from the content API.
	for (TObjectIterator<UClass> It; It; ++It)
	{
		if (It->IsChildOf(UBeamContentObject::StaticClass()) && !It->HasAnyClassFlags(CLASS_Abstract))
		{
			FString TypeName = It->GetFName().ToString();
			FString ContentTypeId = It->GetDefaultObject<UBeamContentObject>()->BuildContentTypeString();

			UClass* ContentTypeClass = *It;

			UE_LOG(LogTemp, Display, TEXT("Initializing Beam Runtime Content System - TYPE=%s, TYPE_ID=%s"), *TypeName, *ContentTypeId);
			AllContentTypes.Add(ContentTypeClass);
			ContentTypeStringToContentClass.Add(ContentTypeId, ContentTypeClass);


			// Map paths to FBeamContentLink recursively descending into all USTRUCT/UOBJECTS
			TArray<const FProperty*> TreePath;
			TArray<TArray<const FProperty*>> FoundPathsToLinks;
			TArray<TArray<const FProperty*>> FoundPathsToRecursiveProps;
			TArray<UClass*> RecursiveTypes;
			for (TFieldIterator<FProperty> PropIt(ContentTypeClass); PropIt; ++PropIt)
			{
				UE_LOG(LogBeamContent, Verbose, TEXT("Starting From Field - TYPE=%s, TYPE_ID=%s, PATH_TO_LINK_FIELD=%s"), *TypeName, *ContentTypeId, *PropIt->GetName());
				DescendLookingForContentLinks(TypeName, ContentTypeId, *PropIt, TreePath, FoundPathsToLinks, FoundPathsToRecursiveProps, RecursiveTypes);
				TreePath.Reset();
				UE_LOG(LogBeamContent, Verbose, TEXT("Done with Field - TYPE=%s, TYPE_ID=%s, PATH_TO_LINK_FIELD=%s"), *TypeName, *ContentTypeId, *PropIt->GetName());
			}

			// Store the path of properties I need to chase to get to the link property.
			for (TArray<const FProperty*> FoundPathsToLink : FoundPathsToLinks)
			{
				TArray<FString> PathToProp;
				for (const FProperty* PathLink : FoundPathsToLink)
					PathToProp.Add(PathLink->GetName());

				UE_LOG(LogBeamContent, Verbose, TEXT("Found Content Link in ContentType - TYPE=%s, TYPE_ID=%s, PATH_TO_LINK_FIELD=%s"), *TypeName, *ContentTypeId,
				       *FString::Join(PathToProp, TEXT(".")));
			}
			PathsToContentLinks.Add(ContentTypeClass, TArray{FoundPathsToLinks});

			// Store any recursive properties of this content type so we can build and match against the "paths from recursive type" to see if we need to descend a recursive structure looking for links
			const auto NumOfRecursiveProps = FoundPathsToRecursiveProps.Num();
			for (int i = 0; i < NumOfRecursiveProps; ++i)
			{
				const auto FoundPathToRecursiveProp = FoundPathsToRecursiveProps[i];
				const auto RecursiveType = RecursiveTypes[i];

				TArray<TArray<const FProperty*>> FoundPathsToLinksFromRecursiveTypes;
				TArray<TArray<const FProperty*>> FoundPathsToRecursiveSelf;
				TArray<UClass*> RecursiveRootTypes;

				// If we have not descended this type at some point already, we need to descend it.
				if (!PathsToContentLinks.Contains(RecursiveType))
				{
					for (TFieldIterator<FProperty> PropIt(RecursiveType); PropIt; ++PropIt)
					{
						DescendLookingForContentLinks(RecursiveType->GetName(), ContentTypeId, *PropIt, TreePath, FoundPathsToLinksFromRecursiveTypes, FoundPathsToRecursiveSelf, RecursiveRootTypes);
						TreePath.Reset();
					}

					// Store the paths to ContentLinks from this recursive property as a root.
					PathsToContentLinks.Add(RecursiveType, FoundPathsToLinksFromRecursiveTypes);

					// Store the paths to all fields of type RecursiveType (TArray<URecursiveType*> and TMap<FString, URecursiveType*>) from the RecursiveType itself 
					PathsToRecursiveSelves.Add(RecursiveType, FoundPathsToRecursiveSelf);
				}

				// If the recursive prop's type has content links inside it, we need to keep track of this so we can correctly gather links when downloading content. 
				if (PathsToContentLinks[RecursiveType].Num() > 0)
				{
					// Build the path to the recursive property
					TArray<FString> PathToRecursiveProp;
					for (const FProperty* PathLink : FoundPathToRecursiveProp) PathToRecursiveProp.Add(PathLink->GetName());
					const auto PathToRecursivePropStr = FString::Join(PathToRecursiveProp, TEXT("."));

					// For each of the paths to content links that we found inside the recursive properties...
					for (TArray<const FProperty*> FoundPathsToLink : FoundPathsToLinksFromRecursiveTypes)
					{
						// Build the path to the content link from the recursive property root.
						TArray<FString> PathToProp;
						for (const FProperty* PathLink : FoundPathsToLink) PathToProp.Add(PathLink->GetName());
						const auto PathToLink = FString::Join(PathToProp, TEXT("."));

						// Log out the found recursive type and the path for its property.
						UE_LOG(LogBeamContent, Verbose,
						       TEXT(
							       "Found Content Link in RecursiveType inside ContentType. - TYPE=%s, TYPE_ID=%s, PATH_TO_RECURSIVE_PROP=%s, RECURSIVE_TYPE=%s, PATH_TO_LINK_FIELD_IN_RECURSIVE_TYPE=%s"
						       ),
						       *TypeName, *ContentTypeId, *PathToRecursivePropStr, *RecursiveType->GetName(), *PathToLink);
					}

					// For each of the paths to content links that we found inside the recursive properties...
					for (TArray<const FProperty*> FoundPathsToLink : FoundPathsToRecursiveSelf)
					{
						// Build the path to the content link from the recursive property root.
						TArray<FString> PathToProp;
						for (const FProperty* PathLink : FoundPathsToLink) PathToProp.Add(PathLink->GetName());
						const auto PathToLink = FString::Join(PathToProp, TEXT("."));

						// Log out the found recursive type and the path for its property.
						UE_LOG(LogBeamContent, Verbose,
						       TEXT(
							       "Found Recursive Prop in RecursiveType inside ContentType. - TYPE=%s, TYPE_ID=%s, PATH_TO_RECURSIVE_PROP=%s, RECURSIVE_TYPE=%s, PATH_TO_LINK_FIELD_IN_RECURSIVE_TYPE=%s"
						       ),
						       *TypeName, *ContentTypeId, *PathToRecursivePropStr, *RecursiveType->GetName(), *PathToLink);
					}

					// Store the path to this recursive property
					if (PathsToRecursiveProperties.Contains(ContentTypeClass)) PathsToRecursiveProperties[ContentTypeClass].Add(FoundPathToRecursiveProp);
					else PathsToRecursiveProperties.Add(ContentTypeClass, TArray<TArray<const FProperty*>>{FoundPathToRecursiveProp});

					// Store the type of this recursive property
					if (RecursivePropertyTypes.Contains(ContentTypeClass)) RecursivePropertyTypes[ContentTypeClass].Add(RecursiveType);
					else RecursivePropertyTypes.Add(ContentTypeClass, TArray{RecursiveType});
				}
			}
		}
	}

	// Go through list of baked content manifests and load up the baked BeamRuntimeContentCache the baked		
	auto CoreSettings = GetMutableDefault<UBeamCoreSettings>();
	auto RuntimeSettings = GetMutableDefault<UBeamRuntimeSettings>();
	TArray<FSoftObjectPath> BakedContentPaths;
	for (const auto& BeamRuntimeContentCache : CoreSettings->BakedContentManifests)
		BakedContentPaths.Add(BeamRuntimeContentCache.ToSoftObjectPath());

	FBeamOperationHandle Op = GEngine->GetEngineSubsystem<UBeamRequestTracker>()->CPP_BeginOperation({}, GetName(), {});
	const auto Handle = RuntimeSettings->ContentStreamingManager.RequestAsyncLoad(BakedContentPaths, FStreamableDelegate::CreateLambda([this, Op, BakedContentPaths, RuntimeSettings, CoreSettings]()
	{
		for (int i = 0; i < CoreSettings->BakedContentManifests.Num(); ++i)
		{
			const auto LoadedObject = CoreSettings->BakedContentManifests[i];
			checkf(LoadedObject, TEXT("Failed to find the content manifest at path %s. Cook content again so that we can correctly set up the baked content objects."),
			       *BakedContentPaths[i].ToString())

			const auto BakedContentManifest = LoadedObject.Get();
			const auto ManifestId = BakedContentManifest->ManifestId;
			BakedContent.Add(ManifestId, BakedContentManifest);
		}

		GEngine->GetEngineSubsystem<UBeamRequestTracker>()->TriggerOperationSuccess(Op, {});
	}));

	// If we don't have any baked content, this Operation is a no-op.
	if (BakedContentPaths.Num() == 0)
		GEngine->GetEngineSubsystem<UBeamRequestTracker>()->TriggerOperationSuccess(Op, {});

	ResultOp = Op;
}

void UBeamContentSubsystem::OnBeamableStarting_Implementation(FBeamOperationHandle& ResultOp)
{
	FBeamOperationEventHandlerCode OpHandler;
	OpHandler.BindLambda([](FBeamOperationEvent OpEvent)
	{
		if (OpEvent.EventType == OET_ERROR)
		{
			// TODO: How should we handle when S3 explodes for some reason?
		}
	});
	FBeamOperationHandle Op = GEngine->GetEngineSubsystem<UBeamRequestTracker>()->CPP_BeginOperation({}, GetName(), OpHandler);

	const auto ManifestId = FBeamContentManifestId{TEXT("global")};
	const auto bShouldDownloadIndividuals = GetDefault<UBeamRuntimeSettings>()->bDownloadIndividualContentOnStart;
	FetchContentManifest(ManifestId, bShouldDownloadIndividuals, Op);
	ResultOp = Op;
}

void UBeamContentSubsystem::OnUserSignedIn_Implementation(const FUserSlot& UserSlot, const FBeamRealmUser& BeamRealmUser, const bool bIsOwnerUserAuth, FBeamOperationHandle& ResultOp)
{
	// The result Op is a completed Op as we don't have anything else to do async if we are not fetching content.
	Super::OnUserSignedIn_Implementation(UserSlot, BeamRealmUser, bIsOwnerUserAuth, ResultOp);

	// We also set up the content refresh notification here whenever the owner user signs in (we need to set this up again as websocket connections are established per-UserSlot).
	const auto NotificationHandler = FOnContentRefreshNotificationCode::CreateLambda([this](const FContentRefreshNotificationMessage& ContentRefreshNotificationMessage)
	{
		// Our legacy solution here is that we delay grabbing the content so as to not make every single logged in client bombard the content service with
		// requests at the same time. We delay by a random amount in seconds as defined by the refresh message.
		const int32 DelayCount = FMath::RandRange(0, ContentRefreshNotificationMessage.Delay);

		// Configure an operation to run refresh the given content manifest some time in the future.
		FTimerHandle H;
		GetWorld()->GetTimerManager().SetTimer(H, FTimerDelegate().CreateLambda([this, ContentRefreshNotificationMessage]
		{
			const auto DelayedFetchAllOpHandler = FBeamOperationEventHandlerCode::CreateLambda([](FBeamOperationEvent OpEvent)
			{
				if (OpEvent.EventType == OET_ERROR)
				{
					// TODO: How should we handle when S3 explodes for some reason?
				}
			});

			// TODO: Only fetch the updated content items (scopes)
			const FBeamOperationHandle DelayedFetchAllOp = GEngine->GetEngineSubsystem<UBeamRequestTracker>()->CPP_BeginOperation({}, GetName(), DelayedFetchAllOpHandler);
			FetchContentManifest(ContentRefreshNotificationMessage.Manifest.Id, true, DelayedFetchAllOp);
			UE_LOG(LogBeamContent, Warning, TEXT("Delay for ContentRefresh is over. Fetching the updated content manifest."));
		}), DelayCount, false, DelayCount);

		UE_LOG(LogBeamContent, Warning, TEXT("Received ContentRefresh notification. Fetching content in %d seconds."), DelayCount);
	});
	GEngine->GetEngineSubsystem<UBeamContentNotifications>()->CPP_SubscribeToContentRefresh(UserSlot, Runtime->DefaultNotificationChannel, NotificationHandler, this);
}

void UBeamContentSubsystem::PrepareContentDownloadRequest(FBeamContentManifestId ManifestId, FBeamRemoteContentManifestEntry ContentEntry, FDownloadContentState& Item)
{
	FBeamContentId Id = ContentEntry.ContentId;
	FString ContentUri = ContentEntry.Uri;
	TArray<FString> Tags = ContentEntry.Tags;
	FOptionalString Checksum = FOptionalString{ContentEntry.Version};

	TUnrealRequestPtr ptr = FHttpModule::Get().CreateRequest();
	ptr->SetVerb("GET");
	ptr->SetURL(ContentUri);
	ptr->SetHeader(UBeamBackend::HEADER_ACCEPT, UBeamBackend::HEADER_VALUE_ACCEPT_CONTENT_TYPE);
	Item = {ManifestId, Id, Tags, Checksum, ptr};
}

void UBeamContentSubsystem::DownloadLiveContentObjectsData(const FBeamContentManifestId Id, const TArray<FBeamRemoteContentManifestEntry> Rows, const TMap<FBeamContentId, FString> Checksums,
                                                           FSimpleDelegate OnSuccess, FSimpleDelegate OnError)
{
	// We keep track of each content we are downloading (the bool indicates whether or not we managed to write the file
	// locally and add it to the local manifest. 
	TArray<FDownloadContentState> DownloadContentOperations;
	if (Rows.Num() == 0)
	{
		OnSuccess.ExecuteIfBound();
		return;
	}

	for (const auto ContentEntry : Rows)
	{
		if (ContentEntry.Type == EContentType::BEAM_content)
		{
			// We only download changed content from the given manifest
			const auto Checksum = Checksums.Find({ContentEntry.ContentId});
			const auto bNotDownloaded = !Checksum;
			const auto bOlderVersionCached = Checksum && !ContentEntry.Version.Equals(*Checksum);
			if (bNotDownloaded || bOlderVersionCached)
			{
				FDownloadContentState Item;
				PrepareContentDownloadRequest(Id, ContentEntry, Item);
				DownloadContentOperations.Add(Item);

				if (bNotDownloaded) UE_LOG(LogBeamContent, Verbose, TEXT("Content Id %s not in memory. Preparing to fetch its JSON blob."), *Item.Id.AsString);
				if (bOlderVersionCached) UE_LOG(LogBeamContent, Verbose, TEXT("Detected Changes in Content Id %s. Preparing to fetch its JSON blob."), *Item.Id.AsString);
			}
		}
	}

	// For each download that we'll make, register a lambda that:
	//  - Tries to save the downloaded file to the local '.beamable' folder.
	//  - Checks to see if it was the last download and, if so, invoke the appropriate on success/error callback.		
	for (int DownloadIdx = 0; DownloadIdx < DownloadContentOperations.Num(); ++DownloadIdx)
	{
		const auto& DownloadContentOperation = DownloadContentOperations[DownloadIdx];
		DownloadContentOperation.Request->OnProcessRequestComplete().BindLambda([this, DownloadContentOperations, DownloadContentOperation, Id, OnSuccess, OnError]
		(TSharedPtr<IHttpRequest>, TSharedPtr<IHttpResponse> HttpResponse, bool)
			{
#if WITH_EDITOR
				if (GEditor && !GEditor->IsPlayingSessionInEditor())
					return;
#endif
				if (HttpResponse->GetResponseCode() == 200)
				{
					auto Body = FString();
					Body = Body + HttpResponse->GetContentAsString();
					UpdateDownloadedContent(Body, DownloadContentOperation);
				}

				bool bAreAllFinished = true;
				bool bAreAllSuccess = true;
				bool bAreAnyFailed = false;

				TArray<FBeamContentId> FailedDownloads;
				for (const auto& Download : DownloadContentOperations)
				{
					const auto bIsSuccess = Download.Request->GetStatus() == EHttpRequestStatus::Succeeded;
					const auto bIsFailure = Download.Request->GetStatus() == EHttpRequestStatus::Failed;

					bAreAllFinished &= bIsSuccess || bIsFailure;
					bAreAllSuccess &= bIsSuccess;
					bAreAnyFailed |= bIsFailure;
					FailedDownloads.Add(FBeamContentId(Download.Id));
				}

				if (bAreAllFinished)
				{
					if (bAreAllSuccess)
					{
						OnSuccess.ExecuteIfBound();
					}

					if (bAreAnyFailed)
					{
						OnError.ExecuteIfBound();
					}
				}
			});
		DownloadContentOperation.Request->ProcessRequest();
	}
}


void UBeamContentSubsystem::UpdateDownloadedContent(FString UriResponse, FDownloadContentState DownloadState)
{
	// We create the object from the downloaded JSON and store it in the created cache.
	const auto ContentId = FBeamContentId(DownloadState.Id);
	const auto ContentTypeId = ContentId.GetTypeId();
	const auto LiveContentCache = LiveContent.FindChecked(DownloadState.ManifestId);

	// Otherwise, find the UClass for the content type. Load the JSON and deserialize it into the UBeamContentObject.
	const auto Type = ContentTypeStringToContentClass.Find(ContentTypeId);
	checkf(Type, TEXT("ContentTypeId for entry did not match any of the existing classes. ManifestId=%s, ContentId=%s"), *DownloadState.ManifestId.AsString, *ContentId.AsString)

	// TODO: Remove this when epic fixes their nonsense...	
	auto TestUriResponse = UriResponse;
	TestUriResponse.ReplaceInline(TEXT("\":true"), TEXT("\":True"));
	TestUriResponse.ReplaceInline(TEXT("\":false"), TEXT("\":False"));
	TestUriResponse.ReplaceInline(TEXT("\":null"), TEXT("\":Null"));

	const auto ContentObject = NewObject<UBeamContentObject>(GetTransientPackage(), *Type);
	UE_LOG(LogBeamContent, Verbose, TEXT("Downloaded content and preparing to parse its Json. CONTENT_ID=%s, JSON=%s"), *ContentId.AsString, *TestUriResponse)
	ContentObject->FromBasicJson(TestUriResponse);
	ContentObject->Tags = DownloadState.Tags;

	checkf(ContentObject, TEXT("ContentObject was not created successfully. ManifestId=%s, ContentId=%s"), *DownloadState.ManifestId.AsString, *ContentId.AsString)

	const auto PropertyHash = ContentObject->CreatePropertiesHash();
	LiveContentCache->Cache.Add(ContentId, ContentObject);
	LiveContentCache->Hashes.Add(ContentId, PropertyHash);

	UE_LOG(LogBeamContent, Verbose, TEXT("Downloaded and parsed content. CONTENT_ID=%s, HASH=%s, CONTENT_MANIFEST_ID=%s"), *ContentId.AsString, *LiveContentCache->Hashes.FindChecked(ContentId),
	       *DownloadState.ManifestId.AsString)
}


bool UBeamContentSubsystem::TryGetContent(FBeamContentId ContentId, UBeamContentObject*& OutContent)
{
	return TryGetContentFromManifest(FBeamContentManifestId{"global"}, ContentId, OutContent);
}

bool UBeamContentSubsystem::TryGetContentFromManifest(FBeamContentManifestId ManifestId, FBeamContentId ContentId, UBeamContentObject*& OutContent)
{
	if (LiveContent.Contains(ManifestId))
	{
		const auto LiveManifest = LiveContent.FindRef(ManifestId);
		if (LiveManifest->Cache.Contains(ContentId))
		{
			OutContent = LiveManifest->Cache.FindRef(ContentId);
			return true;
		}

		const auto CookedManifest = BakedContent.FindRef(ManifestId);
		if (!CookedManifest)
		{
			UE_LOG(LogBeamContent, Warning, TEXT("No content with Id=%s was downloaded yet. Since the Manifest with Id=%s wasn't Baked, we can't provide this content."), *ContentId.AsString,
			       *ManifestId.AsString)
			return false;
		}

		if (CookedManifest->Cache.Contains(ContentId))
		{
			OutContent = CookedManifest->Cache.FindRef(ContentId);
			return true;
		}

		return false;
	}

	const auto CookedManifest = BakedContent.FindRef(ManifestId);
	if (!CookedManifest)
	{
		UE_LOG(LogBeamContent, Warning, TEXT("No content with Id=%s was downloaded yet. Since the Manifest with Id=%s wasn't Baked, we can't provide this content."), *ContentId.AsString,
		       *ManifestId.AsString)
		return false;
	}

	if (CookedManifest->Cache.Contains(ContentId))
	{
		OutContent = CookedManifest->Cache.FindRef(ContentId);
		return true;
	}

	return false;
}

bool UBeamContentSubsystem::IsLoadedContent(FBeamContentId ContentId)
{
	return IsLoadedContentFromManifest(FBeamContentManifestId{"global"}, ContentId);
}

bool UBeamContentSubsystem::IsLoadedContentFromManifest(FBeamContentManifestId ManifestId, FBeamContentId ContentId)
{
	if (LiveContent.Contains(ManifestId))
	{
		const auto LiveManifest = LiveContent.FindRef(ManifestId);
		if (LiveManifest->Cache.Contains(ContentId)) return true;

		const auto CookedManifest = BakedContent.FindRef(ManifestId);
		if (!CookedManifest) return false;
		if (CookedManifest->Cache.Contains(ContentId)) return true;

		return false;
	}

	const auto CookedManifest = BakedContent.FindRef(ManifestId);
	if (!CookedManifest) return false;
	if (CookedManifest->Cache.Contains(ContentId)) return true;

	return false;
}

bool UBeamContentSubsystem::TryGetBakedContent(FBeamContentId ContentId, UBeamContentObject*& OutContent)
{
	return TryGetBakedContentFromManifest(FBeamContentManifestId{"global"}, ContentId, OutContent);
}

bool UBeamContentSubsystem::TryGetBakedContentFromManifest(FBeamContentManifestId ManifestId, FBeamContentId ContentId, UBeamContentObject*& OutContent)
{
	checkf(BakedContent.Contains(ManifestId), TEXT("Manifest must exist in at least the baked content"))
	const auto CookedManifest = BakedContent.FindRef(ManifestId);
	if (CookedManifest->Cache.Contains(ContentId))
	{
		OutContent = CookedManifest->Cache.FindRef(ContentId);
		return true;
	}
	return false;
}

int UBeamContentSubsystem::GetIdsOfContentType(TSubclassOf<UBeamContentObject> Type, TArray<FBeamContentId>& Ids, bool bGetInherited)
{
	// TODO: We either need to cache the results (and invalidate when content updates) OR we need to change our RuntimeCache data structure into a search tree. 
	Ids.Reset();
	Ids.Reserve(256);
	for (const auto& Content : LiveContent)
	{
		for (const auto& Cache : Content.Value->Cache)
		{
			const auto Class = Cache.Value->GetClass();
			const auto bIsType = !bGetInherited && Class == Type.Get();
			const auto bInheritsFrom = bGetInherited && Class->IsChildOf(Type);

			if (bIsType || bInheritsFrom)Ids.AddUnique(Cache.Key);
		}
	}

	for (const auto& Content : BakedContent)
	{
		for (const auto& Cache : Content.Value->Cache)
		{
			const auto Class = Cache.Value->GetClass();
			const auto bIsType = !bGetInherited && Class == Type.Get();
			const auto bInheritsFrom = bGetInherited && Class->IsChildOf(Type);

			if (bIsType || bInheritsFrom)Ids.AddUnique(Cache.Key);
		}
	}
	return Ids.Num();
}

FBeamOperationHandle UBeamContentSubsystem::FetchContentManifestOperation(FBeamContentManifestId ManifestId, bool bDownloadIndividualContent, FBeamOperationEventHandler OnOperationEvent)
{
	const auto Handle = Runtime->RequestTrackerSystem->BeginOperation({}, GetClass()->GetFName().ToString(), OnOperationEvent);
	FetchContentManifest(ManifestId, bDownloadIndividualContent, Handle);
	return Handle;
}

FBeamOperationHandle UBeamContentSubsystem::CPP_FetchContentManifestOperation(FBeamContentManifestId ManifestId, bool bDownloadIndividualContent, FBeamOperationEventHandlerCode OnOperationEvent)
{
	const auto Handle = Runtime->RequestTrackerSystem->CPP_BeginOperation({}, GetClass()->GetFName().ToString(), OnOperationEvent);
	FetchContentManifest(ManifestId, bDownloadIndividualContent, Handle);
	return Handle;
}

FBeamOperationHandle UBeamContentSubsystem::FetchIndividualContentBatchOperation(FBeamContentManifestId ManifestId, TArray<FBeamContentId> ContentToDownload,
                                                                                 FBeamOperationEventHandler OnOperationEvent)
{
	const auto Handle = Runtime->RequestTrackerSystem->BeginOperation({}, GetClass()->GetFName().ToString(), OnOperationEvent);
	FetchIndividualContent(ManifestId, ContentToDownload, Handle);
	return Handle;
}

FBeamOperationHandle UBeamContentSubsystem::CPP_FetchIndividualContentBatchOperation(FBeamContentManifestId ManifestId, TArray<FBeamContentId> ContentToDownloadFetch,
                                                                                     FBeamOperationEventHandlerCode OnOperationEvent)
{
	const auto Handle = Runtime->RequestTrackerSystem->CPP_BeginOperation({}, GetClass()->GetFName().ToString(), OnOperationEvent);
	FetchIndividualContent(ManifestId, ContentToDownloadFetch, Handle);
	return Handle;
}

FBeamOperationHandle UBeamContentSubsystem::FetchIndividualContentOperation(FBeamContentManifestId ManifestId, FBeamContentId ContentToDownload, FBeamOperationEventHandler OnOperationEvent)
{
	const auto Handle = Runtime->RequestTrackerSystem->BeginOperation({}, GetClass()->GetFName().ToString(), OnOperationEvent);
	FetchIndividualContent(ManifestId, {ContentToDownload}, Handle);
	return Handle;
}

FBeamOperationHandle UBeamContentSubsystem::CPP_FetchIndividualContentOperation(FBeamContentManifestId ManifestId, FBeamContentId ContentToDownload, FBeamOperationEventHandlerCode OnOperationEvent)
{
	const auto Handle = Runtime->RequestTrackerSystem->CPP_BeginOperation({}, GetClass()->GetFName().ToString(), OnOperationEvent);
	FetchIndividualContent(ManifestId, {ContentToDownload}, Handle);
	return Handle;
}

void UBeamContentSubsystem::FetchContentManifest(FBeamContentManifestId ManifestId, bool bDownloadIndividualContent, FBeamOperationHandle Op)
{
	const auto Request = UGetManifestPublicJsonRequest::Make(FOptionalBeamContentManifestId(ManifestId), GetTransientPackage(), {});
	const auto Handler = FOnGetManifestPublicJsonFullResponse::CreateLambda([this, ManifestId, Op, bDownloadIndividualContent](FGetManifestPublicJsonFullResponse Resp)
	{
		if (Resp.State == RS_Retrying) return;

		if (Resp.State == RS_Success)
		{
			UBeamContentCache* Cache = NewObject<UBeamContentCache>();
			Cache->ManifestId = ManifestId;
			Cache->LatestRemoteManifest = TArray(Resp.SuccessData->Items);

			const auto NumEntries = Cache->LatestRemoteManifest.Num();
			Cache->Cache.Reserve(NumEntries);
			Cache->Hashes.Reserve(NumEntries);

			if (LiveContent.Contains(ManifestId))
			{
				LiveContent[ManifestId]->LatestRemoteManifest = Cache->LatestRemoteManifest;
			}
			else
			{
				LiveContent.Add(ManifestId, Cache);
			}

			if (bDownloadIndividualContent)
			{
				if (LiveContent.Contains(ManifestId))
				{
					const UBeamContentCache* ContentCache = LiveContent.FindChecked(ManifestId);
					DownloadLiveContentObjectsData(ManifestId, ContentCache->LatestRemoteManifest, ContentCache->Hashes, FSimpleDelegate::CreateLambda([Op, this, Cache, ManifestId]
					{
						ContentManifestsUpdated.Broadcast({ManifestId});
						GEngine->GetEngineSubsystem<UBeamRequestTracker>()->TriggerOperationSuccess(Op, {});
					}), FSimpleDelegate::CreateLambda([Op]
					{
						GEngine->GetEngineSubsystem<UBeamRequestTracker>()->TriggerOperationError(Op, {});
					}));
				}
				else
				{
					// TODO: When we go into the Session service implementation and figure out online/offline modes and recovery, we need to revisit this.
					UE_LOG(LogBeamContent, Error, TEXT("Failed to download data on account of missing the live content manifest. This should only be seen when not connected to the internet."));
				}
			}
			else
			{
				ContentManifestsUpdated.Broadcast({ManifestId});
				GEngine->GetEngineSubsystem<UBeamRequestTracker>()->TriggerOperationSuccess(Op, {});
			}
			return;
		}

		if (Resp.State == RS_Error)
		{
			GEngine->GetEngineSubsystem<UBeamRequestTracker>()->TriggerOperationError(Op, {});
		}
	});

	FBeamRequestContext Ctx;
	ContentApi->CPP_GetManifestPublicJson(Request, Handler, Ctx, Op, this);
}

void UBeamContentSubsystem::FetchIndividualContent(FBeamContentManifestId ManifestId, TArray<FBeamContentId> ContentToDownloadFetch, FBeamOperationHandle Op)
{
	ensureAlwaysMsgf(LiveContent.Contains(ManifestId),
	                 TEXT("Content Manifest %s was never fetched. Please ensure that the FetchContentManifest operation is called at least once for all of your manifests."), *ManifestId.AsString);

	const auto Cache = LiveContent.FindRef(ManifestId);

	TArray<FBeamRemoteContentManifestEntry> EntriesToDownload;
	for (auto ToDownloadFetch : ContentToDownloadFetch)
	{
		const auto Row = Cache->LatestRemoteManifest.FindByPredicate([&ToDownloadFetch](const FBeamRemoteContentManifestEntry& Entry) { return Entry.ContentId == ToDownloadFetch; });
		ensureAlwaysMsgf(Row, TEXT("Content Manifest %s does not contain a content with Id %s. Please ensure that this Id is of this manifest."), *ManifestId.AsString, *ToDownloadFetch.AsString);
		if (Row != nullptr)
		{
			// If this row is in the manifest, we'll see if we have it loaded already (or if the loaded version is not the same as the one in the manifest currently loaded.
			if (const FBeamContentId RowId{Row->ContentId}; IsLoadedContent(RowId))
			{
				UBeamContentObject* RowObj;
				if (TryGetContent(RowId, RowObj); RowObj->Version != Row->Version)
				{
					EntriesToDownload.Add(*Row);
				}
			}
			else
			{
				EntriesToDownload.Add(*Row);
			}
		}
	}

	if (EntriesToDownload.Num() > 0)
	{
		DownloadLiveContentObjectsData(ManifestId, EntriesToDownload, Cache->Hashes, FSimpleDelegate::CreateLambda([this, Op, ManifestId, EntriesToDownload]
		{
			TArray<FBeamContentId> LinkIdsToFetch;
			if (!EnforceLinks(ManifestId, EntriesToDownload, LinkIdsToFetch)) Runtime->RequestTrackerSystem->TriggerOperationSuccess(Op, {});
			else FetchIndividualContent(ManifestId, LinkIdsToFetch, Op);
		}), FSimpleDelegate::CreateLambda([this, Op]
		{
			Runtime->RequestTrackerSystem->TriggerOperationError(Op, {});
		}));
	}
	else
	{
		Runtime->RequestTrackerSystem->TriggerOperationSuccess(Op, {});
	}
}

bool UBeamContentSubsystem::EnforceLinks(FBeamContentManifestId ManifestId, TArray<FBeamRemoteContentManifestEntry> ManifestRows, TArray<FBeamContentId>& OutLinksToFetch)
{
	// For each of the downloaded content from the manifest, check if any of them have ContentLinks in them.
	for (const FBeamRemoteContentManifestEntry& ManifestRow : ManifestRows)
	{
		UBeamContentObject* Obj;
		if (TryGetContentOfTypeFromManifest(ManifestId, FBeamContentId{ManifestRow.ContentId}, Obj))
		{
			const auto ObjContentType = Obj->GetClass();

			if (const auto PathsToLinksPtr = PathsToContentLinks.Find(ObjContentType))
			{
				const auto PathsToLinks = *PathsToLinksPtr;

				// If we have no links here, we just log and skip.
				if (!PathsToLinks.Num()) UE_LOG(LogBeamContent, Verbose, TEXT("ContentObject of this type has no Content Links in it for us to pre-fetch. TYPE=%s"), *ObjContentType->GetName());

				// For each link we do have inside this ContentObject types... we extract the content id in it. 
				for (TArray<const FProperty*> PathToLink : PathsToLinks)
				{
					// Build the path to the content link from the recursive property root.
					ChaseContentLinkProperty(Obj, PathToLink, OutLinksToFetch);
				}
			}

			// Handle recursive properties...
			if (const auto PathsToRecursivePropsPtr = PathsToRecursiveProperties.Find(ObjContentType))
			{
				const auto PathsToRecursiveProps = *PathsToRecursivePropsPtr;
				const auto RecursivePropTypes = RecursivePropertyTypes.FindChecked(ObjContentType);

				if (!RecursivePropTypes.Num()) UE_LOG(LogBeamContent, Verbose, TEXT("ContentObject of this type has no Recursive Fields for us to look for Content Links in. TYPE=%s"),
				                                      *ObjContentType->GetName());

				// For each recursive root and its type...
				for (int i = 0; i < RecursivePropTypes.Num(); ++i)
				{
					const auto PathToRecursiveRoot = PathsToRecursiveProps[i];
					UClass* RecursiveRootType = RecursivePropTypes[i];

					const auto PathToRecursiveSelves = PathsToRecursiveSelves.Find(RecursiveRootType);

					// Get all the recursive root objects
					TArray<UObject*> EveryRecursiveRoot;
					ChaseRecursiveRoots(RecursiveRootType, *PathToRecursiveSelves, PathToRecursiveRoot, Obj, EveryRecursiveRoot);

					// For each recursive root object's ContentLink properties, grab its value.
					if (const auto PathsToLinksFromRecursiveRootPtr = PathsToContentLinks.Find(RecursiveRootType))
					{
						for (UObject* RecursiveInstance : EveryRecursiveRoot)
						{
							const auto PathToLinkFromRecursiveRoot = (*PathsToLinksFromRecursiveRootPtr);
							for (TArray<const FProperty*> PathToLinkFromRoot : PathToLinkFromRecursiveRoot)
							{
								ChaseContentLinkProperty(RecursiveInstance, PathToLinkFromRoot, OutLinksToFetch);
							}
						}
					}
				}
			}
		}

		for (FBeamContentId LinksToFetch : OutLinksToFetch)
		{
			UE_LOG(LogBeamContent, Verbose, TEXT("Found Content Link in Downloaded Content. TYPE=%s, LINK=%s"), *Obj->GetClass()->GetName(), *LinksToFetch.AsString);
		}
	}

	return OutLinksToFetch.Num() > 0;
}
