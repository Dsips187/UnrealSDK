
#include "AutoGen/PostManifestResponseLibrary.h"

#include "CoreMinimal.h"


FString UPostManifestResponseLibrary::PostManifestResponseToJsonString(const UPostManifestResponse* Serializable, const bool Pretty)
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

UPostManifestResponse* UPostManifestResponseLibrary::Make(FOptionalManifestChecksum Manifest, UObject* Outer)
{
	auto Serializable = NewObject<UPostManifestResponse>(Outer);
	Serializable->Manifest = Manifest;
	
	return Serializable;
}

void UPostManifestResponseLibrary::Break(const UPostManifestResponse* Serializable, FOptionalManifestChecksum& Manifest)
{
	Manifest = Serializable->Manifest;
		
}
