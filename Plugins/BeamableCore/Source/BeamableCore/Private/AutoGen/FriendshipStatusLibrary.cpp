
#include "AutoGen/FriendshipStatusLibrary.h"

#include "CoreMinimal.h"


FString UFriendshipStatusLibrary::FriendshipStatusToJsonString(const UFriendshipStatus* Serializable, const bool Pretty)
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

UFriendshipStatus* UFriendshipStatusLibrary::Make(bool bIsBlocked, FString FriendId, FString PlayerId, UObject* Outer)
{
	auto Serializable = NewObject<UFriendshipStatus>(Outer);
	Serializable->bIsBlocked = bIsBlocked;
	Serializable->FriendId = FriendId;
	Serializable->PlayerId = PlayerId;
	
	return Serializable;
}

void UFriendshipStatusLibrary::Break(const UFriendshipStatus* Serializable, bool& bIsBlocked, FString& FriendId, FString& PlayerId)
{
	bIsBlocked = Serializable->bIsBlocked;
	FriendId = Serializable->FriendId;
	PlayerId = Serializable->PlayerId;
		
}

