
#include "BeamableCore/Public/AutoGen/ApiPartiesInvitePostPartyResponseLibrary.h"

#include "CoreMinimal.h"


FString UApiPartiesInvitePostPartyResponseLibrary::ApiPartiesInvitePostPartyResponseToJsonString(const UApiPartiesInvitePostPartyResponse* Serializable, const bool Pretty)
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

UApiPartiesInvitePostPartyResponse* UApiPartiesInvitePostPartyResponseLibrary::Make(UObject* Outer)
{
	auto Serializable = NewObject<UApiPartiesInvitePostPartyResponse>(Outer);
	
	return Serializable;
}



