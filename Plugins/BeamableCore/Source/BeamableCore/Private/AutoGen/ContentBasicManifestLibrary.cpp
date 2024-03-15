
#include "BeamableCore/Public/AutoGen/ContentBasicManifestLibrary.h"

#include "CoreMinimal.h"


FString UContentBasicManifestLibrary::ContentBasicManifestToJsonString(const UContentBasicManifest* Serializable, const bool Pretty)
{
	FString Result = FString{};
	if(Pretty)
	{
		TUnrealPrettyJsonSerializer JsonSerializer = TJsonStringWriter<TPrettyJsonPrintPolicy<TCHAR>>::Create(&Result);
		Serializable->BeamSerialize(JsonSerializer);
		JsonSerializer->Close();
	}
	else
	{
		TUnrealJsonSerializer JsonSerializer = TJsonStringWriter<TCondensedJsonPrintPolicy<TCHAR>>::Create(&Result);
		Serializable->BeamSerialize(JsonSerializer);
		JsonSerializer->Close();			
	}
	return Result;
}	

UContentBasicManifest* UContentBasicManifestLibrary::Make(FBeamContentManifestId Id, FString Checksum, int64 Created, TArray<UBaseContentReference*> References, FOptionalBool bArchived, UObject* Outer)
{
	auto Serializable = NewObject<UContentBasicManifest>(Outer);
	Serializable->Id = Id;
	Serializable->Checksum = Checksum;
	Serializable->Created = Created;
	Serializable->References = References;
	Serializable->bArchived = bArchived;
	
	return Serializable;
}

void UContentBasicManifestLibrary::Break(const UContentBasicManifest* Serializable, FBeamContentManifestId& Id, FString& Checksum, int64& Created, TArray<UBaseContentReference*>& References, FOptionalBool& bArchived)
{
	Id = Serializable->Id;
	Checksum = Serializable->Checksum;
	Created = Serializable->Created;
	References = Serializable->References;
	bArchived = Serializable->bArchived;
		
}

