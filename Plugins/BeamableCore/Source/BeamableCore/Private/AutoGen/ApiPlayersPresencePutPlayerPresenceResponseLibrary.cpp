
#include "BeamableCore/Public/AutoGen/ApiPlayersPresencePutPlayerPresenceResponseLibrary.h"

#include "CoreMinimal.h"


FString UApiPlayersPresencePutPlayerPresenceResponseLibrary::ApiPlayersPresencePutPlayerPresenceResponseToJsonString(const UApiPlayersPresencePutPlayerPresenceResponse* Serializable, const bool Pretty)
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

UApiPlayersPresencePutPlayerPresenceResponse* UApiPlayersPresencePutPlayerPresenceResponseLibrary::Make(UObject* Outer)
{
	auto Serializable = NewObject<UApiPlayersPresencePutPlayerPresenceResponse>(Outer);
	
	return Serializable;
}



