
#include "AutoGen/MultipliersGetResponseLibrary.h"

#include "CoreMinimal.h"


FString UMultipliersGetResponseLibrary::MultipliersGetResponseToJsonString(const UMultipliersGetResponse* Serializable, const bool Pretty)
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

UMultipliersGetResponse* UMultipliersGetResponseLibrary::Make(TArray<UVipBonus*> Multipliers, UObject* Outer)
{
	auto Serializable = NewObject<UMultipliersGetResponse>(Outer);
	Serializable->Multipliers = Multipliers;
	
	return Serializable;
}

void UMultipliersGetResponseLibrary::Break(const UMultipliersGetResponse* Serializable, TArray<UVipBonus*>& Multipliers)
{
	Multipliers = Serializable->Multipliers;
		
}
