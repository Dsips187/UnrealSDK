

#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBackend.h"
#include "RequestTracker/BeamRequestTracker.h"

#include "Leaderboards/GetRanksRequest.h"
#include "Leaderboards/GetMatchesRequest.h"
#include "Leaderboards/PutEntryRequest.h"
#include "Leaderboards/GetViewRequest.h"
#include "Leaderboards/BasicLeaderboardsGetListRequest.h"
#include "Leaderboards/GetPlayerRequest.h"
#include "Leaderboards/BasicLeaderboardsGetAssignmentRequest.h"
#include "Leaderboards/GetUidRequest.h"
#include "Leaderboards/DeleteEntriesRequest.h"
#include "Leaderboards/GetMembershipRequest.h"
#include "Leaderboards/GetPartitionRequest.h"
#include "Leaderboards/GetFriendsRequest.h"
#include "Leaderboards/PostLeaderboardsRequest.h"
#include "Leaderboards/DeleteLeaderboardsRequest.h"
#include "Leaderboards/ObjectLeaderboardsGetAssignmentRequest.h"
#include "Leaderboards/DeleteAssignmentRequest.h"
#include "Leaderboards/DeleteEntryRequest.h"
#include "Leaderboards/PutFreezeRequest.h"
#include "Leaderboards/GetDetailsRequest.h"
#include "Leaderboards/PutSwapRequest.h"

#include "BeamLeaderboardsApi.generated.h"


/**
 * Subsystem containing request calls for the Leaderboards service.
 */
UCLASS(NotBlueprintType)
class BEAMABLECORE_API UBeamLeaderboardsApi : public UEngineSubsystem
{
private:
	GENERATED_BODY()
	/** @brief Initializes the auto-increment Id and binds the ExecuteRequestDelegate to DefaultExecuteRequestImpl  */
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	/** Cleans up the system.  */
	virtual void Deinitialize() override;

	UPROPERTY()
	UBeamBackend* Backend;

	UPROPERTY()
	UBeamRequestTracker* RequestTracker;

	
	/**
	 * @brief Private implementation that all overloaded BP UFunctions call.	  
	 */
	void BP_GetRanksImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, FBeamConnectivity& ConnectivityStatus, UGetRanksRequest* RequestData,
	                                const FOnGetRanksSuccess& OnSuccess, const FOnGetRanksError& OnError, const FOnGetRanksComplete& OnComplete,
	                                int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_GetRanksImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, FBeamConnectivity& ConnectivityStatus, UGetRanksRequest* RequestData,
	                                 const FOnGetRanksFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;

		
	/**
	 * @brief Private implementation that all overloaded BP UFunctions call.	  
	 */
	void BP_GetMatchesImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, FBeamConnectivity& ConnectivityStatus, UGetMatchesRequest* RequestData,
	                                const FOnGetMatchesSuccess& OnSuccess, const FOnGetMatchesError& OnError, const FOnGetMatchesComplete& OnComplete,
	                                int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_GetMatchesImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, FBeamConnectivity& ConnectivityStatus, UGetMatchesRequest* RequestData,
	                                 const FOnGetMatchesFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;

		
	/**
	 * @brief Private implementation that all overloaded BP UFunctions call.	  
	 */
	void BP_PutEntryImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, FBeamConnectivity& ConnectivityStatus, UPutEntryRequest* RequestData,
	                                const FOnPutEntrySuccess& OnSuccess, const FOnPutEntryError& OnError, const FOnPutEntryComplete& OnComplete,
	                                int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_PutEntryImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, FBeamConnectivity& ConnectivityStatus, UPutEntryRequest* RequestData,
	                                 const FOnPutEntryFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;

		
	/**
	 * @brief Private implementation that all overloaded BP UFunctions call.	  
	 */
	void BP_GetViewImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, FBeamConnectivity& ConnectivityStatus, UGetViewRequest* RequestData,
	                                const FOnGetViewSuccess& OnSuccess, const FOnGetViewError& OnError, const FOnGetViewComplete& OnComplete,
	                                int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_GetViewImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, FBeamConnectivity& ConnectivityStatus, UGetViewRequest* RequestData,
	                                 const FOnGetViewFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;


	
	/**
	 * @brief Private implementation for requests that require authentication that all overloaded BP UFunctions call.	  
	 */
	void BP_GetListImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UBasicLeaderboardsGetListRequest* RequestData,
	                  const FOnBasicLeaderboardsGetListSuccess& OnSuccess, const FOnBasicLeaderboardsGetListError& OnError, const FOnBasicLeaderboardsGetListComplete& OnComplete, 
					  int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_GetListImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UBasicLeaderboardsGetListRequest* RequestData,
	                   const FOnBasicLeaderboardsGetListFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
		
	/**
	 * @brief Private implementation for requests that require authentication that all overloaded BP UFunctions call.	  
	 */
	void BP_GetPlayerImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UGetPlayerRequest* RequestData,
	                  const FOnGetPlayerSuccess& OnSuccess, const FOnGetPlayerError& OnError, const FOnGetPlayerComplete& OnComplete, 
					  int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_GetPlayerImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UGetPlayerRequest* RequestData,
	                   const FOnGetPlayerFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
		
	/**
	 * @brief Private implementation for requests that require authentication that all overloaded BP UFunctions call.	  
	 */
	void BP_BasicLeaderboardsGetAssignmentImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UBasicLeaderboardsGetAssignmentRequest* RequestData,
	                  const FOnBasicLeaderboardsGetAssignmentSuccess& OnSuccess, const FOnBasicLeaderboardsGetAssignmentError& OnError, const FOnBasicLeaderboardsGetAssignmentComplete& OnComplete, 
					  int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_BasicLeaderboardsGetAssignmentImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UBasicLeaderboardsGetAssignmentRequest* RequestData,
	                   const FOnBasicLeaderboardsGetAssignmentFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
		
	/**
	 * @brief Private implementation for requests that require authentication that all overloaded BP UFunctions call.	  
	 */
	void BP_GetUidImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UGetUidRequest* RequestData,
	                  const FOnGetUidSuccess& OnSuccess, const FOnGetUidError& OnError, const FOnGetUidComplete& OnComplete, 
					  int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_GetUidImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UGetUidRequest* RequestData,
	                   const FOnGetUidFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
		
	/**
	 * @brief Private implementation for requests that require authentication that all overloaded BP UFunctions call.	  
	 */
	void BP_DeleteEntriesImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UDeleteEntriesRequest* RequestData,
	                  const FOnDeleteEntriesSuccess& OnSuccess, const FOnDeleteEntriesError& OnError, const FOnDeleteEntriesComplete& OnComplete, 
					  int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_DeleteEntriesImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UDeleteEntriesRequest* RequestData,
	                   const FOnDeleteEntriesFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
		
	/**
	 * @brief Private implementation for requests that require authentication that all overloaded BP UFunctions call.	  
	 */
	void BP_GetMembershipImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UGetMembershipRequest* RequestData,
	                  const FOnGetMembershipSuccess& OnSuccess, const FOnGetMembershipError& OnError, const FOnGetMembershipComplete& OnComplete, 
					  int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_GetMembershipImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UGetMembershipRequest* RequestData,
	                   const FOnGetMembershipFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
		
	/**
	 * @brief Private implementation for requests that require authentication that all overloaded BP UFunctions call.	  
	 */
	void BP_GetPartitionImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UGetPartitionRequest* RequestData,
	                  const FOnGetPartitionSuccess& OnSuccess, const FOnGetPartitionError& OnError, const FOnGetPartitionComplete& OnComplete, 
					  int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_GetPartitionImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UGetPartitionRequest* RequestData,
	                   const FOnGetPartitionFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
		
	/**
	 * @brief Private implementation for requests that require authentication that all overloaded BP UFunctions call.	  
	 */
	void BP_GetFriendsImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UGetFriendsRequest* RequestData,
	                  const FOnGetFriendsSuccess& OnSuccess, const FOnGetFriendsError& OnError, const FOnGetFriendsComplete& OnComplete, 
					  int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_GetFriendsImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UGetFriendsRequest* RequestData,
	                   const FOnGetFriendsFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
		
	/**
	 * @brief Private implementation for requests that require authentication that all overloaded BP UFunctions call.	  
	 */
	void BP_PostLeaderboardsImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UPostLeaderboardsRequest* RequestData,
	                  const FOnPostLeaderboardsSuccess& OnSuccess, const FOnPostLeaderboardsError& OnError, const FOnPostLeaderboardsComplete& OnComplete, 
					  int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_PostLeaderboardsImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UPostLeaderboardsRequest* RequestData,
	                   const FOnPostLeaderboardsFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
		
	/**
	 * @brief Private implementation for requests that require authentication that all overloaded BP UFunctions call.	  
	 */
	void BP_DeleteLeaderboardsImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UDeleteLeaderboardsRequest* RequestData,
	                  const FOnDeleteLeaderboardsSuccess& OnSuccess, const FOnDeleteLeaderboardsError& OnError, const FOnDeleteLeaderboardsComplete& OnComplete, 
					  int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_DeleteLeaderboardsImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UDeleteLeaderboardsRequest* RequestData,
	                   const FOnDeleteLeaderboardsFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
		
	/**
	 * @brief Private implementation for requests that require authentication that all overloaded BP UFunctions call.	  
	 */
	void BP_ObjectLeaderboardsGetAssignmentImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UObjectLeaderboardsGetAssignmentRequest* RequestData,
	                  const FOnObjectLeaderboardsGetAssignmentSuccess& OnSuccess, const FOnObjectLeaderboardsGetAssignmentError& OnError, const FOnObjectLeaderboardsGetAssignmentComplete& OnComplete, 
					  int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_ObjectLeaderboardsGetAssignmentImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UObjectLeaderboardsGetAssignmentRequest* RequestData,
	                   const FOnObjectLeaderboardsGetAssignmentFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
		
	/**
	 * @brief Private implementation for requests that require authentication that all overloaded BP UFunctions call.	  
	 */
	void BP_DeleteAssignmentImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UDeleteAssignmentRequest* RequestData,
	                  const FOnDeleteAssignmentSuccess& OnSuccess, const FOnDeleteAssignmentError& OnError, const FOnDeleteAssignmentComplete& OnComplete, 
					  int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_DeleteAssignmentImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UDeleteAssignmentRequest* RequestData,
	                   const FOnDeleteAssignmentFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
		
	/**
	 * @brief Private implementation for requests that require authentication that all overloaded BP UFunctions call.	  
	 */
	void BP_DeleteEntryImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UDeleteEntryRequest* RequestData,
	                  const FOnDeleteEntrySuccess& OnSuccess, const FOnDeleteEntryError& OnError, const FOnDeleteEntryComplete& OnComplete, 
					  int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_DeleteEntryImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UDeleteEntryRequest* RequestData,
	                   const FOnDeleteEntryFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
		
	/**
	 * @brief Private implementation for requests that require authentication that all overloaded BP UFunctions call.	  
	 */
	void BP_PutFreezeImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UPutFreezeRequest* RequestData,
	                  const FOnPutFreezeSuccess& OnSuccess, const FOnPutFreezeError& OnError, const FOnPutFreezeComplete& OnComplete, 
					  int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_PutFreezeImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UPutFreezeRequest* RequestData,
	                   const FOnPutFreezeFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
		
	/**
	 * @brief Private implementation for requests that require authentication that all overloaded BP UFunctions call.	  
	 */
	void BP_GetDetailsImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UGetDetailsRequest* RequestData,
	                  const FOnGetDetailsSuccess& OnSuccess, const FOnGetDetailsError& OnError, const FOnGetDetailsComplete& OnComplete, 
					  int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_GetDetailsImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UGetDetailsRequest* RequestData,
	                   const FOnGetDetailsFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
		
	/**
	 * @brief Private implementation for requests that require authentication that all overloaded BP UFunctions call.	  
	 */
	void BP_PutSwapImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UPutSwapRequest* RequestData,
	                  const FOnPutSwapSuccess& OnSuccess, const FOnPutSwapError& OnError, const FOnPutSwapComplete& OnComplete, 
					  int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_PutSwapImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UPutSwapRequest* RequestData,
	                   const FOnPutSwapFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;

public:
	
	/** Used by a helper blueprint node so that you can easily chain requests in BP-land. */
	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly)
	static UBeamLeaderboardsApi* GetSelf() { return GEngine->GetEngineSubsystem<UBeamLeaderboardsApi>(); }

	
	/**
	 * @brief Makes a request to the Get /object/leaderboards/{objectId}/ranks endpoint of the Leaderboards Service.
	 *
	 * PREFER THE UFUNCTION OVERLOAD AS OPPOSED TO THIS. THIS MAINLY EXISTS TO ALLOW LAMBDA BINDING THE HANDLER.
	 * (Dynamic delegates do not allow for that so... we autogen this one to make experimenting in CPP a bit faster and for whenever you need to capture variables).
	 * 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param Handler A callback that defines how to handle success, error and completion.
     * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
	 * @param OpHandle When made as part of an Operation, you can pass this in and it'll register the request with the operation automatically. 
	 */
	void CPP_GetRanks(UGetRanksRequest* Request, const FOnGetRanksFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;

		
	/**
	 * @brief Makes a request to the Get /object/leaderboards/{objectId}/matches endpoint of the Leaderboards Service.
	 *
	 * PREFER THE UFUNCTION OVERLOAD AS OPPOSED TO THIS. THIS MAINLY EXISTS TO ALLOW LAMBDA BINDING THE HANDLER.
	 * (Dynamic delegates do not allow for that so... we autogen this one to make experimenting in CPP a bit faster and for whenever you need to capture variables).
	 * 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param Handler A callback that defines how to handle success, error and completion.
     * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
	 * @param OpHandle When made as part of an Operation, you can pass this in and it'll register the request with the operation automatically. 
	 */
	void CPP_GetMatches(UGetMatchesRequest* Request, const FOnGetMatchesFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;

		
	/**
	 * @brief Makes a request to the Put /object/leaderboards/{objectId}/entry endpoint of the Leaderboards Service.
	 *
	 * PREFER THE UFUNCTION OVERLOAD AS OPPOSED TO THIS. THIS MAINLY EXISTS TO ALLOW LAMBDA BINDING THE HANDLER.
	 * (Dynamic delegates do not allow for that so... we autogen this one to make experimenting in CPP a bit faster and for whenever you need to capture variables).
	 * 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param Handler A callback that defines how to handle success, error and completion.
     * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
	 * @param OpHandle When made as part of an Operation, you can pass this in and it'll register the request with the operation automatically. 
	 */
	void CPP_PutEntry(UPutEntryRequest* Request, const FOnPutEntryFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;

		
	/**
	 * @brief Makes a request to the Get /object/leaderboards/{objectId}/view endpoint of the Leaderboards Service.
	 *
	 * PREFER THE UFUNCTION OVERLOAD AS OPPOSED TO THIS. THIS MAINLY EXISTS TO ALLOW LAMBDA BINDING THE HANDLER.
	 * (Dynamic delegates do not allow for that so... we autogen this one to make experimenting in CPP a bit faster and for whenever you need to capture variables).
	 * 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param Handler A callback that defines how to handle success, error and completion.
     * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
	 * @param OpHandle When made as part of an Operation, you can pass this in and it'll register the request with the operation automatically. 
	 */
	void CPP_GetView(UGetViewRequest* Request, const FOnGetViewFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;


	
	/**
	 * @brief Makes an authenticated request to the Get /basic/leaderboards/list endpoint of the Leaderboards Service.
	 *
	 * PREFER THE UFUNCTION OVERLOAD AS OPPOSED TO THIS. THIS MAINLY EXISTS TO ALLOW LAMBDA BINDING THE HANDLER.
	 * (Dynamic delegates do not allow for that so... we autogen this one to make experimenting in CPP a bit faster).
	 * 
	 * @param UserSlot The Authenticated User Slot that is making this request.
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param Handler A callback that defines how to handle success, error and completion.
     * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
	 * @param OpHandle When made as part of an Operation, you can pass this in and it'll register the request with the operation automatically.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId). 
	 */
	void CPP_GetList(const FUserSlot& UserSlot, UBasicLeaderboardsGetListRequest* Request, const FOnBasicLeaderboardsGetListFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr) const;

		
	/**
	 * @brief Makes an authenticated request to the Get /basic/leaderboards/player endpoint of the Leaderboards Service.
	 *
	 * PREFER THE UFUNCTION OVERLOAD AS OPPOSED TO THIS. THIS MAINLY EXISTS TO ALLOW LAMBDA BINDING THE HANDLER.
	 * (Dynamic delegates do not allow for that so... we autogen this one to make experimenting in CPP a bit faster).
	 * 
	 * @param UserSlot The Authenticated User Slot that is making this request.
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param Handler A callback that defines how to handle success, error and completion.
     * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
	 * @param OpHandle When made as part of an Operation, you can pass this in and it'll register the request with the operation automatically.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId). 
	 */
	void CPP_GetPlayer(const FUserSlot& UserSlot, UGetPlayerRequest* Request, const FOnGetPlayerFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr) const;

		
	/**
	 * @brief Makes an authenticated request to the Get /basic/leaderboards/assignment endpoint of the Leaderboards Service.
	 *
	 * PREFER THE UFUNCTION OVERLOAD AS OPPOSED TO THIS. THIS MAINLY EXISTS TO ALLOW LAMBDA BINDING THE HANDLER.
	 * (Dynamic delegates do not allow for that so... we autogen this one to make experimenting in CPP a bit faster).
	 * 
	 * @param UserSlot The Authenticated User Slot that is making this request.
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param Handler A callback that defines how to handle success, error and completion.
     * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
	 * @param OpHandle When made as part of an Operation, you can pass this in and it'll register the request with the operation automatically.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId). 
	 */
	void CPP_BasicLeaderboardsGetAssignment(const FUserSlot& UserSlot, UBasicLeaderboardsGetAssignmentRequest* Request, const FOnBasicLeaderboardsGetAssignmentFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr) const;

		
	/**
	 * @brief Makes an authenticated request to the Get /basic/leaderboards/uid endpoint of the Leaderboards Service.
	 *
	 * PREFER THE UFUNCTION OVERLOAD AS OPPOSED TO THIS. THIS MAINLY EXISTS TO ALLOW LAMBDA BINDING THE HANDLER.
	 * (Dynamic delegates do not allow for that so... we autogen this one to make experimenting in CPP a bit faster).
	 * 
	 * @param UserSlot The Authenticated User Slot that is making this request.
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param Handler A callback that defines how to handle success, error and completion.
     * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
	 * @param OpHandle When made as part of an Operation, you can pass this in and it'll register the request with the operation automatically.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId). 
	 */
	void CPP_GetUid(const FUserSlot& UserSlot, UGetUidRequest* Request, const FOnGetUidFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr) const;

		
	/**
	 * @brief Makes an authenticated request to the Delete /object/leaderboards/{objectId}/entries endpoint of the Leaderboards Service.
	 *
	 * PREFER THE UFUNCTION OVERLOAD AS OPPOSED TO THIS. THIS MAINLY EXISTS TO ALLOW LAMBDA BINDING THE HANDLER.
	 * (Dynamic delegates do not allow for that so... we autogen this one to make experimenting in CPP a bit faster).
	 * 
	 * @param UserSlot The Authenticated User Slot that is making this request.
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param Handler A callback that defines how to handle success, error and completion.
     * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
	 * @param OpHandle When made as part of an Operation, you can pass this in and it'll register the request with the operation automatically.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId). 
	 */
	void CPP_DeleteEntries(const FUserSlot& UserSlot, UDeleteEntriesRequest* Request, const FOnDeleteEntriesFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr) const;

		
	/**
	 * @brief Makes an authenticated request to the Get /object/leaderboards/{objectId}/membership endpoint of the Leaderboards Service.
	 *
	 * PREFER THE UFUNCTION OVERLOAD AS OPPOSED TO THIS. THIS MAINLY EXISTS TO ALLOW LAMBDA BINDING THE HANDLER.
	 * (Dynamic delegates do not allow for that so... we autogen this one to make experimenting in CPP a bit faster).
	 * 
	 * @param UserSlot The Authenticated User Slot that is making this request.
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param Handler A callback that defines how to handle success, error and completion.
     * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
	 * @param OpHandle When made as part of an Operation, you can pass this in and it'll register the request with the operation automatically.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId). 
	 */
	void CPP_GetMembership(const FUserSlot& UserSlot, UGetMembershipRequest* Request, const FOnGetMembershipFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr) const;

		
	/**
	 * @brief Makes an authenticated request to the Get /object/leaderboards/{objectId}/partition endpoint of the Leaderboards Service.
	 *
	 * PREFER THE UFUNCTION OVERLOAD AS OPPOSED TO THIS. THIS MAINLY EXISTS TO ALLOW LAMBDA BINDING THE HANDLER.
	 * (Dynamic delegates do not allow for that so... we autogen this one to make experimenting in CPP a bit faster).
	 * 
	 * @param UserSlot The Authenticated User Slot that is making this request.
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param Handler A callback that defines how to handle success, error and completion.
     * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
	 * @param OpHandle When made as part of an Operation, you can pass this in and it'll register the request with the operation automatically.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId). 
	 */
	void CPP_GetPartition(const FUserSlot& UserSlot, UGetPartitionRequest* Request, const FOnGetPartitionFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr) const;

		
	/**
	 * @brief Makes an authenticated request to the Get /object/leaderboards/{objectId}/friends endpoint of the Leaderboards Service.
	 *
	 * PREFER THE UFUNCTION OVERLOAD AS OPPOSED TO THIS. THIS MAINLY EXISTS TO ALLOW LAMBDA BINDING THE HANDLER.
	 * (Dynamic delegates do not allow for that so... we autogen this one to make experimenting in CPP a bit faster).
	 * 
	 * @param UserSlot The Authenticated User Slot that is making this request.
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param Handler A callback that defines how to handle success, error and completion.
     * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
	 * @param OpHandle When made as part of an Operation, you can pass this in and it'll register the request with the operation automatically.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId). 
	 */
	void CPP_GetFriends(const FUserSlot& UserSlot, UGetFriendsRequest* Request, const FOnGetFriendsFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr) const;

		
	/**
	 * @brief Makes an authenticated request to the Post /object/leaderboards/{objectId}/ endpoint of the Leaderboards Service.
	 *
	 * PREFER THE UFUNCTION OVERLOAD AS OPPOSED TO THIS. THIS MAINLY EXISTS TO ALLOW LAMBDA BINDING THE HANDLER.
	 * (Dynamic delegates do not allow for that so... we autogen this one to make experimenting in CPP a bit faster).
	 * 
	 * @param UserSlot The Authenticated User Slot that is making this request.
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param Handler A callback that defines how to handle success, error and completion.
     * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
	 * @param OpHandle When made as part of an Operation, you can pass this in and it'll register the request with the operation automatically.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId). 
	 */
	void CPP_PostLeaderboards(const FUserSlot& UserSlot, UPostLeaderboardsRequest* Request, const FOnPostLeaderboardsFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr) const;

		
	/**
	 * @brief Makes an authenticated request to the Delete /object/leaderboards/{objectId}/ endpoint of the Leaderboards Service.
	 *
	 * PREFER THE UFUNCTION OVERLOAD AS OPPOSED TO THIS. THIS MAINLY EXISTS TO ALLOW LAMBDA BINDING THE HANDLER.
	 * (Dynamic delegates do not allow for that so... we autogen this one to make experimenting in CPP a bit faster).
	 * 
	 * @param UserSlot The Authenticated User Slot that is making this request.
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param Handler A callback that defines how to handle success, error and completion.
     * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
	 * @param OpHandle When made as part of an Operation, you can pass this in and it'll register the request with the operation automatically.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId). 
	 */
	void CPP_DeleteLeaderboards(const FUserSlot& UserSlot, UDeleteLeaderboardsRequest* Request, const FOnDeleteLeaderboardsFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr) const;

		
	/**
	 * @brief Makes an authenticated request to the Get /object/leaderboards/{objectId}/assignment endpoint of the Leaderboards Service.
	 *
	 * PREFER THE UFUNCTION OVERLOAD AS OPPOSED TO THIS. THIS MAINLY EXISTS TO ALLOW LAMBDA BINDING THE HANDLER.
	 * (Dynamic delegates do not allow for that so... we autogen this one to make experimenting in CPP a bit faster).
	 * 
	 * @param UserSlot The Authenticated User Slot that is making this request.
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param Handler A callback that defines how to handle success, error and completion.
     * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
	 * @param OpHandle When made as part of an Operation, you can pass this in and it'll register the request with the operation automatically.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId). 
	 */
	void CPP_ObjectLeaderboardsGetAssignment(const FUserSlot& UserSlot, UObjectLeaderboardsGetAssignmentRequest* Request, const FOnObjectLeaderboardsGetAssignmentFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr) const;

		
	/**
	 * @brief Makes an authenticated request to the Delete /object/leaderboards/{objectId}/assignment endpoint of the Leaderboards Service.
	 *
	 * PREFER THE UFUNCTION OVERLOAD AS OPPOSED TO THIS. THIS MAINLY EXISTS TO ALLOW LAMBDA BINDING THE HANDLER.
	 * (Dynamic delegates do not allow for that so... we autogen this one to make experimenting in CPP a bit faster).
	 * 
	 * @param UserSlot The Authenticated User Slot that is making this request.
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param Handler A callback that defines how to handle success, error and completion.
     * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
	 * @param OpHandle When made as part of an Operation, you can pass this in and it'll register the request with the operation automatically.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId). 
	 */
	void CPP_DeleteAssignment(const FUserSlot& UserSlot, UDeleteAssignmentRequest* Request, const FOnDeleteAssignmentFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr) const;

		
	/**
	 * @brief Makes an authenticated request to the Delete /object/leaderboards/{objectId}/entry endpoint of the Leaderboards Service.
	 *
	 * PREFER THE UFUNCTION OVERLOAD AS OPPOSED TO THIS. THIS MAINLY EXISTS TO ALLOW LAMBDA BINDING THE HANDLER.
	 * (Dynamic delegates do not allow for that so... we autogen this one to make experimenting in CPP a bit faster).
	 * 
	 * @param UserSlot The Authenticated User Slot that is making this request.
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param Handler A callback that defines how to handle success, error and completion.
     * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
	 * @param OpHandle When made as part of an Operation, you can pass this in and it'll register the request with the operation automatically.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId). 
	 */
	void CPP_DeleteEntry(const FUserSlot& UserSlot, UDeleteEntryRequest* Request, const FOnDeleteEntryFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr) const;

		
	/**
	 * @brief Makes an authenticated request to the Put /object/leaderboards/{objectId}/freeze endpoint of the Leaderboards Service.
	 *
	 * PREFER THE UFUNCTION OVERLOAD AS OPPOSED TO THIS. THIS MAINLY EXISTS TO ALLOW LAMBDA BINDING THE HANDLER.
	 * (Dynamic delegates do not allow for that so... we autogen this one to make experimenting in CPP a bit faster).
	 * 
	 * @param UserSlot The Authenticated User Slot that is making this request.
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param Handler A callback that defines how to handle success, error and completion.
     * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
	 * @param OpHandle When made as part of an Operation, you can pass this in and it'll register the request with the operation automatically.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId). 
	 */
	void CPP_PutFreeze(const FUserSlot& UserSlot, UPutFreezeRequest* Request, const FOnPutFreezeFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr) const;

		
	/**
	 * @brief Makes an authenticated request to the Get /object/leaderboards/{objectId}/details endpoint of the Leaderboards Service.
	 *
	 * PREFER THE UFUNCTION OVERLOAD AS OPPOSED TO THIS. THIS MAINLY EXISTS TO ALLOW LAMBDA BINDING THE HANDLER.
	 * (Dynamic delegates do not allow for that so... we autogen this one to make experimenting in CPP a bit faster).
	 * 
	 * @param UserSlot The Authenticated User Slot that is making this request.
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param Handler A callback that defines how to handle success, error and completion.
     * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
	 * @param OpHandle When made as part of an Operation, you can pass this in and it'll register the request with the operation automatically.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId). 
	 */
	void CPP_GetDetails(const FUserSlot& UserSlot, UGetDetailsRequest* Request, const FOnGetDetailsFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr) const;

		
	/**
	 * @brief Makes an authenticated request to the Put /object/leaderboards/{objectId}/swap endpoint of the Leaderboards Service.
	 *
	 * PREFER THE UFUNCTION OVERLOAD AS OPPOSED TO THIS. THIS MAINLY EXISTS TO ALLOW LAMBDA BINDING THE HANDLER.
	 * (Dynamic delegates do not allow for that so... we autogen this one to make experimenting in CPP a bit faster).
	 * 
	 * @param UserSlot The Authenticated User Slot that is making this request.
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param Handler A callback that defines how to handle success, error and completion.
     * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
	 * @param OpHandle When made as part of an Operation, you can pass this in and it'll register the request with the operation automatically.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId). 
	 */
	void CPP_PutSwap(const FUserSlot& UserSlot, UPutSwapRequest* Request, const FOnPutSwapFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr) const;


	
	/**
	 * @brief Makes a request to the Get /object/leaderboards/{objectId}/ranks endpoint of the Leaderboards Service.
	 *
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight. 
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", meta=(AdvancedDisplay="OpHandle", AutoCreateRefTerm="OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void GetRanks(UGetRanksRequest* Request, const FOnGetRanksSuccess& OnSuccess, const FOnGetRanksError& OnError, const FOnGetRanksComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle());

		
	/**
	 * @brief Makes a request to the Get /object/leaderboards/{objectId}/matches endpoint of the Leaderboards Service.
	 *
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight. 
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", meta=(AdvancedDisplay="OpHandle", AutoCreateRefTerm="OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void GetMatches(UGetMatchesRequest* Request, const FOnGetMatchesSuccess& OnSuccess, const FOnGetMatchesError& OnError, const FOnGetMatchesComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle());

		
	/**
	 * @brief Makes a request to the Put /object/leaderboards/{objectId}/entry endpoint of the Leaderboards Service.
	 *
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight. 
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", meta=(AdvancedDisplay="OpHandle", AutoCreateRefTerm="OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void PutEntry(UPutEntryRequest* Request, const FOnPutEntrySuccess& OnSuccess, const FOnPutEntryError& OnError, const FOnPutEntryComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle());

		
	/**
	 * @brief Makes a request to the Get /object/leaderboards/{objectId}/view endpoint of the Leaderboards Service.
	 *
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight. 
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", meta=(AdvancedDisplay="OpHandle", AutoCreateRefTerm="OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void GetView(UGetViewRequest* Request, const FOnGetViewSuccess& OnSuccess, const FOnGetViewError& OnError, const FOnGetViewComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle());


	
	/**
	 * @brief Makes an authenticated request to the Get /basic/leaderboards/list endpoint of the Leaderboards Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId).
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="OpHandle,CallingContext",AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void GetList(FUserSlot UserSlot, UBasicLeaderboardsGetListRequest* Request, const FOnBasicLeaderboardsGetListSuccess& OnSuccess, const FOnBasicLeaderboardsGetListError& OnError, const FOnBasicLeaderboardsGetListComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr);

		
	/**
	 * @brief Makes an authenticated request to the Get /basic/leaderboards/player endpoint of the Leaderboards Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId).
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="OpHandle,CallingContext",AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void GetPlayer(FUserSlot UserSlot, UGetPlayerRequest* Request, const FOnGetPlayerSuccess& OnSuccess, const FOnGetPlayerError& OnError, const FOnGetPlayerComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr);

		
	/**
	 * @brief Makes an authenticated request to the Get /basic/leaderboards/assignment endpoint of the Leaderboards Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId).
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="OpHandle,CallingContext",AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void BasicLeaderboardsGetAssignment(FUserSlot UserSlot, UBasicLeaderboardsGetAssignmentRequest* Request, const FOnBasicLeaderboardsGetAssignmentSuccess& OnSuccess, const FOnBasicLeaderboardsGetAssignmentError& OnError, const FOnBasicLeaderboardsGetAssignmentComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr);

		
	/**
	 * @brief Makes an authenticated request to the Get /basic/leaderboards/uid endpoint of the Leaderboards Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId).
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="OpHandle,CallingContext",AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void GetUid(FUserSlot UserSlot, UGetUidRequest* Request, const FOnGetUidSuccess& OnSuccess, const FOnGetUidError& OnError, const FOnGetUidComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr);

		
	/**
	 * @brief Makes an authenticated request to the Delete /object/leaderboards/{objectId}/entries endpoint of the Leaderboards Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId).
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="OpHandle,CallingContext",AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void DeleteEntries(FUserSlot UserSlot, UDeleteEntriesRequest* Request, const FOnDeleteEntriesSuccess& OnSuccess, const FOnDeleteEntriesError& OnError, const FOnDeleteEntriesComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr);

		
	/**
	 * @brief Makes an authenticated request to the Get /object/leaderboards/{objectId}/membership endpoint of the Leaderboards Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId).
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="OpHandle,CallingContext",AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void GetMembership(FUserSlot UserSlot, UGetMembershipRequest* Request, const FOnGetMembershipSuccess& OnSuccess, const FOnGetMembershipError& OnError, const FOnGetMembershipComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr);

		
	/**
	 * @brief Makes an authenticated request to the Get /object/leaderboards/{objectId}/partition endpoint of the Leaderboards Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId).
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="OpHandle,CallingContext",AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void GetPartition(FUserSlot UserSlot, UGetPartitionRequest* Request, const FOnGetPartitionSuccess& OnSuccess, const FOnGetPartitionError& OnError, const FOnGetPartitionComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr);

		
	/**
	 * @brief Makes an authenticated request to the Get /object/leaderboards/{objectId}/friends endpoint of the Leaderboards Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId).
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="OpHandle,CallingContext",AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void GetFriends(FUserSlot UserSlot, UGetFriendsRequest* Request, const FOnGetFriendsSuccess& OnSuccess, const FOnGetFriendsError& OnError, const FOnGetFriendsComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr);

		
	/**
	 * @brief Makes an authenticated request to the Post /object/leaderboards/{objectId}/ endpoint of the Leaderboards Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId).
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="OpHandle,CallingContext",AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void PostLeaderboards(FUserSlot UserSlot, UPostLeaderboardsRequest* Request, const FOnPostLeaderboardsSuccess& OnSuccess, const FOnPostLeaderboardsError& OnError, const FOnPostLeaderboardsComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr);

		
	/**
	 * @brief Makes an authenticated request to the Delete /object/leaderboards/{objectId}/ endpoint of the Leaderboards Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId).
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="OpHandle,CallingContext",AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void DeleteLeaderboards(FUserSlot UserSlot, UDeleteLeaderboardsRequest* Request, const FOnDeleteLeaderboardsSuccess& OnSuccess, const FOnDeleteLeaderboardsError& OnError, const FOnDeleteLeaderboardsComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr);

		
	/**
	 * @brief Makes an authenticated request to the Get /object/leaderboards/{objectId}/assignment endpoint of the Leaderboards Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId).
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="OpHandle,CallingContext",AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void ObjectLeaderboardsGetAssignment(FUserSlot UserSlot, UObjectLeaderboardsGetAssignmentRequest* Request, const FOnObjectLeaderboardsGetAssignmentSuccess& OnSuccess, const FOnObjectLeaderboardsGetAssignmentError& OnError, const FOnObjectLeaderboardsGetAssignmentComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr);

		
	/**
	 * @brief Makes an authenticated request to the Delete /object/leaderboards/{objectId}/assignment endpoint of the Leaderboards Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId).
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="OpHandle,CallingContext",AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void DeleteAssignment(FUserSlot UserSlot, UDeleteAssignmentRequest* Request, const FOnDeleteAssignmentSuccess& OnSuccess, const FOnDeleteAssignmentError& OnError, const FOnDeleteAssignmentComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr);

		
	/**
	 * @brief Makes an authenticated request to the Delete /object/leaderboards/{objectId}/entry endpoint of the Leaderboards Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId).
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="OpHandle,CallingContext",AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void DeleteEntry(FUserSlot UserSlot, UDeleteEntryRequest* Request, const FOnDeleteEntrySuccess& OnSuccess, const FOnDeleteEntryError& OnError, const FOnDeleteEntryComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr);

		
	/**
	 * @brief Makes an authenticated request to the Put /object/leaderboards/{objectId}/freeze endpoint of the Leaderboards Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId).
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="OpHandle,CallingContext",AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void PutFreeze(FUserSlot UserSlot, UPutFreezeRequest* Request, const FOnPutFreezeSuccess& OnSuccess, const FOnPutFreezeError& OnError, const FOnPutFreezeComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr);

		
	/**
	 * @brief Makes an authenticated request to the Get /object/leaderboards/{objectId}/details endpoint of the Leaderboards Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId).
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="OpHandle,CallingContext",AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void GetDetails(FUserSlot UserSlot, UGetDetailsRequest* Request, const FOnGetDetailsSuccess& OnSuccess, const FOnGetDetailsError& OnError, const FOnGetDetailsComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr);

		
	/**
	 * @brief Makes an authenticated request to the Put /object/leaderboards/{objectId}/swap endpoint of the Leaderboards Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId).
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="OpHandle,CallingContext",AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void PutSwap(FUserSlot UserSlot, UPutSwapRequest* Request, const FOnPutSwapSuccess& OnSuccess, const FOnPutSwapError& OnError, const FOnPutSwapComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr);
	

	
	/**
	 * @brief Makes a request to the Get /object/leaderboards/{objectId}/ranks endpoint of the Leaderboards Service.
	 *	 
	 * @param RetryConfig The retry config for this specific request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context -- used to query information about the request or to cancel it while it's in flight.	  
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", meta=(AutoCreateRefTerm="OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void GetRanksWithRetry(const FBeamRetryConfig& RetryConfig, UGetRanksRequest* Request, const FOnGetRanksSuccess& OnSuccess, const FOnGetRanksError& OnError, const FOnGetRanksComplete& OnComplete, FBeamRequestContext& OutRequestContext);
		
	/**
	 * @brief Makes a request to the Get /object/leaderboards/{objectId}/matches endpoint of the Leaderboards Service.
	 *	 
	 * @param RetryConfig The retry config for this specific request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context -- used to query information about the request or to cancel it while it's in flight.	  
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", meta=(AutoCreateRefTerm="OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void GetMatchesWithRetry(const FBeamRetryConfig& RetryConfig, UGetMatchesRequest* Request, const FOnGetMatchesSuccess& OnSuccess, const FOnGetMatchesError& OnError, const FOnGetMatchesComplete& OnComplete, FBeamRequestContext& OutRequestContext);
		
	/**
	 * @brief Makes a request to the Put /object/leaderboards/{objectId}/entry endpoint of the Leaderboards Service.
	 *	 
	 * @param RetryConfig The retry config for this specific request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context -- used to query information about the request or to cancel it while it's in flight.	  
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", meta=(AutoCreateRefTerm="OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void PutEntryWithRetry(const FBeamRetryConfig& RetryConfig, UPutEntryRequest* Request, const FOnPutEntrySuccess& OnSuccess, const FOnPutEntryError& OnError, const FOnPutEntryComplete& OnComplete, FBeamRequestContext& OutRequestContext);
		
	/**
	 * @brief Makes a request to the Get /object/leaderboards/{objectId}/view endpoint of the Leaderboards Service.
	 *	 
	 * @param RetryConfig The retry config for this specific request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context -- used to query information about the request or to cancel it while it's in flight.	  
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", meta=(AutoCreateRefTerm="OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void GetViewWithRetry(const FBeamRetryConfig& RetryConfig, UGetViewRequest* Request, const FOnGetViewSuccess& OnSuccess, const FOnGetViewError& OnError, const FOnGetViewComplete& OnComplete, FBeamRequestContext& OutRequestContext);

	
	/**
	 * @brief Makes an authenticated request to the Get /basic/leaderboards/list endpoint of the Leaderboards Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request.
	 * @param RetryConfig The retry config for this specific request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context -- used to query information about the request or to cancel it while it's in flight.
	 * @param CallingContext A UObject managed by the UWorld that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId). 
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="CallingContext", AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void GetListWithRetry(FUserSlot UserSlot, const FBeamRetryConfig& RetryConfig, UBasicLeaderboardsGetListRequest* Request, const FOnBasicLeaderboardsGetListSuccess& OnSuccess, const FOnBasicLeaderboardsGetListError& OnError, const FOnBasicLeaderboardsGetListComplete& OnComplete, FBeamRequestContext& OutRequestContext, const UObject* CallingContext = nullptr);
		
	/**
	 * @brief Makes an authenticated request to the Get /basic/leaderboards/player endpoint of the Leaderboards Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request.
	 * @param RetryConfig The retry config for this specific request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context -- used to query information about the request or to cancel it while it's in flight.
	 * @param CallingContext A UObject managed by the UWorld that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId). 
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="CallingContext", AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void GetPlayerWithRetry(FUserSlot UserSlot, const FBeamRetryConfig& RetryConfig, UGetPlayerRequest* Request, const FOnGetPlayerSuccess& OnSuccess, const FOnGetPlayerError& OnError, const FOnGetPlayerComplete& OnComplete, FBeamRequestContext& OutRequestContext, const UObject* CallingContext = nullptr);
		
	/**
	 * @brief Makes an authenticated request to the Get /basic/leaderboards/assignment endpoint of the Leaderboards Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request.
	 * @param RetryConfig The retry config for this specific request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context -- used to query information about the request or to cancel it while it's in flight.
	 * @param CallingContext A UObject managed by the UWorld that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId). 
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="CallingContext", AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void BasicLeaderboardsGetAssignmentWithRetry(FUserSlot UserSlot, const FBeamRetryConfig& RetryConfig, UBasicLeaderboardsGetAssignmentRequest* Request, const FOnBasicLeaderboardsGetAssignmentSuccess& OnSuccess, const FOnBasicLeaderboardsGetAssignmentError& OnError, const FOnBasicLeaderboardsGetAssignmentComplete& OnComplete, FBeamRequestContext& OutRequestContext, const UObject* CallingContext = nullptr);
		
	/**
	 * @brief Makes an authenticated request to the Get /basic/leaderboards/uid endpoint of the Leaderboards Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request.
	 * @param RetryConfig The retry config for this specific request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context -- used to query information about the request or to cancel it while it's in flight.
	 * @param CallingContext A UObject managed by the UWorld that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId). 
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="CallingContext", AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void GetUidWithRetry(FUserSlot UserSlot, const FBeamRetryConfig& RetryConfig, UGetUidRequest* Request, const FOnGetUidSuccess& OnSuccess, const FOnGetUidError& OnError, const FOnGetUidComplete& OnComplete, FBeamRequestContext& OutRequestContext, const UObject* CallingContext = nullptr);
		
	/**
	 * @brief Makes an authenticated request to the Delete /object/leaderboards/{objectId}/entries endpoint of the Leaderboards Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request.
	 * @param RetryConfig The retry config for this specific request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context -- used to query information about the request or to cancel it while it's in flight.
	 * @param CallingContext A UObject managed by the UWorld that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId). 
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="CallingContext", AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void DeleteEntriesWithRetry(FUserSlot UserSlot, const FBeamRetryConfig& RetryConfig, UDeleteEntriesRequest* Request, const FOnDeleteEntriesSuccess& OnSuccess, const FOnDeleteEntriesError& OnError, const FOnDeleteEntriesComplete& OnComplete, FBeamRequestContext& OutRequestContext, const UObject* CallingContext = nullptr);
		
	/**
	 * @brief Makes an authenticated request to the Get /object/leaderboards/{objectId}/membership endpoint of the Leaderboards Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request.
	 * @param RetryConfig The retry config for this specific request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context -- used to query information about the request or to cancel it while it's in flight.
	 * @param CallingContext A UObject managed by the UWorld that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId). 
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="CallingContext", AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void GetMembershipWithRetry(FUserSlot UserSlot, const FBeamRetryConfig& RetryConfig, UGetMembershipRequest* Request, const FOnGetMembershipSuccess& OnSuccess, const FOnGetMembershipError& OnError, const FOnGetMembershipComplete& OnComplete, FBeamRequestContext& OutRequestContext, const UObject* CallingContext = nullptr);
		
	/**
	 * @brief Makes an authenticated request to the Get /object/leaderboards/{objectId}/partition endpoint of the Leaderboards Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request.
	 * @param RetryConfig The retry config for this specific request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context -- used to query information about the request or to cancel it while it's in flight.
	 * @param CallingContext A UObject managed by the UWorld that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId). 
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="CallingContext", AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void GetPartitionWithRetry(FUserSlot UserSlot, const FBeamRetryConfig& RetryConfig, UGetPartitionRequest* Request, const FOnGetPartitionSuccess& OnSuccess, const FOnGetPartitionError& OnError, const FOnGetPartitionComplete& OnComplete, FBeamRequestContext& OutRequestContext, const UObject* CallingContext = nullptr);
		
	/**
	 * @brief Makes an authenticated request to the Get /object/leaderboards/{objectId}/friends endpoint of the Leaderboards Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request.
	 * @param RetryConfig The retry config for this specific request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context -- used to query information about the request or to cancel it while it's in flight.
	 * @param CallingContext A UObject managed by the UWorld that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId). 
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="CallingContext", AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void GetFriendsWithRetry(FUserSlot UserSlot, const FBeamRetryConfig& RetryConfig, UGetFriendsRequest* Request, const FOnGetFriendsSuccess& OnSuccess, const FOnGetFriendsError& OnError, const FOnGetFriendsComplete& OnComplete, FBeamRequestContext& OutRequestContext, const UObject* CallingContext = nullptr);
		
	/**
	 * @brief Makes an authenticated request to the Post /object/leaderboards/{objectId}/ endpoint of the Leaderboards Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request.
	 * @param RetryConfig The retry config for this specific request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context -- used to query information about the request or to cancel it while it's in flight.
	 * @param CallingContext A UObject managed by the UWorld that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId). 
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="CallingContext", AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void PostLeaderboardsWithRetry(FUserSlot UserSlot, const FBeamRetryConfig& RetryConfig, UPostLeaderboardsRequest* Request, const FOnPostLeaderboardsSuccess& OnSuccess, const FOnPostLeaderboardsError& OnError, const FOnPostLeaderboardsComplete& OnComplete, FBeamRequestContext& OutRequestContext, const UObject* CallingContext = nullptr);
		
	/**
	 * @brief Makes an authenticated request to the Delete /object/leaderboards/{objectId}/ endpoint of the Leaderboards Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request.
	 * @param RetryConfig The retry config for this specific request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context -- used to query information about the request or to cancel it while it's in flight.
	 * @param CallingContext A UObject managed by the UWorld that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId). 
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="CallingContext", AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void DeleteLeaderboardsWithRetry(FUserSlot UserSlot, const FBeamRetryConfig& RetryConfig, UDeleteLeaderboardsRequest* Request, const FOnDeleteLeaderboardsSuccess& OnSuccess, const FOnDeleteLeaderboardsError& OnError, const FOnDeleteLeaderboardsComplete& OnComplete, FBeamRequestContext& OutRequestContext, const UObject* CallingContext = nullptr);
		
	/**
	 * @brief Makes an authenticated request to the Get /object/leaderboards/{objectId}/assignment endpoint of the Leaderboards Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request.
	 * @param RetryConfig The retry config for this specific request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context -- used to query information about the request or to cancel it while it's in flight.
	 * @param CallingContext A UObject managed by the UWorld that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId). 
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="CallingContext", AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void ObjectLeaderboardsGetAssignmentWithRetry(FUserSlot UserSlot, const FBeamRetryConfig& RetryConfig, UObjectLeaderboardsGetAssignmentRequest* Request, const FOnObjectLeaderboardsGetAssignmentSuccess& OnSuccess, const FOnObjectLeaderboardsGetAssignmentError& OnError, const FOnObjectLeaderboardsGetAssignmentComplete& OnComplete, FBeamRequestContext& OutRequestContext, const UObject* CallingContext = nullptr);
		
	/**
	 * @brief Makes an authenticated request to the Delete /object/leaderboards/{objectId}/assignment endpoint of the Leaderboards Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request.
	 * @param RetryConfig The retry config for this specific request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context -- used to query information about the request or to cancel it while it's in flight.
	 * @param CallingContext A UObject managed by the UWorld that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId). 
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="CallingContext", AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void DeleteAssignmentWithRetry(FUserSlot UserSlot, const FBeamRetryConfig& RetryConfig, UDeleteAssignmentRequest* Request, const FOnDeleteAssignmentSuccess& OnSuccess, const FOnDeleteAssignmentError& OnError, const FOnDeleteAssignmentComplete& OnComplete, FBeamRequestContext& OutRequestContext, const UObject* CallingContext = nullptr);
		
	/**
	 * @brief Makes an authenticated request to the Delete /object/leaderboards/{objectId}/entry endpoint of the Leaderboards Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request.
	 * @param RetryConfig The retry config for this specific request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context -- used to query information about the request or to cancel it while it's in flight.
	 * @param CallingContext A UObject managed by the UWorld that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId). 
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="CallingContext", AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void DeleteEntryWithRetry(FUserSlot UserSlot, const FBeamRetryConfig& RetryConfig, UDeleteEntryRequest* Request, const FOnDeleteEntrySuccess& OnSuccess, const FOnDeleteEntryError& OnError, const FOnDeleteEntryComplete& OnComplete, FBeamRequestContext& OutRequestContext, const UObject* CallingContext = nullptr);
		
	/**
	 * @brief Makes an authenticated request to the Put /object/leaderboards/{objectId}/freeze endpoint of the Leaderboards Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request.
	 * @param RetryConfig The retry config for this specific request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context -- used to query information about the request or to cancel it while it's in flight.
	 * @param CallingContext A UObject managed by the UWorld that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId). 
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="CallingContext", AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void PutFreezeWithRetry(FUserSlot UserSlot, const FBeamRetryConfig& RetryConfig, UPutFreezeRequest* Request, const FOnPutFreezeSuccess& OnSuccess, const FOnPutFreezeError& OnError, const FOnPutFreezeComplete& OnComplete, FBeamRequestContext& OutRequestContext, const UObject* CallingContext = nullptr);
		
	/**
	 * @brief Makes an authenticated request to the Get /object/leaderboards/{objectId}/details endpoint of the Leaderboards Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request.
	 * @param RetryConfig The retry config for this specific request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context -- used to query information about the request or to cancel it while it's in flight.
	 * @param CallingContext A UObject managed by the UWorld that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId). 
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="CallingContext", AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void GetDetailsWithRetry(FUserSlot UserSlot, const FBeamRetryConfig& RetryConfig, UGetDetailsRequest* Request, const FOnGetDetailsSuccess& OnSuccess, const FOnGetDetailsError& OnError, const FOnGetDetailsComplete& OnComplete, FBeamRequestContext& OutRequestContext, const UObject* CallingContext = nullptr);
		
	/**
	 * @brief Makes an authenticated request to the Put /object/leaderboards/{objectId}/swap endpoint of the Leaderboards Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request.
	 * @param RetryConfig The retry config for this specific request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context -- used to query information about the request or to cancel it while it's in flight.
	 * @param CallingContext A UObject managed by the UWorld that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId). 
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="CallingContext", AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void PutSwapWithRetry(FUserSlot UserSlot, const FBeamRetryConfig& RetryConfig, UPutSwapRequest* Request, const FOnPutSwapSuccess& OnSuccess, const FOnPutSwapError& OnError, const FOnPutSwapComplete& OnComplete, FBeamRequestContext& OutRequestContext, const UObject* CallingContext = nullptr);
};