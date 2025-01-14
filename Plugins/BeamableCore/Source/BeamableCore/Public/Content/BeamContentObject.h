﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "JsonDomBuilder.h"

#include "BeamContentObject.generated.h"

class UContentDefinition;
struct FLocalContentManifestRow;

/**
 * This is the base class for all Beamable ContentObjects. This different serialization modes for different use cases:
 * - BasicJson: Mostly used for printing out the contents of the object. Only serializes Id, Version and UPROPERTIES.
 * - ContentDefinitionJson: Used in the publish flow and makes use of a specific format required for publishing.
 */
UCLASS(Blueprintable, BlueprintType, Abstract)
class BEAMABLECORE_API UBeamContentObject : public UObject
{
	GENERATED_BODY()

public:
	FString Id;
	FString Version;
	TArray<FString> Tags;

	FDateTime Created;
	FDateTime LastChanged;

	/**
	 * @brief Generates a ContentDefinitionJsonObject. This is used during the publish flow. 
	 */
	virtual void BuildContentDefinitionJsonObject(FJsonDomBuilder::FObject& OutContentDefinition);

	/**
	 * @brief Generates an MD5 Hash of the ContentObject's properties.
	 */
	UFUNCTION(BlueprintCallable, Category="Beam")
	FString CreatePropertiesHash();

	/**
	 * @brief Generates a serialized string (in basic format) for this content object.	 
	 */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Beam")
	void ToBasicJson(FString& Serialized);
	virtual void ToBasicJson_Implementation(FString& Serialized);

	/**
	 * @brief Parses a serialized string (in basic format) for this content object.
	 */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Beam")
	void FromBasicJson(const FString& Json);
	virtual void FromBasicJson_Implementation(const FString& Json);


	void ToPropertiesJson(FString& Serialized);
	void FromPropertiesJson(const FString& Json);

	/**
	 * @brief Builds the basic content object serialized object. 
	 */
	virtual void BuildBasicJsonObject(FJsonDomBuilder::FObject& Output);

	/**
	 * @brief Parses the basic content object serialized object.
	 */
	virtual void ParseBasicJsonObject(const TSharedPtr<FJsonObject>& Object);

	/**
	 * @brief Serializes the UPROPERTIES of this content object.
	 */
	virtual void BuildPropertiesJsonObject(FJsonDomBuilder::FObject& Properties);

	/**
	 * @brief Deserializes the UPROPERTIES of this content object.
	 */
	virtual void ParsePropertiesJsonObject(const TSharedPtr<FJsonObject>& JsonProperties);

	/**
	 * @brief Walks up the ContentObject class hierarchy and creates a '.'-separated string from the top-most type to the current one.
	 * This is leveraged by the Beamable backend for various things (for legacy reasons). 
	 */
	UFUNCTION(BlueprintCallable, Category="Beam")
	FString BuildContentTypeString();

public:
	/**
	 * UTILITIES FOR PARSING/SERIALIZING JSON PROPERTIES VIA REFLECTION. 
	 */


	/**
	 * @brief Serializes a TArray into a FJsonDomBuilder::FArray.
	 * @param PropName The property's name.
	 * @param JsonArray The Json Array for us to fill.
	 * @param ArrayProperty The FArrayProperty for the TArray field we want to access.
	 * @param ArrayOwner Ptr to the struct/object that owns the TArray UProperty.
	 */
	void SerializeArrayProperty(FString PropName, FJsonDomBuilder::FArray& JsonArray, const FArrayProperty* const ArrayProperty, const void* ArrayOwner);

	/**
	 * @brief Deserializes a TArray from a FJsonDomBuilder::FArray.
	 * @param PropName The property's name.
	 * @param JsonArray The Json Array for us to parse.
	 * @param ArrayProperty The FArrayProperty for the TArray field we want to write to.
	 * @param ArrayOwner Ptr to the struct/object that owns the TArray UProperty.
	 */
	void ParseArrayProperty(const FString& PropName, const TArray<TSharedPtr<FJsonValue>>& JsonArray, const FArrayProperty* ArrayProperty, const void* ArrayOwner);

	/**
	 * @brief Serializes a TMap<FString,> into a FJsonDomBuilder::FObject.
	 * @param PropName The property's name.
	 * @param JsonMap The Json Map for us to fill.
	 * @param MapProperty The FMapProperty for the TMap<FString,> field we want to access.
	 * @param MapOwner Ptr to the struct/object that owns the TMap<FString,> UProperty.
	 */
	void SerializeMapProperty(FString PropName, FJsonDomBuilder::FObject& JsonMap, const FMapProperty* const MapProperty, const void* MapOwner);

	/**
	 * @brief Deserializes a TMap<FString,> from a FJsonDomBuilder::FObject.
	 * @param PropName The property's name.
	 * @param JsonMap The Json Map for us to parse.
	 * @param MapProperty The FMapProperty for the TMap<FString,> field we want to access.
	 * @param MapOwner Ptr to the struct/object that owns the TMap<FString,> UProperty.
	 */
	void ParseMapProperty(const FString& PropName, const TSharedPtr<FJsonObject>& JsonMap, const FMapProperty* MapProperty, void* MapOwner);

	template <typename TInner>
	static void BuildArray(FJsonDomBuilder::FArray& ArrayToFill, const FArrayProperty* const ArrayProperty, const void* ArrayOwner)
	{
		const FScriptArray* Val = ArrayProperty->GetPropertyValuePtr(ArrayProperty->ContainerPtrToValuePtr<void>(ArrayOwner));

		const auto ArrayNum = Val->Num();
		for (auto i = 0; i < ArrayNum; i++)
		{
			const TInner* Data = static_cast<const TInner*>(Val->GetData());
			ArrayToFill.Add(*(Data + i));
		}
	}

	template <typename TInner>
	static void BuildMap(FStrProperty* const StrKeyProperty, FJsonDomBuilder::FObject JsonMap, FScriptMapHelper MapHelper)
	{
		const auto MapNum = MapHelper.Num();
		for (auto i = 0; i < MapNum; i++)
		{
			if (MapHelper.IsValidIndex(i))
			{
				const FString Key = StrKeyProperty->GetPropertyValue(MapHelper.GetKeyPtr(i));
				const TInner* Data = reinterpret_cast<const TInner*>(MapHelper.GetValuePtr(i));

				JsonMap.Set(Key, *Data);
			}
		}
	}
};



#define DEFINE_CONTENT_TYPE_NAME(ClassName, TypeName) \
inline void ClassName::GetContentType_##ClassName(FString& Result){ Result = TEXT(TypeName); }