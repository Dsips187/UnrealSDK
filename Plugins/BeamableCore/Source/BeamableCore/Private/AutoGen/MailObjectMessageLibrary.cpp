
#include "BeamableCore/Public/AutoGen/MailObjectMessageLibrary.h"

#include "CoreMinimal.h"


FString UMailObjectMessageLibrary::MailObjectMessageToJsonString(const UMailObjectMessage* Serializable, const bool Pretty)
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

UMailObjectMessage* UMailObjectMessageLibrary::Make(int64 ReceiverGamerTag, FString State, int64 Id, int64 SenderGamerTag, int64 Sent, FString Category, TArray<UAttachment*> Attachments, FOptionalString Body, FOptionalInt32 Expires, FOptionalPlayerReward PlayerRewards, FOptionalString Subject, FOptionalMailRewards Rewards, FOptionalInt64 BodyRef, FOptionalInt64 ClaimedTimeMs, UObject* Outer)
{
	auto Serializable = NewObject<UMailObjectMessage>(Outer);
	Serializable->ReceiverGamerTag = ReceiverGamerTag;
	Serializable->State = State;
	Serializable->Id = Id;
	Serializable->SenderGamerTag = SenderGamerTag;
	Serializable->Sent = Sent;
	Serializable->Category = Category;
	Serializable->Attachments = Attachments;
	Serializable->Body = Body;
	Serializable->Expires = Expires;
	Serializable->PlayerRewards = PlayerRewards;
	Serializable->Subject = Subject;
	Serializable->Rewards = Rewards;
	Serializable->BodyRef = BodyRef;
	Serializable->ClaimedTimeMs = ClaimedTimeMs;
	
	return Serializable;
}

void UMailObjectMessageLibrary::Break(const UMailObjectMessage* Serializable, int64& ReceiverGamerTag, FString& State, int64& Id, int64& SenderGamerTag, int64& Sent, FString& Category, TArray<UAttachment*>& Attachments, FOptionalString& Body, FOptionalInt32& Expires, FOptionalPlayerReward& PlayerRewards, FOptionalString& Subject, FOptionalMailRewards& Rewards, FOptionalInt64& BodyRef, FOptionalInt64& ClaimedTimeMs)
{
	ReceiverGamerTag = Serializable->ReceiverGamerTag;
	State = Serializable->State;
	Id = Serializable->Id;
	SenderGamerTag = Serializable->SenderGamerTag;
	Sent = Serializable->Sent;
	Category = Serializable->Category;
	Attachments = Serializable->Attachments;
	Body = Serializable->Body;
	Expires = Serializable->Expires;
	PlayerRewards = Serializable->PlayerRewards;
	Subject = Serializable->Subject;
	Rewards = Serializable->Rewards;
	BodyRef = Serializable->BodyRef;
	ClaimedTimeMs = Serializable->ClaimedTimeMs;
		
}

