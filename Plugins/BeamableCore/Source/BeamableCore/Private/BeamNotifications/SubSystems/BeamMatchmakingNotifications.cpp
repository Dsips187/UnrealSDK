﻿#include "BeamNotifications/SubSystems/BeamMatchmakingNotifications.h"

#include "BeamLogging.h"
#include "BeamBackend/SemanticTypes/BeamContentId.h"
#include "BeamNotifications/BeamNotifications.h"
#include "Serialization/BeamJsonUtils.h"

void FMatchmakingUpdateNotificationMessage::BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const
{
	Serializer->WriteValue(TEXT("ticketId"), TicketId);
	Serializer->WriteValue(TEXT("status"), Status);
	Serializer->WriteValue(TEXT("created"), Created);
	Serializer->WriteValue(TEXT("expires"), Expires);
	UBeamJsonUtils::SerializeArray<FString, FString>(TEXT("players"), Players, Serializer);
	Serializer->WriteValue(TEXT("matchType"), MatchType);
	Serializer->WriteValue(TEXT("matchId"), MatchId);
}

void FMatchmakingUpdateNotificationMessage::BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const
{
	Serializer->WriteValue(TEXT("ticketId"), TicketId);
	Serializer->WriteValue(TEXT("status"), Status);
	Serializer->WriteValue(TEXT("created"), Created);
	Serializer->WriteValue(TEXT("expires"), Expires);
	UBeamJsonUtils::SerializeArray<FString, FString>(TEXT("players"), Players, Serializer);
	Serializer->WriteValue(TEXT("matchType"), MatchType);
	Serializer->WriteValue(TEXT("matchId"), MatchId);
}

void FMatchmakingUpdateNotificationMessage::BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag)
{
	TicketId = Bag->GetStringField(TEXT("ticketId"));
	Status   = Bag->GetStringField(TEXT("status"));
	Created  = Bag->GetStringField(TEXT("created"));
	Expires  = Bag->GetStringField(TEXT("expires"));
	UBeamJsonUtils::DeserializeArray<FString, FString>(Bag->GetArrayField(TEXT("players")), Players, OuterOwner);
	MatchType = Bag->GetStringField(TEXT("matchType"));
	MatchId   = Bag->GetStringField(TEXT("matchId"));
}

void FMatchmakingTimeoutNotificationMessage::BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const
{
}

void FMatchmakingTimeoutNotificationMessage::BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const
{
}

void FMatchmakingTimeoutNotificationMessage::BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag)
{
}

void UBeamMatchmakingNotifications::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	Notifications = Collection.InitializeDependency<UBeamNotifications>();
}

void UBeamMatchmakingNotifications::SubscribeToMatchmakingUpdate(const FUserSlot& Slot, const FName& SocketName, FBeamContentId GameType, const FOnMatchmakingUpdateNotification& Handler)
{
	FDelegateHandle Handle;
	const auto      Key = FString::Format(*CTX_KEY_Matchmaking_Update, {GameType.AsString});
	if (!Notifications->TrySubscribeForMessage<FOnMatchmakingUpdateNotification, FMatchmakingUpdateNotificationMessage>(Slot, SocketName, Key, Handler, Handle))
	{
		UE_LOG(LogBeamNotifications, Warning, TEXT("Trying to subscribe to a non-existent socket. SLOT=%s, ID=%s"), *Slot.Name, *SocketName.ToString());
	}
}

FDelegateHandle UBeamMatchmakingNotifications::CPP_SubscribeToMatchmakingUpdate(const FUserSlot& Slot, const FName& SocketName, FBeamContentId GameType, const FOnMatchmakingUpdateNotificationCode& Handler) const
{
	FDelegateHandle Handle;
	const auto      Key = FString::Format(*CTX_KEY_Matchmaking_Update, {GameType.AsString});
	if (!Notifications->TrySubscribeForMessage<FOnMatchmakingUpdateNotificationCode, FMatchmakingUpdateNotificationMessage>(Slot, SocketName, Key, Handler, Handle))
	{
		UE_LOG(LogBeamNotifications, Warning, TEXT("Trying to subscribe to a non-existent socket. SLOT=%s, ID=%s"), *Slot.Name, *SocketName.ToString());
	}
	return Handle;
}

void UBeamMatchmakingNotifications::SubscribeToMatchmakingTimeout(const FUserSlot& Slot, const FName& SocketName, FBeamContentId GameType, const FOnMatchmakingTimeoutNotification& Handler)
{
	FDelegateHandle Handle;
	const auto      Key = FString::Format(*CTX_KEY_Matchmaking_Timeout, {GameType.AsString});
	if (!Notifications->TrySubscribeForMessage<FOnMatchmakingTimeoutNotification, FMatchmakingTimeoutNotificationMessage>(Slot, SocketName, Key, Handler, Handle))
	{
		UE_LOG(LogBeamNotifications, Warning, TEXT("Trying to subscribe to a non-existent socket. SLOT=%s, ID=%s"), *Slot.Name, *SocketName.ToString());
	}
}

FDelegateHandle UBeamMatchmakingNotifications::CPP_SubscribeToMatchmakingTimeout(const FUserSlot& Slot, const FName& SocketName, FBeamContentId GameType, const FOnMatchmakingTimeoutNotificationCode& Handler) const
{
	FDelegateHandle Handle;
	const auto      Key = FString::Format(*CTX_KEY_Matchmaking_Timeout, {GameType.AsString});
	if (!Notifications->TrySubscribeForMessage<FOnMatchmakingTimeoutNotificationCode, FMatchmakingTimeoutNotificationMessage>(Slot, SocketName, Key, Handler, Handle))
	{
		UE_LOG(LogBeamNotifications, Warning, TEXT("Trying to subscribe to a non-existent socket. SLOT=%s, ID=%s"), *Slot.Name, *SocketName.ToString());
	}
	return Handle;
}
