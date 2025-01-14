﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Content/BeamContentTypes/BeamGameTypeContent.h"
#include "AutoGen/SubSystems/BeamMatchmakingApi.h"
#include "BeamBackend/SemanticTypes/BeamStatsType.h"
#include "BeamNotifications/SubSystems/BeamMatchmakingNotifications.h"
#include "Runtime/BeamRuntimeSubsystem.h"
#include "Subsystems/Content/BeamContentSubsystem.h"
#include "BeamMatchmakingSubsystem.generated.h"

class UBeamMatchmakingSubsystem;

USTRUCT(BlueprintType)
struct FBeamMatchmakingTicket
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Beam")
	FGuid TicketId = {};

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Beam")
	UBeamGameTypeContent* GameType = nullptr;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Beam")
	TArray<FUserSlot> SlotsInTicket = {};

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Beam")
	TArray<FBeamGamerTag> GamerTagsInTicket = {};

	/**
	 * This will be empty until the OnMatchReady callback is invoked.
	 */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Beam")
	FGuid FoundMatchLobbyId;

	friend bool operator==(const FBeamMatchmakingTicket& Lhs, const FBeamMatchmakingTicket& RHS)
	{
		return Lhs.TicketId == RHS.TicketId;
	}

	friend bool operator==(const FBeamMatchmakingTicket& Lhs, const FGuid& RHS)
	{
		return Lhs.TicketId == RHS;
	}

	friend bool operator!=(const FBeamMatchmakingTicket& Lhs, const FBeamMatchmakingTicket& RHS)
	{
		return !(Lhs == RHS);
	}
};


DECLARE_DELEGATE_OneParam(FOnMatchmakingTicketUpdatedCode, const FBeamMatchmakingTicket&)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMatchmakingTicketUpdated, const FBeamMatchmakingTicket&, Ticket);


USTRUCT(BlueprintType)
struct FBeamMatchmakingState
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Beam")
	FUserSlot OwnerSlot;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Beam")
	FGuid InTicket;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Beam")
	FDateTime LastJoinTime;
};


/**
 * 
 */
UCLASS(BlueprintType)
class BEAMABLECORERUNTIME_API UBeamMatchmakingSubsystem : public UBeamRuntimeSubsystem
{
	GENERATED_BODY()

	UPROPERTY()
	UBeamMatchmakingApi* MatchmakingApi;

	UPROPERTY()
	UBeamMatchmakingNotifications* MatchmakingNotifications;

	UPROPERTY()
	UBeamUserSlots* UserSlots;

	UPROPERTY()
	UBeamRequestTracker* RequestTracker;

	UPROPERTY()
	UBeamContentSubsystem* ContentSubsystem;

public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Beam")
	TArray<FBeamMatchmakingTicket> LiveTickets;

	/*
	 * For easy binding from blueprints. You are responsible for unregistering these as your objects are destroyed or when the ticket is invalidated.
	 */
	UPROPERTY(BlueprintAssignable)
	FOnMatchmakingTicketUpdated                       OnMatchRemoteSearchStarted;
	TMultiMap<FGuid, FOnMatchmakingTicketUpdatedCode> OnMatchRemoteSearchStartedCode;

	/*
	 * For easy binding from blueprints. You are responsible for unregistering these as your objects are destroyed or when the ticket is invalidated.
	 */
	UPROPERTY(BlueprintAssignable)
	FOnMatchmakingTicketUpdated                       OnMatchSearching;
	TMultiMap<FGuid, FOnMatchmakingTicketUpdatedCode> OnMatchSearchingCode;

	/*
	 * For easy binding from blueprints. You are responsible for unregistering these as your objects are destroyed or when the ticket is invalidated.
	 */
	UPROPERTY(BlueprintAssignable)
	FOnMatchmakingTicketUpdated                       OnMatchReady;
	TMultiMap<FGuid, FOnMatchmakingTicketUpdatedCode> OnMatchReadyCode;

	/*
     * For easy binding from blueprints. You are responsible for unregistering these as your objects are destroyed or when the ticket is invalidated.
     */
	UPROPERTY(BlueprintAssignable)
	FOnMatchmakingTicketUpdated                       OnMatchCancelled;
	TMultiMap<FGuid, FOnMatchmakingTicketUpdatedCode> OnMatchCancelledCode;

	/*
	 * For easy binding from blueprints. You are responsible for unregistering these as your objects are destroyed or when the ticket is invalidated.
	 */
	UPROPERTY(BlueprintAssignable)
	FOnMatchmakingTicketUpdated                       OnMatchTimedOut;
	TMultiMap<FGuid, FOnMatchmakingTicketUpdatedCode> OnMatchTimedOutCode;

	/**
	 * This gets called whenever a ticket is invalidated.
	 * Use this to unbind the BP OnMatch____ you have bound for that ticket.
	 */
	UPROPERTY(BlueprintAssignable)
	FOnMatchmakingTicketUpdated OnMatchTicketInvalidated;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Beam")
	TMap<FUserSlot, FBeamMatchmakingState> Slots;

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	virtual void InitializeWhenUnrealReady_Implementation(FBeamOperationHandle& ResultOp) override;

	virtual void OnPostUserSignedIn_Implementation(const FUserSlot& UserSlot, const FBeamRealmUser& BeamRealmUser, const bool bIsOwnerUserAuth, FBeamOperationHandle& ResultOp) override;

	// LOCAL STATE GETTERS

	/**
	 * Checks if the given user slot is in a queue. 
	 */
	UFUNCTION(BlueprintCallable, Category="Beam", meta=(AutoCreateRefTerm="Slot"))
	bool IsUserSlotInQueue(const FUserSlot& Slot);

	/**
	 * Gets the TicketId for the given user slot, if any. 
	 */
	UFUNCTION(BlueprintCallable, Category="Beam", meta=(AutoCreateRefTerm="Slot", ExpandBoolAsExecs="ReturnValue"))
	bool TryGetTicketId(const FUserSlot& Slot, FGuid& TicketId);

	/**
	 * Gets the ticket data for the given user slot. 
	 */
	UFUNCTION(BlueprintCallable, Category="Beam", meta=(AutoCreateRefTerm="Slot", ExpandBoolAsExecs="ReturnValue"))
	bool TryGetTicket(const FUserSlot& Slot, FBeamMatchmakingTicket& Ticket);


	// OPERATIONS

	/**
	 * @brief Joins the given game type queue.
	 * The user in the given user slot is added to the queue. If that user is in a party:
	 *   - If its the party leader, the entire party will be added to the queue and other clients will receive notifications for it.
	 *   - If its not the party leader, the operation will fail.
	 *
	 * If the user is already in a queue, it'll fail. If the queue type has more than one team, the provided team must match one of the team names.
	 * If the queue type has a single team (FFA, for example), you can leave the team blank. Queue types with no teams are not valid.
	 */
	UFUNCTION(BlueprintCallable, Category="Beam|Operation|Matchmaking", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="CallingContext"))
	FBeamOperationHandle TryJoinQueueOperation(FUserSlot UserSlot, FBeamContentId GameTypeQueue, FOptionalString Team, FBeamOperationEventHandler OnOperationEvent);

	/**
	 * @copydoc TryJoinQueueOperation 
	 */
	FBeamOperationHandle CPP_TryJoinQueueOperation(FUserSlot UserSlot, const FBeamContentId& GameTypeQueue, FOptionalString Team, FBeamOperationEventHandlerCode OnOperationEvent);

	/**
	 * @brief Leaves the given queue. If the user is not in a queue, this fails.
	 * The user in the given user slot is added to the queue. If that user is in a party:
	 *   - If its the party leader, the entire party will be added to the queue and other clients will receive notifications for it.
	 *   - If its not the party leader, the operation will fail.
	 *
	 * If the user is already in a queue, it'll fail. If the queue type has more than one team, the provided team must match one of the team names.
	 * If the queue type has a single team (FFA, for example), you can leave the team blank. Queue types with no teams are not valid.
	 */
	UFUNCTION(BlueprintCallable, Category="Beam|Operation|Matchmaking", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="CallingContext"))
	FBeamOperationHandle TryLeaveQueueOperation(FUserSlot UserSlot, FBeamOperationEventHandler OnOperationEvent);

	/**
	 * @copydoc TryLeaveQueueOperation 
	 */
	FBeamOperationHandle CPP_TryLeaveQueueOperation(FUserSlot UserSlot, FBeamOperationEventHandlerCode OnOperationEvent);

private:
	// Operation Implementations
	void TryJoinQueue(FUserSlot Slot, FBeamContentId GameTypeQueue, FOptionalString Team, FBeamOperationHandle Op);
	void TryLeaveQueue(FUserSlot Slot, FBeamOperationHandle Op);

	// Notification Handlers
	void OnMatchmakingUpdateReceived(FMatchmakingUpdateNotificationMessage Msg);
	void OnMatchmakingTimeoutReceived(FMatchmakingTimeoutNotificationMessage Msg);

	// Utility Functions
	void InvalidateLiveTicket(FBeamMatchmakingTicket& LiveTicket);
};
