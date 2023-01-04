
#include "AutoGen/StatsResponseLibrary.h"

#include "CoreMinimal.h"


FString UStatsResponseLibrary::StatsResponseToJsonString(const UStatsResponse* Serializable, const bool Pretty)
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

UStatsResponse* UStatsResponseLibrary::Make(int64 Id, TMap<FString, FString> Stats, UObject* Outer)
{
	auto Serializable = NewObject<UStatsResponse>(Outer);
	Serializable->Id = Id;
	Serializable->Stats = Stats;
	
	return Serializable;
}

void UStatsResponseLibrary::Break(const UStatsResponse* Serializable, int64& Id, TMap<FString, FString>& Stats)
{
	Id = Serializable->Id;
	Stats = Serializable->Stats;
		
}
