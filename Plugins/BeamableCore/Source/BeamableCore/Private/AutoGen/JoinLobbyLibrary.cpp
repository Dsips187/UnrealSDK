
#include "BeamableCore/Public/AutoGen/JoinLobbyLibrary.h"

#include "CoreMinimal.h"


FString UJoinLobbyLibrary::JoinLobbyToJsonString(const UJoinLobby* Serializable, const bool Pretty)
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

UJoinLobby* UJoinLobbyLibrary::Make(FOptionalArrayOfBeamTag Tags, UObject* Outer)
{
	auto Serializable = NewObject<UJoinLobby>(Outer);
	Serializable->Tags = Tags;
	
	return Serializable;
}

void UJoinLobbyLibrary::Break(const UJoinLobby* Serializable, FOptionalArrayOfBeamTag& Tags)
{
	Tags = Serializable->Tags;
		
}

