
#include "AutoGen/GetCatalogReqLibrary.h"

#include "CoreMinimal.h"


FString UGetCatalogReqLibrary::GetCatalogReqToJsonString(const UGetCatalogReq* Serializable, const bool Pretty)
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

UGetCatalogReq* UGetCatalogReqLibrary::Make(FOptionalInt64 Version, UObject* Outer)
{
	auto Serializable = NewObject<UGetCatalogReq>(Outer);
	Serializable->Version = Version;
	
	return Serializable;
}

void UGetCatalogReqLibrary::Break(const UGetCatalogReq* Serializable, FOptionalInt64& Version)
{
	Version = Serializable->Version;
		
}
