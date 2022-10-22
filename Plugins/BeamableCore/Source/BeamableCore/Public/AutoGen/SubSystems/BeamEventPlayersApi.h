

#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBackend.h"

#include "EventPlayers/GetEventPlayersRequest.h"
#include "EventPlayers/ObjectEventPlayersPostClaimRequest.h"
#include "EventPlayers/PutScoreRequest.h"

#include "BeamEventPlayersApi.generated.h"


/**
 * Subsystem containing request calls for the EventPlayers service.
 */
UCLASS(BlueprintType)
class BEAMABLECORE_API UBeamEventPlayersApi : public UEngineSubsystem
{
private:
	GENERATED_BODY()
	/** @brief Initializes the auto-increment Id and binds the ExecuteRequestDelegate to DefaultExecuteRequestImpl  */
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	/** Cleans up the system.  */
	virtual void Deinitialize() override;

	UPROPERTY()
	UBeamBackend* Backend;

	
	/**
	 * @brief Private implementation that all overloaded BP UFunctions call.	  
	 */
	void BP_GetEventPlayersImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, FBeamConnectivity& ConnectivityStatus, UGetEventPlayersRequest* RequestData,
	                                const FOnGetEventPlayersSuccess& OnSuccess, const FOnGetEventPlayersError& OnError, const FOnGetEventPlayersComplete& OnComplete,
	                                int64& OutRequestId) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_GetEventPlayersImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, FBeamConnectivity& ConnectivityStatus, UGetEventPlayersRequest* RequestData,
	                                 const FOnGetEventPlayersFullResponse& Handler) const;

		
	/**
	 * @brief Private implementation that all overloaded BP UFunctions call.	  
	 */
	void BP_PostClaimImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, FBeamConnectivity& ConnectivityStatus, UObjectEventPlayersPostClaimRequest* RequestData,
	                                const FOnObjectEventPlayersPostClaimSuccess& OnSuccess, const FOnObjectEventPlayersPostClaimError& OnError, const FOnObjectEventPlayersPostClaimComplete& OnComplete,
	                                int64& OutRequestId) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_PostClaimImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, FBeamConnectivity& ConnectivityStatus, UObjectEventPlayersPostClaimRequest* RequestData,
	                                 const FOnObjectEventPlayersPostClaimFullResponse& Handler) const;

		
	/**
	 * @brief Private implementation that all overloaded BP UFunctions call.	  
	 */
	void BP_PutScoreImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, FBeamConnectivity& ConnectivityStatus, UPutScoreRequest* RequestData,
	                                const FOnPutScoreSuccess& OnSuccess, const FOnPutScoreError& OnError, const FOnPutScoreComplete& OnComplete,
	                                int64& OutRequestId) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_PutScoreImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, FBeamConnectivity& ConnectivityStatus, UPutScoreRequest* RequestData,
	                                 const FOnPutScoreFullResponse& Handler) const;


	

public:
	
	/** Used by a helper blueprint node so that you can easily chain requests in BP-land. */
	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly)
	static UBeamEventPlayersApi* GetSelf() { return GEngine->GetEngineSubsystem<UBeamEventPlayersApi>(); }

	
	/**
	 * @brief Makes a request to the Get /object/event-players/{objectId}/ endpoint of the EventPlayers Service.
	 *
	 * PREFER THE UFUNCTION OVERLOAD AS OPPOSED TO THIS. THIS MAINLY EXISTS TO ALLOW LAMBDA BINDING THE HANDLER.
	 * (Dynamic delegates do not allow for that so... we autogen this one to make experimenting in CPP a bit faster and for whenever you need to capture variables).
	 * 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param Handler A callback that defines how to handle success, error and completion. 
	 */
	void CPP_GetEventPlayers(UGetEventPlayersRequest* Request, const FOnGetEventPlayersFullResponse& Handler) const;

		
	/**
	 * @brief Makes a request to the Post /object/event-players/{objectId}/claim endpoint of the EventPlayers Service.
	 *
	 * PREFER THE UFUNCTION OVERLOAD AS OPPOSED TO THIS. THIS MAINLY EXISTS TO ALLOW LAMBDA BINDING THE HANDLER.
	 * (Dynamic delegates do not allow for that so... we autogen this one to make experimenting in CPP a bit faster and for whenever you need to capture variables).
	 * 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param Handler A callback that defines how to handle success, error and completion. 
	 */
	void CPP_PostClaim(UObjectEventPlayersPostClaimRequest* Request, const FOnObjectEventPlayersPostClaimFullResponse& Handler) const;

		
	/**
	 * @brief Makes a request to the Put /object/event-players/{objectId}/score endpoint of the EventPlayers Service.
	 *
	 * PREFER THE UFUNCTION OVERLOAD AS OPPOSED TO THIS. THIS MAINLY EXISTS TO ALLOW LAMBDA BINDING THE HANDLER.
	 * (Dynamic delegates do not allow for that so... we autogen this one to make experimenting in CPP a bit faster and for whenever you need to capture variables).
	 * 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param Handler A callback that defines how to handle success, error and completion. 
	 */
	void CPP_PutScore(UPutScoreRequest* Request, const FOnPutScoreFullResponse& Handler) const;


	

	
	/**
	 * @brief Makes a request to the Get /object/event-players/{objectId}/ endpoint of the EventPlayers Service.
	 *
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestId The Request Id -- used to query information about the request or to cancel it while it's in flight. 
	 */
	UFUNCTION(BlueprintCallable, Category="Beam|APIs|EventPlayers", meta=(AutoCreateRefTerm="OnSuccess,OnError,OnComplete"))
	void GetEventPlayers(UGetEventPlayersRequest* Request, const FOnGetEventPlayersSuccess& OnSuccess, const FOnGetEventPlayersError& OnError, const FOnGetEventPlayersComplete& OnComplete,
								 int64& OutRequestId);

		
	/**
	 * @brief Makes a request to the Post /object/event-players/{objectId}/claim endpoint of the EventPlayers Service.
	 *
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestId The Request Id -- used to query information about the request or to cancel it while it's in flight. 
	 */
	UFUNCTION(BlueprintCallable, Category="Beam|APIs|EventPlayers", meta=(AutoCreateRefTerm="OnSuccess,OnError,OnComplete"))
	void PostClaim(UObjectEventPlayersPostClaimRequest* Request, const FOnObjectEventPlayersPostClaimSuccess& OnSuccess, const FOnObjectEventPlayersPostClaimError& OnError, const FOnObjectEventPlayersPostClaimComplete& OnComplete,
								 int64& OutRequestId);

		
	/**
	 * @brief Makes a request to the Put /object/event-players/{objectId}/score endpoint of the EventPlayers Service.
	 *
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestId The Request Id -- used to query information about the request or to cancel it while it's in flight. 
	 */
	UFUNCTION(BlueprintCallable, Category="Beam|APIs|EventPlayers", meta=(AutoCreateRefTerm="OnSuccess,OnError,OnComplete"))
	void PutScore(UPutScoreRequest* Request, const FOnPutScoreSuccess& OnSuccess, const FOnPutScoreError& OnError, const FOnPutScoreComplete& OnComplete,
								 int64& OutRequestId);


		
};
