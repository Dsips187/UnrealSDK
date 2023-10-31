﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AutoGen/SubSystems/BeamAccountsApi.h"
#include "AutoGen/SubSystems/BeamAuthApi.h"
#include "AutoGen/SubSystems/Realms/GetClientDefaultsRequest.h"
#include "BeamNotifications/BeamNotifications.h"

#include "RequestTracker/BeamOperation.h"
#include "RequestTracker/BeamOperationHandle.h"
#include "RequestTracker/BeamRequestTracker.h"
#include "Serialization/ObjectReader.h"
#include "Serialization/ObjectWriter.h"
#include "UserSlots/BeamUserSlots.h"
#include "BeamRuntime.generated.h"

class UBeamRuntimeSubsystem;
class UBeamNotifications;

/**
 * State of connectivity for a specific UserSlot.
 *
 * - Offline: UserSlot is not authenticated. 
 * - Fixup: UserSlot is in the process of synchronizing all the supported OfflineOperations with the Beamable Backend (see FOfflineOperationData)
 * - Online: UserSlot is connected and has the local state synchronized with the Beamable Backend.
 */
UENUM()
enum EBeamRuntimeConnectivityState
{
	Offline,
	Fixup,
	Online,
};

/**
 * While in the Offline state, BeamRuntimeSubsystems can record offline operations into a DAG of operations.
 * The DAG is played back during the Fixup process after connection has been established, each layer of the DAG being executed in parallel.
 * It is the BeamRuntimeSubsystem's responsibility to know whether it can run in parallel or not and call the correct API to register OfflineOperations into the DAG.
 *
 * The data required for an offline operation to be played-back during fixed is stored in serialized form in the memory archive here.
 * The BeamRuntimeSubsystem that makes the operation is responsible for the data format of this buffer. 
 */
struct FOfflineOperationData
{	
	FName          OperationKey;	
	TArray<uint8>  OperationRequestDataBackingArray;		
	FMemoryArchive OperationRequestData;
};

/**
 * Manager that tracks connectivity states and the DAG of FOfflineOperationData to run during the Fixup process.
 * Exposes an API to manage the DAG while in Offline modes.
 */
UCLASS()
class URuntimeConnectivityManager : public UObject
{
	GENERATED_BODY()

public:
	FUserSlot                     OwnerSlot;
	EBeamRuntimeConnectivityState CurrentState;


	/**
	 * The number of times the connection was dropped this session.
	 * TODO: Should reset when a user logs out from this user slot.
	 */
	int32 ConnectionLostCountInSession;

	/**
	 * TODO: API for systems to build layers of operations for playback during Fixup.
	 */
	TArray<TMap<TSubclassOf<UBeamRuntimeSubsystem>, TArray<FOfflineOperationData>>> FixupOperationDAG;

	/**
	 * Count of FOfflineOperationData across all layers.
	 */
	int32 CurrentFixupOperationCount;

	/**
	 * The last time in which we detected a connection loss.
	 * Holds the session start time.  
	 */
	FDateTime CurrentConnectionLostTime;

	/**
	 * During fixup can be a long running process with multiple operations and Waits, so we track which layer of the FixupOperationDAG we are currently resolving.
	 * This is so we can correctly react to connection losses mid-fixup.
	 */
	int32                        CurrentFixupLayer;
	TArray<FBeamOperationHandle> CurrentFixupLayerOperations;
	FBeamWaitHandle              CurrentFixupLayerWaitHandle;


	/**
	 * @return Whether or not the owner of this manager is authenticated.
	 */
	bool IsAuthenticated() const { return GEngine->GetEngineSubsystem<UBeamUserSlots>()->IsUserSlotAuthenticated(OwnerSlot, this); }

	/**
	 * @return Whether or not the slot this manager is associated with is authenticated AND if we are offline. The common case being: frictionless auth is disabled.
	 */
	bool IsUnauthenticatedOfflineUser() const { return !IsAuthenticated() && CurrentState == Offline; }

	/**
	 * @return If we are authenticated, but have failed to connect the websocket during the auth flow. 
	 */
	bool HasNeverConnectedThisSession() const { return IsAuthenticated() && CurrentState == Offline && !ConnectionLostCountInSession; }

	/**
	 * @return If we are authenticated and were connected at some point and the connection was lost. 
	 */
	bool IsDisconnected() const { return IsAuthenticated() && CurrentState == Offline && ConnectionLostCountInSession; }

	/**
	 * TODO: After we've reconnected with the websocket, kick-off the fixup process.
	 */
	void StartRecoveryFixup()
	{
		if (!CurrentFixupOperationCount)
		{
			CurrentState = Online;
			return;
		}

		CurrentState = Fixup;
		// TODO: configure chain of operations for each DAG layer passing them along to UBeamRuntimeSubsystems then waiting on them to finish.
	}

	/**
	 * TODO: Kick off attempts to reconnect to the Default notification channel. Must do so with exponential backoff using default retry configs.
	 */
	void StartRecoveryFromDisconnection()
	{
		// Just do nothing if we haven't lost connection or if we are not Offline.
		if (!ConnectionLostCountInSession) return;
		if (CurrentState != Offline) return;

		// TODO: call try connect on Notification system again
		// TODO: figure out a way to keep 
	}
};


DECLARE_DYNAMIC_DELEGATE(FRuntimeStateChangedHandler);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FRuntimeStateChangedEvent);

/**
 * 
 */
UCLASS(BlueprintType, meta=(Namespace="Beam"))
class BEAMABLECORERUNTIME_API UBeamRuntime : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	/** @brief Initializes the subsystem.  */
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	/**
	 * @brief This gets called the frame after all the subsystem initializations have happened.
	 * This enables all subsystems to have a chance to subscribe to BeamRuntime events should they choose to do so.
	 * This is handled automatically for by all UBeamRuntimeSubsystems.
	 */
	virtual void TriggerInitializeWhenUnrealReady();

	/**
	 * @brief This gets called after all runtime systems had the opportunity to get ready for authentication to happen.
	 */
	void TriggerOnBeamableStarted(const TArray<FBeamRequestContext>&, const TArray<TScriptInterface<IBeamBaseRequestInterface>>&, const TArray<UObject*>&, const TArray<FBeamErrorResponse>&);
	/**
	 * @brief This gets called after all runtime subsystems have been initialized, but before the Owner Player's auth has been made.
	 */
	void TriggerGlobalOnStartedAndFrictionlessAuth(const TArray<FBeamRequestContext>&, const TArray<TScriptInterface<IBeamBaseRequestInterface>>&, const TArray<UObject*>&, const TArray<FBeamErrorResponse>&);

	/**
	 * Manages connectivity and recovery for every user slot.
	 */
	UPROPERTY()
	TMap<FUserSlot, URuntimeConnectivityManager*> ConnectivityState;


	/**
	 * @brief Callback added to the UserSlot global callback so that we can respond to users signing in.
	 * We start a chain of requests that:
	 * - Establishes a websocket connection and connectivity state.
	 * - If connected:
	 *   - Calls the User Authenticated callbacks on BeamRuntimeSubsystems.
	 *   - Then the PostUserSign in callback on every BeamRuntimeSubsystems.
	 * - If not connected:
	 *   - Go into offline mode.
	 */
	void TriggerOnUserSlotAuthenticated(const FUserSlot& UserSlot, const FBeamRealmUser& BeamRealmUser, const UObject* Context);

	/**
	 * @brief 
	 */
	void TriggerSubsystemPostUserSignIn(const TArray<FBeamRequestContext>&, const TArray<TScriptInterface<IBeamBaseRequestInterface>>&, const TArray<UObject*>&, const TArray<FBeamErrorResponse>&, FUserSlot UserSlot, FBeamRealmUser BeamRealmUser);

	/**
	 * @brief Callback added to the UserSlot global callback so that we can respond to users signing out. 
	 */
	UFUNCTION()
	void TriggerOnUserSlotCleared(const EUserSlotClearedReason& Reason, const FUserSlot& UserSlot, const FBeamRealmUser& BeamRealmUser, const UObject* Context);

	/**
	 * @brief After all subsystems have finished their respective handling of UserSlot sign-out, we give them all a chance to respond to that. 
	 */
	void TriggerPostUserSignedOut(const TArray<FBeamRequestContext>&, const TArray<TScriptInterface<IBeamBaseRequestInterface>>&, const TArray<UObject*>&, const TArray<FBeamErrorResponse>&, FUserSlot UserSlot, EUserSlotClearedReason Reason, FBeamRealmUser BeamRealmUser);

	/** Cleans up the system.  */
	virtual void Deinitialize() override;

	/**
	 * @brief Stored lambda delegate handle for what this subsystem does when a user slot is authenticated.
	 */
	FDelegateHandle UserSlotAuthenticatedHandler;

	/**
	 * @brief Stored lambda delegate handle for what this subsystem does when a user slot is cleared.
	 */
	FDelegateHandle UserSlotClearedHandler;

	/**
	 * @brief When we boot up the game instance (and it's subsystems), after all Initialize calls have finished, we allow BeamSubsystems to kick-off operations in parallel.
	 * They return operation handles that we wait on. When done, these subsystems are be ready to make unauthenticated requests to the Beamable backend.
	 */
	TArray<FBeamOperationHandle> InitializeWhenUnrealReadyOps = {};
	FBeamWaitHandle              OnInitializeWhenUnrealReadyWait;
	FOnWaitCompleteCode          OnInitializeWhenUnrealReadyCompleted;

	/**
	 * @brief After beamable has finished it's initialization but has yet to attempt its frictionless auth	 
	 */
	TArray<FBeamOperationHandle> OnBeamableStartedOps = {};
	FBeamWaitHandle              OnBeamableStartedWait;
	FOnWaitCompleteCode          OnBeamableStartedCompleted;

	/**
	 * @brief So that actors and components can react to beamable's initialization flow being finished.
	 * This runs only once during your game's execution: after all UBeamRuntimeSubsystem::OnBeamableStarted have run.
	 * If you have Automatic Frictionless Auth disabled, from this point forward, you can make Authentication calls to Beamable.
	 */
	UPROPERTY()
	FRuntimeStateChangedEvent OnStarted;

	/**
	 * @brief Every time a user signs into beamable, we give each subsystem the ability to run an operation for that user.
	 * We also give them the list of currently authenticated UserSlots (so that they can tell if the user that just signed in is the last one for example).
	 */
	TMap<FUserSlot, TArray<FBeamOperationHandle>> OnUserSignedInOps = {};
	TMap<FUserSlot, FBeamWaitHandle>              OnUserSignedInWaits;
	TMap<FUserSlot, FOnWaitCompleteCode>          OnUserSignedInCompleted;

	/**
	 * @brief After Beamable all UBeamRuntimeSubsystem::OnUserSignedIn operations have finished.
	 * This is a second layer of operations that makes it easier for users to make BeamRuntimeSystems of their own that are allowed
	 * to depend on data from our own SDK systems implementations.
	 */
	TMap<FUserSlot, TArray<FBeamOperationHandle>> OnPostUserSignedInOps = {};
	TMap<FUserSlot, FBeamWaitHandle>              OnPostUserSignedInWaits;
	TMap<FUserSlot, FOnWaitCompleteCode>          OnPostUserSignedInCompleted;

	/**
	 * @brief So that actors and components can react to failures in the user authentication flow.
	 * This runs after all of the BeamRuntimeSubsystems have run their OnFailedUserAuth callback. 
	 */
	UPROPERTY(BlueprintAssignable)
	FRuntimeStateChangedEvent OnFailedUserAuth;

	/**
	 * @brief So that actors and components can react to beamable's initialization flow being finished.
	 *  The OnReady event is what game makers should use when registering their actors, systems, etc... if they wish to depend on beamable's runtime systems.
	 *
	 *  This runs only once during your game's entire run: after the PostUserSignIn call of the OwnerPlayer's authentication. 
	 */
	UPROPERTY()
	FRuntimeStateChangedEvent OnReady;

	/**
	 * @brief Every time a user signs out of beamable we give each subsystem the ability to run an operation for that user.
	 * We also give them the list of currently authenticated User Slots and the reason for the sign out so that they can correctly decide what to do in each instance.
	 */
	TMap<FUserSlot, TArray<FBeamOperationHandle>> OnUserSignedOutOps = {};
	TMap<FUserSlot, FBeamWaitHandle>              OnUserSignedOutWaits;
	TMap<FUserSlot, FOnWaitCompleteCode>          OnUserSignedOutCompleted;

	/**
	 * @brief After Beamable all UBeamRuntimeSubsystem::OnUserSignedOut operations have finished.
	 * This is a second layer of operations that makes it easier for users to make BeamRuntimeSystems of their own that are allowed
	 * need to perform cleanup after our own SDK systems have finished theirs.
	 */
	TMap<FUserSlot, TArray<FBeamOperationHandle>> OnPostUserSignedOutOps = {};
	TMap<FUserSlot, FBeamWaitHandle>              OnPostUserSignedOutWaits;
	TMap<FUserSlot, FOnWaitCompleteCode>          OnPostUserSignedOutCompleted;

	/**
	 * @brief For each user slot, we automatically open and connect to the beamable notification service
	 * (web-socket protocol through which we receive).
	 */
	TMap<FUserSlot, FBeamWebSocketHandle> DefaultNotificationChannels;

public:
	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, meta=(DefaultToSelf="CallingContext"))
	static UBeamRuntime* GetSelf(const UObject* CallingContext) { return CallingContext->GetWorld()->GetGameInstance()->GetSubsystem<UBeamRuntime>(); }

	static const inline FName DefaultNotificationChannel = FName(TEXT("Default"));

	/**
	 * @brief Function that replaces UBeamBackend::DefaultExecuteRequestImpl when running in PIE mode.
	 * 
	 */
	UFUNCTION()
	void PIEExecuteRequestImpl(int64 ActiveRequestId, FBeamConnectivity& Connectivity);

	UPROPERTY()
	UBeamUserSlots* UserSlotSystem;

	UPROPERTY()
	UBeamRequestTracker* RequestTrackerSystem;

	UPROPERTY()
	UBeamNotifications* NotificationSystem;

	/**
	 * @brief This flag is used for beamable's automatic initialization.
	 * It ensures that the OnBeamableReady event is only ever called once in one of two moments after the game boots up:
	 *  - If UserSlot at index 0 is signed in already, we wait for it's authentication flow to finish and then call it.
	 *  - If UserSlot at index 0 is NOT signed in already, we call it during DelayedInitialize (for now, we assume this is the "owner" player of the game -- player 1).
	 *
	 *  BeamRuntimeSubsystems implement their OnBeamableReady function event to: either set up local data by kicking-off operations to fetch data.
	 *
	 *  The OnReady event exposed here is what game makers should use when registering their actors, components, etc... if they wish to depend on beamable's runtime systems.	  
	 */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, DisplayName="IsOwnerUserAuthenticated")
	bool bIsOwnerPlayerAuthenticated = false;

	/**
	 * @brief This flag is used to verify that beamable has been properly initialized and is ready for authentication.
	 */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, DisplayName="IsBeamableStarted")
	bool bIsBeamableStarted = false;

	/**
	 * If runs the FrictionlessAuthentication flow for the given user slot. You can make this call whenever you want to create a new user into a new slot.
	 * Passing nothing, will sign into the OwnerPlayerSlot. If the given slot is already authenticated, this is a no-op.
	 */
	UFUNCTION(BlueprintCallable)
	void FrictionlessAuthenticateSlot(const FUserSlot& UserSlot);

	/**
	 * @brief In BP, use this function to bind initialization functions to OnReady. This will execute the delegate if you're already ready before it binds it. 
	 */
	UFUNCTION(BlueprintCallable)
	void RegisterOnStarted(FRuntimeStateChangedHandler Handler)
	{
		if (bIsBeamableStarted) const auto _ = Handler.ExecuteIfBound();
		OnStarted.Add(Handler);
	}

	/**
	 * @brief In BP, use this function to bind initialization functions to OnReady. This will NOT execute the delegate if you're already ready. 
	 */
	UFUNCTION(BlueprintCallable)
	void RegisterOnStarted_NoExecute(FRuntimeStateChangedHandler Handler) { OnStarted.Add(Handler); }

	/**
	 * @brief In BP, use this function to unbind initialization custom events to OnReady. 
	 */
	UFUNCTION(BlueprintCallable)
	void UnregisterOnStarted(FRuntimeStateChangedHandler Handler)
	{
		if(OnStarted.Contains(Handler))
			OnStarted.Remove(Handler);
	}

	
	/**
	 * @brief In BP, use this function to bind initialization functions to OnReady. This will execute the delegate if you're already ready before it binds it. 
	 */
	UFUNCTION(BlueprintCallable)
	void RegisterOnReady(FRuntimeStateChangedHandler Handler)
	{
		if (bIsOwnerPlayerAuthenticated) const auto _ = Handler.ExecuteIfBound();
		OnReady.Add(Handler);		
	}

	/**
	 * @brief In BP, use this function to bind initialization functions to OnReady. This will NOT execute the delegate if you're already ready. 
	 */
	UFUNCTION(BlueprintCallable)
	void RegisterOnReady_NoExecute(FRuntimeStateChangedHandler Handler) { OnReady.Add(Handler); }

	/**
	 * @brief In BP, use this function to unbind initialization custom events to OnReady. 
	 */
	UFUNCTION(BlueprintCallable)
	void UnregisterOnReady(FRuntimeStateChangedHandler Handler)
	{
		if(OnReady.Contains(Handler))
			OnReady.Remove(Handler);
	}

	/**
	 * @brief An operation that will authenticate a user with the beamable and persist that authentication locally.
	 */
	UFUNCTION(BlueprintCallable, Category="Beam|Operation|Auth", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="CallingContext"))
	FBeamOperationHandle AuthenticateFrictionlessOperation(FUserSlot UserSlot, FBeamOperationEventHandler OnOperationEvent, UObject* CallingContext = nullptr);

	/**
	 * @brief An operation that will authenticate a user with the beamable and persist that authentication locally.
	 */
	FBeamOperationHandle CPP_AuthenticateFrictionlessOperation(FUserSlot UserSlot, FBeamOperationEventHandlerCode OnOperationEvent, UObject* CallingContext = nullptr);

	/**
	 * Use this if you wish to authenticate by manually making an Authenticate Request to the Auth Service (pass in the Token you get as a response here).
	 */
	UFUNCTION(BlueprintCallable, Category="Beam|Operation|Auth", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="CallingContext"))
	FBeamOperationHandle AuthenticateWithTokenOperation(FUserSlot UserSlot, UTokenResponse* TokenResponse, FBeamOperationEventHandler OnOperationEvent, UObject* CallingContext = nullptr);

	/**
	 * Use this if you wish to authenticate by manually making an Authenticate Request to the Auth Service (pass in the Token you get as a response here).
	 */
	FBeamOperationHandle CPP_AuthenticateWithTokenOperation(FUserSlot UserSlot, const UTokenResponse* TokenResponse, FBeamOperationEventHandlerCode OnOperationEvent, UObject* CallingContext = nullptr);

private:
	// Operation Implementations
	void AuthenticateFrictionless(FUserSlot UserSlot, FBeamOperationHandle Op, UObject* CallingContext);
	void AuthenticateFrictionless_OnAuthenticated(FAuthenticateFullResponse Resp, FUserSlot UserSlot, FBeamOperationHandle Op);

	void AuthenticateWithToken(FUserSlot UserSlot, const UTokenResponse* Token, FBeamOperationHandle Op);

	void RunPostAuthenticationSetup(FUserSlot UserSlot, FBeamOperationHandle Op);
	void RunPostAuthenticationSetup_OnGetMe(FBasicAccountsGetMeFullResponse Response, FUserSlot UserSlot, FBeamOperationHandle Op);
	void RunPostAuthenticationSetup_PrepareNotificationService(FGetClientDefaultsFullResponse Resp, FUserSlot UserSlot, FBeamRealmUser BeamRealmUser, FBeamOperationHandle Op);


	/**
	 * Call as part of an operation to verify that the given token, generated by the given provider and in the given namespace, is available for association to a beamable account.
	 * @param IsAvailable Allocated bool where we'll write the availability. We do not own this memory. Deallocate on Operation completion.
	 */
	void CheckExternalIdentityAvailable(FString ExternalProvider, FString ExternalNamespace, FString ExternalToken, FBeamOperationHandle Op, bool* IsAvailable);

	/**
	 * Tries to get the default notification channel for the given user slot. 
	 */
	bool GetDefaultNotificationChannel(const FUserSlot& UserSlot, FBeamWebSocketHandle& OutHandle) const;

	/**
	 * Adds the default information session information tracked by the SDK into the given header dictionary. 
	 */
	virtual void FillDefaultSessionHeaders(TMap<FString, FString>& Headers);

	static inline FString BEAM_SESSION_HEADER_PLATFORM = FString(TEXT("X-BEAM-SESSION-PLATFORM"));
	static inline FString BEAM_SESSION_HEADER_DEVICE   = FString(TEXT("X-BEAM-SESSION-DEVICE"));
	static inline FString BEAM_SESSION_HEADER_SOURCE   = FString(TEXT("X-BEAM-SESSION-SOURCE"));
	static inline FString BEAM_SESSION_HEADER_LOCALE   = FString(TEXT("X-BEAM-SESSION-LOCALE"));
	static inline FString BEAM_SESSION_HEADER_LANGUAGE = FString(TEXT("X-BEAM-SESSION-LANGUAGE"));
};
