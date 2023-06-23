
#include "BeamableCore/Public/AutoGen/ApiPartiesMembersDeletePartyResponseLibrary.h"

#include "CoreMinimal.h"


FString UApiPartiesMembersDeletePartyResponseLibrary::ApiPartiesMembersDeletePartyResponseToJsonString(const UApiPartiesMembersDeletePartyResponse* Serializable, const bool Pretty)
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

UApiPartiesMembersDeletePartyResponse* UApiPartiesMembersDeletePartyResponseLibrary::Make(UObject* Outer)
{
	auto Serializable = NewObject<UApiPartiesMembersDeletePartyResponse>(Outer);
	
	return Serializable;
}



