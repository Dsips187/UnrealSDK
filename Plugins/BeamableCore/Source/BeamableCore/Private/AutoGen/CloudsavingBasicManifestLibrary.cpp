
#include "BeamableCore/Public/AutoGen/CloudsavingBasicManifestLibrary.h"

#include "CoreMinimal.h"


FString UCloudsavingBasicManifestLibrary::CloudsavingBasicManifestToJsonString(const UCloudsavingBasicManifest* Serializable, const bool Pretty)
{
	FString Result = FString{};
	if(Pretty)
	{
		TUnrealPrettyJsonSerializer JsonSerializer = TJsonStringWriter<TPrettyJsonPrintPolicy<wchar_t>>::Create(&Result);
		Serializable->BeamSerialize(JsonSerializer);
		JsonSerializer->Close();
	}
	else
	{
		TUnrealJsonSerializer JsonSerializer = TJsonStringWriter<TCondensedJsonPrintPolicy<wchar_t>>::Create(&Result);
		Serializable->BeamSerialize(JsonSerializer);
		JsonSerializer->Close();			
	}
	return Result;
}	

UCloudsavingBasicManifest* UCloudsavingBasicManifestLibrary::Make(bool bReplacement, FString Id, int64 Created, TArray<UReference*> Manifest, UObject* Outer)
{
	auto Serializable = NewObject<UCloudsavingBasicManifest>(Outer);
	Serializable->bReplacement = bReplacement;
	Serializable->Id = Id;
	Serializable->Created = Created;
	Serializable->Manifest = Manifest;
	
	return Serializable;
}

void UCloudsavingBasicManifestLibrary::Break(const UCloudsavingBasicManifest* Serializable, bool& bReplacement, FString& Id, int64& Created, TArray<UReference*>& Manifest)
{
	bReplacement = Serializable->bReplacement;
	Id = Serializable->Id;
	Created = Serializable->Created;
	Manifest = Serializable->Manifest;
		
}

