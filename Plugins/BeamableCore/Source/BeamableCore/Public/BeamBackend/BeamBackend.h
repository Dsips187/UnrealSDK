// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HttpManager.h"


#include "BeamEnvironment.h"

#include "BeamBackend/RequestType.h"
#include "BeamBackend/BeamFullResponse.h"

#include "UserSlots/BeamUserSlots.h"

#include "BeamBackend.generated.h"


class IBeamBaseRequestInterface;

/**
 * @brief Holds data regarding internet connectivity status for Beamable. 
 */
USTRUCT(BlueprintType)
struct FBeamConnectivity
{
	GENERATED_BODY()

	/**
	 * @brief Whether or not the last request was successful (true) or failed due to connectivity issues (false).
	 */
	UPROPERTY(BlueprintReadOnly)
	bool IsConnected;

	/**
	 * @brief The time in ticks since the last successful request occurred.
	 */
	UPROPERTY(BlueprintReadOnly)
	int64 LastTimeSinceSuccessfulRequest;
};

/**
 * @brief Semantic separation for longs representing a Beamable Request Id.
 * Every request sent out from any of the UBeam***Api subsystems gets one of these.
 */
typedef int64 FBeamRequestId;


/**
 * @brief Shorter name for Unreal's HttpRequest struct.
 */
typedef TSharedRef<IHttpRequest, ESPMode::ThreadSafe> TUnrealRequest;

/**
 * @brief Shorter name for the pointer to Unreal's HttpRequest struct.
 */
typedef TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> TUnrealRequestPtr;

/**
 * @brief Shorter name for unreal's request status.
 */
typedef EHttpRequestStatus::Type TUnrealRequestStatus;

/**
 * @brief Semantic separation for the Functor declaration representing a Beamable Request Processor.
 * Exist to make explicit any assumptions we make about passing parameters to the request processing callback.
 */
typedef TFunction<void (FHttpRequestPtr request, FHttpResponsePtr response, bool success)> FBeamRequestProcessor;

/**
 * @brief Handle to an Enqueued Request that needs to be retried.
 */
struct FRequestToRetry
{
	/**
	 * @brief The unique request id.
	 */
	FBeamRequestId RequestId = 0;	

	/**
	 * @brief Whether or not the request was made with a blueprint compatible handler. 
	 */
	int32 IsBlueprintCompatible;

	/**
	 * @brief The HTTP status code.
	 */
	int32 ResponseCode;

	/**
	 * @brief The realm the request was targeted to.
	 */
	FBeamRealmHandle RealmHandle;

	/**
	 * @brief The authentication token used in the request, if any.
	 */
	FBeamAuthToken AuthToken;	

	/**
	 * @brief A custom error code independent of the HTTP status code.
	 */
	FString ErrorCode;

	friend bool operator==(const FRequestToRetry& Lhs, const FRequestToRetry& RHS)
	{
		return Lhs.RequestId == RHS.RequestId
			&& Lhs.IsBlueprintCompatible == RHS.IsBlueprintCompatible
			&& Lhs.ResponseCode == RHS.ResponseCode
			&& Lhs.RealmHandle == RHS.RealmHandle
			&& Lhs.AuthToken == RHS.AuthToken;
	}

	friend bool operator!=(const FRequestToRetry& Lhs, const FRequestToRetry& RHS)
	{
		return !(Lhs == RHS);
	}
};

/**
 * @brief Data needed to decided when enough time has passed that we should retry again.
 */
struct FProcessingRequestRetry
{
	/**
	 * @brief The handle defining which request we are processing.
	 */
	FRequestToRetry RequestToRetry;

	/**
	 * @brief How long (in seconds) should we wait before trying the request again.
	 */
	float TimeToWait;

	/**
	 * @brief How long (in seconds) have we waited for this retry.
	 */
	float AccumulatedTime;
};


DECLARE_DELEGATE_TwoParams(FBeamMakeRequestDelegate, int64 /*ActiveRequestId*/, FBeamConnectivity& /*Connectivity*/);

DECLARE_DELEGATE_TwoParams(FGlobalRequestErrorCodeHandler, const FBeamRequestContext&, const FBeamErrorResponse&);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FGlobalRequestErrorHandler, const FBeamRequestContext&, RequestContext, const FBeamErrorResponse&, Error);

DECLARE_MULTICAST_DELEGATE_ThreeParams(FGlobalConnectivityChangedCodeHandler, const FBeamRequestContext&, const FRequestType&, const bool);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FGlobalConnectivityChangedHandler, const FBeamRequestContext&, RequestContext, const FRequestType&, FailedRequestType, const bool, bConnected);

/**
* @brief Subsystems that associate data with in-flight requests and require guarantees that those request objects stay alive need to tell the backend subsystem which
* requests are still in use by them to guarantee the requests/response data associated with the request won't be cleaned up.
*/
DECLARE_DYNAMIC_DELEGATE_OneParam(FTickOnBackendCleanUp, TArray<int64>&, OutUsingRequestIds);

/**
* @brief Subsystems that associate data with in-flight requests and require and want to react to the fact that a request was completed can register themselves here.
*/
DECLARE_DYNAMIC_DELEGATE_OneParam(FTickOnRequestIdCompleted, int64, CompletedRequestId);

/**
 * 
 */
UCLASS(NotBlueprintable)
class BEAMABLECORE_API UBeamBackend : public UEngineSubsystem
{
	GENERATED_BODY()

	// Forward declaration of the Automated Testing class so we can make it a friend and make it easier to test internal state.
	// Also, mock request types declared for Automated Testing purposes.
	friend class FBeamBackendSpec;
	friend class UBeamRequestTracker;
	friend class FBeamRequestTrackerSpec;

private:
	/**
	 * @brief  Just an Auto-Increment ID of each running request.
	 */
	long volatile* InFlightRequestId;

	/**
	 * @brief Delegate handle to the tick function of the UBeamBackend sub-system used to update and handle retry requests.
	 */
	FTSTicker::FDelegateHandle RetryQueueTickHandle;

	/**
	 * @brief Delegate handle to the tick function of the UBeamBackend sub-system used to clean up completed requests.
	 */
	FTSTicker::FDelegateHandle CleanupRequestsTickHandle;

	/**
	 * @brief Queue of failed requests that we must retry.
	 */
	TQueue<FRequestToRetry> EnqueuedRetries;

	/**
	 * @brief Delegates that other subsystems register to tell UBeamBackend of RequestIds that they are using.
	 * This is called to give subsystems an opportunity to clean up their internal state that relates to Requests.
	 * The subsystems should fill out the given array with any RequestIds that they are still using and don't want to be cleaned up. 
	 */
	TArray<FTickOnBackendCleanUp> TickOnBackendCleanUpDelegates;

	/**
	 * @brief Delegates that other subsystems register to react whenever a request is completed.
	 * The guarantees here is that OnComplete will have run in all cases for all types of request.
	 */
	TArray<FTickOnRequestIdCompleted> TickOnRequestIdCompletedDelegates;
	

	template <class TRequestData>
	static void StaticCheckForRequestType();

	template <class TResponseData>
	static void StaticCheckForResponseType();
	
	void TryTriggerRequestCompleteDelegates(const int64& RequestId);
	
	bool TickRetryQueue(float DeltaTime);	

	bool TickCleanUp(float deltaTime);


public:
	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly)
	static UBeamBackend* GetSelf() { return GEngine->GetEngineSubsystem<UBeamBackend>(); }

	static const FString HEADER_CONTENT_TYPE;
	static const FString HEADER_ACCEPT;
	static const FString HEADER_VALUE_ACCEPT_CONTENT_TYPE;
	static const FString HEADER_AUTHORIZATION;
	static const FString HEADER_REQUEST_SCOPE;
	static const FString HEADER_VALUE_AUTHORIZATION;
	static const FString HEADER_CLIENT_ID;
	static const FString HEADER_PROJECT_ID;

	/**
	 * @brief List of error codes that mean we should re-auth and automatically make the request again.
	 */
	const static TArray<FString> AUTH_ERROR_CODE_RETRY_ALLOWED;

	

	/**
	 * @brief Pointer to the UBeamEnvironment Engine Subsystem. Gathers which platform we are running as well as the Beamable SDK version.
	 */
	UPROPERTY()
	UBeamEnvironment* BeamEnvironment;

	/**
	 * @brief Pointer to the UBeamUserSlot Engine Subsystem.
	 * We use this to fetch valid authenticated user data for the user making the request. 
	 */
	UPROPERTY()
	UBeamUserSlots* BeamUserSlots;


	/** @brief Initializes the subsystem.  */
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	/** Cleans up the system.  */
	virtual void Deinitialize() override;

	/*
	  _____                            _         __  _____                                      
	 |  __ \                          | |       / / |  __ \                                     
	 | |__) |___  __ _ _   _  ___  ___| |_     / /  | |__) |___  ___ _ __   ___  _ __  ___  ___ 
	 |  _  // _ \/ _` | | | |/ _ \/ __| __|   / /   |  _  // _ \/ __| '_ \ / _ \| '_ \/ __|/ _ \
	 | | \ \  __/ (_| | |_| |  __/\__ \ |_   / /    | | \ \  __/\__ \ |_) | (_) | | | \__ \  __/
	 |_|  \_\___|\__, |\__,_|\___||___/\__| /_/     |_|  \_\___||___/ .__/ \___/|_| |_|___/\___|
					| |                                             | |                         
					|_|                                             |_|                         	                                                                               
	*/


	/**
	 * @brief A delegate wrapper so we can easily replace the code that sends the request by assertions over the request data. 
	 */
	FBeamMakeRequestDelegate ExecuteRequestDelegate;

	/**
	 * @brief When set to true, the Global Request Error Handlers will run IN ADDITION to the one provided at the callsite. 
	 */
	UPROPERTY(BlueprintReadOnly, Category="Beam|Config")
	bool AlwaysRunGlobalHandlers;

	/**
	 * @brief When set to true, we will log all success responses regardless of whether or not you passed in a handler. 
	 */
	UPROPERTY(BlueprintReadOnly, Category="Beam|Config")
	bool AlwaysLogSuccessResponses;

	/**
	 * @brief When set to true, we will log all error responses regardless of whether or not you passed in a handler. 
	 */
	UPROPERTY(BlueprintReadOnly, Category="Beam|Config")
	bool AlwaysLogErrorResponses;

	/**
	 * @brief When set to true, we will log all completed requests. 
	 */
	UPROPERTY(BlueprintReadOnly, Category="Beam|Config")
	bool AlwaysLogCompleteResponses;

	/**
	 * @brief A global request handler delegate that'll be called 
	 */
	UPROPERTY(BlueprintAssignable, Category="Beam|Config")
	FGlobalRequestErrorHandler GlobalRequestErrorHandler;

	/**
	 * \copydoc GlobalRequestErrorHandler	
	 * @brief Another global request handler --- this one can be used to bind lambdas from code. Use the other handler if you can.	 
	 */
	FGlobalRequestErrorCodeHandler GlobalRequestErrorCodeHandler;

	/**
	 * @brief Tracking of all requests generated by the CreateUnrealRequest and went through the pipeline of PrepareBeamableRequest methods.
	 */
	TMap<FBeamRequestId, TUnrealRequestPtr> InFlightRequests;

	/**
	 * @brief Tracking of all request ids that were cancelled by the user.
	 * In BP-land, a cancelled request will simply discard it's response and call OnComplete.
	 * You can use IsRequestCancelled(RequestId) during the callback to handle cancelled requests.
	 *
	 * In Code, a cancelled request will also discard it's response, but the callback will be the same. The FullResponse has a
	 * property you can read that determines whether the request was cancelled or not.
	 */
	TArray<FBeamRequestId> InFlightRequestsCancelled;

	/**
	 * @brief Tracking of all request contexts used to send out Beamable requests. 
	 */
	TMap<FBeamRequestId, FBeamRequestContext> InFlightRequestContexts;

	/**
	 * @brief When we create a new request, authenticated or otherwise, we store it's RequestData object here.
	 * When it and WaitHandles that depend on it are completed, we remove it from here.
	 */
	UPROPERTY(BlueprintReadOnly, Category="Beam")
	TMap<FBeamRequestContext, TScriptInterface<IBeamBaseRequestInterface>> InFlightRequestData;

	/**
	 * @brief When we create a new request, authenticated or otherwise, we store it's deserialized response object here.
	 * When it and WaitHandles that depend on it are completed, we remove it from here.
	 * TODO: Code gen all possible responses with this interface (IBeamBaseResponseBodyInterface) being implemented and then change it here.
	 */
	UPROPERTY(BlueprintReadOnly, Category="Beam")
	TMap<FBeamRequestContext, UObject*> InFlightResponseBodyData;

	/**
	 * @brief When we create a new request, authenticated or otherwise, we store it's deserialized error object here.
	 * When it and WaitHandles that depend on it are completed, we remove it from here.	 
	 */
	UPROPERTY(BlueprintReadOnly, Category="Beam")
	TMap<FBeamRequestContext, FBeamErrorResponse> InFlightResponseErrorData;

	/**
	 * @brief Map of @see {FBeamRequestId} to the number of times a request with that id failed. Used to do exponential back-off.
	 */
	TMap<FBeamRequestId, int> InFlightFailureCount;

	/**
	 * @brief Tracking of all requests that failed and have started processing.
	 * Processing is just waiting for the correct amount of time, before actually trying again.
	 */
	TMap<FBeamRequestId, FProcessingRequestRetry> InFlightProcessingRequests;


	/**
	 *  @brief Used only as delegate set in ExecuteRequestDelegate.
	 *  When testing, this is [optionally] swapped out so we can assert the state of the TUnrealRequest instance that would be sent out.
	 *  
	 */
	UFUNCTION()
	void DefaultExecuteRequestImpl(int64 ActiveRequestId, FBeamConnectivity& Connectivity);

	/**
	 * @brief Creates a request and prepares it to be sent out. This does not bind the lambda --- see any auto-generated API to understand how to manually make
	 * a beamable request.
	 * 
	 * @tparam TRequestData A type that implements the FBeamBaseRequest struct.
	 * @param OutRequestId  The RequestId assigned to the returned TUnrealRequest.
	 * @param TargetRealm The Realm with which we are communicating with.
	 * @param RetryConfig The Retry Configuration for this request. 
	 * @param RequestData An instance of the request type.
	 * 
	 * @return A TUnrealRequest object that will be tracked by UBeamBackend.
	 */
	template <class TRequestData>
	TUnrealRequestPtr CreateRequest(int64& OutRequestId, const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const TRequestData* RequestData);

	/**
	 * @brief Creates an authenticated request and prepares it to be sent out.
	 * This does not bind the lambda --- see any auto-generated API to understand how to manually make a beamable request.
	 * 
	 * @tparam TRequestData A type that implements the FBeamBaseRequest struct.
	 * @param OutRequestId  The RequestId assigned to the returned TUnrealRequest.
	 * @param TargetRealm The Realm with which we are communicating with.
	 * @param RetryConfig The Retry Configuration for this request.
	 * @param AuthToken An AuthenticationToken to be used to make the request.
	 * @param RequestData An instance of the request type.
	 * 
	 * @return A TUnrealRequest object that will be tracked by UBeamBackend.
	 */
	template <typename TRequestData>
	TUnrealRequestPtr CreateAuthenticatedRequest(int64& OutRequestId, const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken,
	                                             const TRequestData* RequestData);

	/**
	 * @brief Creates a TUnrealRequest that is tied to a specific InFlightRequestId.
	 * You need to manually call the PrepareBeamableRequestXXX functions and then attach a function generated from one of the MakeXXXRequestProcessor
	 * for this to work properly.
	 *
	 * Better to call the CreateRequest and CreateAuthenticatedRequestFunctions and then attaching the appropriate MakeXXXRequestProcessor manually.
	 * You can look at any of the auto-generated APIs to see what this looks like.
	 * 
	 * @param OutRequestId  The RequestId assigned to the returned TUnrealRequest.
	 * @param RetryConfig The Retry Configuration for this request.
	 * 
	 * @return A TUnrealRequest object that will be tracked by UBeamBackend.
	 */
	TUnrealRequestPtr CreateUnpreparedRequest(int64& OutRequestId, const FBeamRetryConfig& RetryConfig);

	/**
	 * @brief This is mainly used in Unit tests where we want to build the request and not send it.
	 * However, if a request is ever created manually by a user (not via one of our API Subsystems) and never sent, they need to call this otherwise
	 * they'll "leak" some memory (the data associated with the request here will never be cleared).
	 * 
	 * @param RequestId The RequestId of the request you wish to discard.
	 */
	UFUNCTION()
	void DiscardUnsentRequest(const int64& RequestId);

	/**
	 * @brief This will tell the BeamBackend to ignore the result of this request if it was sent but has not returned yet.
	 * If the request was not sent, it'll simply discard the unsent request instead.
	 * 
	 * @param RequestId The RequestId of the request you wish to cancel.
	 */
	UFUNCTION(BlueprintCallable, Category="Beam")
	void CancelRequest(int64 RequestId);

	/**
	 * @brief This will check and see if the request was cancelled and is awaiting cancellation.
	 * This does not track inactive request ids (that have been discard and/or completed). This is only valid while a
	 * request is in-fact in flight and during it's callback executions.
	 */
	UFUNCTION(BlueprintGetter, Category="Beam")
	bool IsRequestCancelled(int64 RequestId) const;

	/**
	 * @brief Gets the number of times this request failed.
	 * Can be used to change UI in order to allow users to cancel out of a popup after a certain amount of retries, for example.
	 * 
	 * @param RequestId The RequestId of the request.
	 * @return The number of times this request has failed.
	 */
	UFUNCTION(BlueprintGetter, Category="Beam")
	int GetRequestFailureCount(int64 RequestId) const;

	/**
	 * @brief Prepares an TUnrealRequest using data from a FBeamRealmHandle and an FBeamAuthToken by setting up Beamable's custom request headers.
	 * @param RealmHandle A RealmHandle describing which realm this request is talking too.
	 * @param UnrealRequest The actual HttpRequest we are configuring to send out through the Unreal Http Module.
	 */
	static void PrepareBeamableRequestToRealm(const TUnrealRequestPtr& UnrealRequest, const FBeamRealmHandle& RealmHandle);

	/**
	 * @brief Prepares an TUnrealRequest using data from a FBeamRealmHandle and an FBeamAuthToken by setting up a JWT Authentication header.
	 * @param RealmHandle A RealmHandle describing which realm this request is talking too.
	 * @param AuthToken An AuthToken to configure the authentication data required for the request.
	 * @param UnrealRequest The actual HttpRequest we are configuring to send out through the Unreal Http Module. 
	 */
	static void PrepareBeamableRequestToRealmWithAuthToken(const TUnrealRequestPtr& UnrealRequest, const FBeamRealmHandle& RealmHandle, const FBeamAuthToken& AuthToken);

	/**
	 * @brief Prepares an TUnrealRequest using any UStruct containing the data (route and body params) we need to make the request.
	 * @tparam TRequestData A type that implements the FBeamBaseRequest struct.
	 * @param RequestData An instance of the request type.
	 * @param Request The actual HttpRequest we are configuring to send out through the Unreal Http Module.
	 * @param TargetBeamableUrl The target beamable URL --- typically from the current UBeamEnvironment.
	 */
	template <typename TRequestData>
	void PrepareBeamableRequestVerbRouteBody(const TUnrealRequestPtr& Request, const TRequestData* RequestData, const FString& TargetBeamableUrl);

	/**
	 * @brief The blueprint-only version of the Beamable Request Processor implementation. This generates a function to be used as the lambda for the HttpRequest completion.
	 * 
	 * @tparam TRequestData A type that implements the FBeamBaseRequest struct.
	 * @tparam TResponseData A type that implements the FBeamBaseResponse struct.
	 * @tparam TSuccessCallback A Dynamic Delegate with two params (DECLARE_DYNAMIC_DELEGATE_TwoParams) that blueprints can define to handle the successful request.
	 * @tparam TErrorCallback A Dynamic Delegate with two params (DECLARE_DYNAMIC_DELEGATE_TwoParams) that blueprints can define to handle a irrecoverable error in the request.
	 * @tparam TCompleteCallback A Dynamic Delegate with one params (DECLARE_DYNAMIC_DELEGATE_OneParam) that blueprints can define to run after the request completes, be it an error or success.
	 * @param RequestId The Request Id generated by the UBeamBackend::CreateRequest function.
	 * @param RequestData An instance of the request type.
	 * @param OnSuccess The callback to handle success.
	 * @param OnError The callback to handle irrecoverable errors.
	 * @param OnComplete The callback to run after success/errors have been handled.
	 * 
	 * @return The request processor function, with correctly captured variables and properly set up to handle errors, retry and other utilities.
	 */
	template <typename TRequestData, typename TResponseData, typename TSuccessCallback, typename TErrorCallback, typename TCompleteCallback>
	FBeamRequestProcessor MakeBlueprintRequestProcessor(const int64& RequestId, TRequestData* RequestData, TSuccessCallback OnSuccess, TErrorCallback OnError,
	                                                    TCompleteCallback OnComplete);

	/**
	 * @brief Callback that MakeBlueprintRequestProcessor uses to handle un-authenticated requests.	  
	 */
	template <typename TRequestData, typename TResponseData, typename TSuccessCallback, typename TErrorCallback, typename TCompleteCallback>
	void ProcessBlueprintRequest(const int32& ResponseCode, const FString& ContentAsString, const TUnrealRequestStatus RequestStatus,
	                             const int64& RequestId, TRequestData* RequestData,
	                             TSuccessCallback OnSuccess, TErrorCallback OnError, TCompleteCallback OnComplete);	

	/**
	 * @brief The blueprint-only version of the Beamable Request Processor implementation for authenticated requests.	 * 
	 * 
	 * @tparam TRequestData A type that implements the FBeamBaseRequest struct.
	 * @tparam TResponseData A type that implements the FBeamBaseResponse struct.
	 * @tparam TSuccessCallback A Dynamic Delegate with two params (DECLARE_DYNAMIC_DELEGATE_TwoParams) that blueprints can define to handle the successful request.
	 * @tparam TErrorCallback A Dynamic Delegate with two params (DECLARE_DYNAMIC_DELEGATE_TwoParams) that blueprints can define to handle a irrecoverable error in the request.
	 * @tparam TCompleteCallback A Dynamic Delegate with one params (DECLARE_DYNAMIC_DELEGATE_OneParam) that blueprints can define to run after the request completes, be it an error or success.
	 * @param RequestId The Request Id generated by the UBeamBackend::CreateRequest function.
	 * @param RealmHandle The Realm (CID+PID) we are making the request to.
	 * @param AuthToken The AuthenticationToken we should be using to make the request.
	 * @param RequestData An instance of the request type.
	 * @param OnSuccess The callback to handle success.
	 * @param OnError The callback to handle irrecoverable errors.
	 * @param OnComplete The callback to run after success/errors have been handled. 
	 * @return A function to be used as the lambda for the HttpRequest completion callback.
	 */
	template <typename TRequestData, typename TResponseData, typename TSuccessCallback, typename TErrorCallback, typename TCompleteCallback>
	FBeamRequestProcessor MakeAuthenticatedBlueprintRequestProcessor(const int64& RequestId, const FBeamRealmHandle& RealmHandle, const FBeamAuthToken& AuthToken,
	                                                                 TRequestData* RequestData, TSuccessCallback OnSuccess, TErrorCallback OnError, TCompleteCallback OnComplete);

	/**
	 * @brief Callback that MakeAuthenticatedBlueprintRequestProcessor uses to handle authenticated requests. 
	 */
	template <typename TRequestData, typename TResponseData, typename TSuccessCallback, typename TErrorCallback, typename TCompleteCallback>
	void ProcessAuthenticatedBlueprintRequest(const int32& ResponseCode, const FString& ContentAsString, const TUnrealRequestStatus RequestStatus,
	                                          const int64& RequestId, const FBeamRealmHandle& RealmHandle, const FBeamAuthToken& AuthToken,
	                                          TRequestData* RequestData, TSuccessCallback OnSuccess, TErrorCallback OnError, TCompleteCallback OnComplete);

	/**
	 * @brief The code-only version of the Beamable Request Processor implementation. This generates 2 things:
	 * a function to be used as the lambda for the HttpRequest completion and a set of Future objects user-code can attach to.
	 * 
	 * @tparam TRequestData A type that implements the FBeamBaseRequest struct.
	 * @tparam TResponseData A type that implements the FBeamBaseResponse struct.
	 * @param RequestId The Request Id generated by the UBeamBackend::CreateRequest function.
	 * @param RequestData An instance of the request type.
	 * @param ResponseHandler A callback to handle the full response of this request. To handle success/error/retry, read from the TBeamFullResponse data.  	 
	 * 
	 * @return The request processor function, with correctly captured variables and properly set up to handle errors, retry and other utilities.
	 */
	template <typename TRequestData, typename TResponseData>
	FBeamRequestProcessor MakeCodeRequestProcessor(const int64& RequestId, TRequestData* RequestData, TBeamFullResponseHandler<TRequestData*, TResponseData*> ResponseHandler);

	/**
	 * @brief Callback that MakeCodeRequestProcessor uses to handle requests that don't require authentication.	  
	 */
	template <typename TRequestData, typename TResponseData>
	void ProcessCodeRequest(const int32& ResponseCode, const FString& ContentAsString, const TUnrealRequestStatus RequestStatus,
	                        const int64& RequestId, TRequestData* RequestData, TBeamFullResponseHandler<TRequestData*, TResponseData*> ResponseHandler);

	/**
	 * @brief The code-only version of the Beamable Request Processor implementation. This generates 2 things:
	 * a function to be used as the lambda for the HttpRequest completion and a set of Future objects user-code can attach to.
	 * 
	 * @tparam TRequestData A type that implements the FBeamBaseRequest struct.
	 * @tparam TResponseData A type that implements the FBeamBaseResponse struct.
	 * @param RequestId The Request Id generated by the UBeamBackend::CreateRequest function.
	 * @param RealmHandle The Realm (CID+PID) we are making the request to.
	 * @param AuthToken The AuthenticationToken we should be using to make the request.
	 * @param RequestData An instance of the request type.
	 * @param ResponseHandler A callback to handle the full response of this request. To handle success/error/retry, read from the TBeamFullResponse data.  	 
	 * 
	 * @return The request processor function, with correctly captured variables and properly set up to handle errors, retry and other utilities.
	 */
	template <typename TRequestData, typename TResponseData>
	FBeamRequestProcessor MakeAuthenticatedCodeRequestProcessor(const int64& RequestId, const FBeamRealmHandle& RealmHandle, const FBeamAuthToken& AuthToken,
	                                                            TRequestData* RequestData, TBeamFullResponseHandler<TRequestData*, TResponseData*> ResponseHandler);

	/**
	 * @brief Callback that MakeAuthenticatedCodeRequestProcessor uses to handle authenticated request's responses.
	 */
	template <typename TRequestData, typename TResponseData>
	void ProcessAuthenticatedCodeRequest(const int32& ResponseCode, const FString& ContentAsString, const TUnrealRequestStatus RequestStatus, const int64& RequestId,
	                                     const FBeamRealmHandle& RealmHandle, const FBeamAuthToken& AuthToken, TRequestData* RequestData,
	                                     const TBeamFullResponseHandler<TRequestData*, TResponseData*>& ResponseHandler);


	/*
	 
  _____      _                 _____             __ _       
 |  __ \    | |               / ____|           / _(_)      
 | |__) |___| |_ _ __ _   _  | |     ___  _ __ | |_ _  __ _ 
 |  _  // _ \ __| '__| | | | | |    / _ \| '_ \|  _| |/ _` |
 | | \ \  __/ |_| |  | |_| | | |___| (_) | | | | | | | (_| |
 |_|  \_\___|\__|_|   \__, |  \_____\___/|_| |_|_| |_|\__, |
					   __/ |                           __/ |
					  |___/                           |___/ 

	 */

	/**
	* @brief Retry configuration data. Can be overriden at the request level. 
	*/
	UPROPERTY(BlueprintReadWrite, Category="Beam|Config")
	FBeamRetryConfig DefaultRetryConfig;

	/**
	 * @brief Key is the request struct type's GetName() call. Value can be set by users. 
	 */
	UPROPERTY(BlueprintReadOnly, Category="Beam|Config")
	TMap<FRequestType, FBeamRetryConfig> PerTypeRetryConfigs;

	/**
	 * @brief Key is the request struct type's GetName() call and the UserSlotId for which this configuration is set separated by '₢'.
	 * Value can be set by users.
	 */
	UPROPERTY(BlueprintReadOnly, Category="Beam|Config")
	TMap<FString, FBeamRetryConfig> PerUserPerTypeRetryConfig;

	/**
	 * @brief Key is the UserSlotId for which this configuration is set. Value can be set by users.
	 */
	UPROPERTY(BlueprintReadOnly, Category="Beam|Config")
	TMap<FUserSlot, FBeamRetryConfig> PerUserRetryConfig;

	/**
	 * @brief Gets the retry configuration associated with all requests of this type. 
	 * @param RequestType Any FBeamRequest::StaticStruct()->GetName() (basically the name of any request struct).
	 * In BP-Land, you can call a static function to get one of these.
	 * 
	 * @param Config The RetryConfiguration.
	 * 
	 * @return True, if the returned config was the one you asked for. False, if a fallback was returned (happens if you call this without ever having set the retry configuration).
	 */
	UFUNCTION(BlueprintGetter, Category="Beam|Config", meta=(AutoCreateRefTerm="RequestType"))
	bool GetRetryConfigForRequestType(const FRequestType& RequestType, FBeamRetryConfig& Config) const;

	/**
	 * @brief Gets the retry configuration associated with all requests made by this user.
	 * @param Slot Any valid UserSlot. 
	 * @param Config The RetryConfiguration.
	 * @return True, if the returned config was the one you asked for. False, if a fallback was returned (happens if you call this without ever having set the retry configuration).
	 */
	UFUNCTION(BlueprintGetter, Category="Beam|Config", meta=(AutoCreateRefTerm="Slot"))
	bool GetRetryConfigForUserSlot(const FUserSlot& Slot, FBeamRetryConfig& Config) const;

	/**
	 * @brief Gets the retry configuration associated with all requests of this type made by the given user slot.
	 * @param RequestType Any FBeamRequest::StaticStruct()->GetName() (basically the name of any request struct).
	 * @param Slot Any valid UserSlot. 
	 * @param Config The RetryConfiguration.
	 * @return True, if the returned config was the one you asked for. False, if a fallback was returned (happens if you call this without ever having set the retry configuration).
	 */
	UFUNCTION(BlueprintGetter, Category="Beam|Config", meta=(AutoCreateRefTerm="RequestType,Slot"))
	bool GetRetryConfigForUserSlotAndRequestType(const FRequestType& RequestType, const FUserSlot& Slot, FBeamRetryConfig& Config) const;


	/**
	 * @brief Sets the retry configuration for a given request type's requests.
	 * @param RequestType The Request type whose retry configuration you wish to reset.
	 * @param RetryConfig The retry config you wish that request type to use.
	 */
	UFUNCTION(BlueprintCallable, Category="Beam|Config", meta=(AutoCreateRefTerm="RequestType"))
	void SetRetryConfigForRequestType(const FRequestType& RequestType, const FBeamRetryConfig& RetryConfig);

	/**
	 * @brief Sets the retry configuration for a given user's requests. 
	 * @param Slot The user slot whose retry configuration you wish to set.
	 * @param RetryConfig The retry config you wish that user to use.
	 */
	UFUNCTION(BlueprintCallable, Category="Beam|Config", meta=(AutoCreateRefTerm="Slot"))
	void SetRetryConfigForUserSlot(const FUserSlot Slot, const FBeamRetryConfig& RetryConfig);

	/**
	 * @brief Sets the retry configuration for a given user + request type combination's requests.
	 * @param Slot The user slot whose retry configuration you wish to set.
	 * @param RequestType The Request type whose retry configuration you wish to reset. 
	 * @param RetryConfig The retry config you wish that user + request type combination to use.
	 */
	UFUNCTION(BlueprintCallable, Category="Beam|Config", meta=(AutoCreateRefTerm="RequestType,Slot"))
	void SetRetryConfigForUserSlotAndRequestType(const FUserSlot& Slot, const FRequestType& RequestType, const FBeamRetryConfig& RetryConfig);

	/**
	 * @brief Resets the Retry Configuration for the given request type  back to the default retry configuration.
	 * @param RequestType The Request type whose retry configuration you wish to reset.
	 */
	UFUNCTION(BlueprintCallable, Category="Beam|Config", meta=(AutoCreateRefTerm="RequestType"))
	void ResetRetryConfigForRequestType(const FRequestType& RequestType);

	/**
	 * @brief Resets the Retry Configuration for the given user back to the default retry configuration.
	 * @param Slot The user slot whose retry configuration you wish to reset.
	 */
	UFUNCTION(BlueprintCallable, Category="Beam|Config", meta=(AutoCreateRefTerm="Slot"))
	void ResetRetryConfigForUserSlot(const FUserSlot& Slot);

	/**
	 * @brief Resets the Retry Configuration for the given user and request type combination back to the default retry configuration.	 
	 * @param Slot The user slot whose retry configuration you wish to reset.
	 * @param RequestType The Request type whose retry configuration you wish to reset.
	 */
	UFUNCTION(BlueprintCallable, Category="Beam|Config", meta=(AutoCreateRefTerm="RequestType,Slot"))
	void ResetRetryConfigForUserSlotAndRequestType(const FUserSlot& Slot, const FRequestType& RequestType);

	/**
	 
	_____                            _   _       _ _         
  / ____|                          | | (_)     (_) |        
 | |     ___  _ __  _ __   ___  ___| |_ ___   ___| |_ _   _ 
 | |    / _ \| '_ \| '_ \ / _ \/ __| __| \ \ / / | __| | | |
 | |___| (_) | | | | | | |  __/ (__| |_| |\ V /| | |_| |_| |
  \_____\___/|_| |_|_| |_|\___|\___|\__|_| \_/ |_|\__|\__, |
													   __/ |
													  |___/ 
	 */


private:
	/**
	* @brief Called whenever a request is completed in order to update our connectivity status in accordance with UE's output codes.
	*/
	void UpdateConnectivity(const FBeamRequestContext& RequestContext, const TUnrealRequestStatus RequestStatus, const FRequestType RequestType);

public:
	/**
	* @brief The current state of internet connection as detected by Beamable. This is updated automatically on every non-timeout request.
	*/
	UPROPERTY(BlueprintReadOnly, Category="Beam|Status")
	FBeamConnectivity CurrentConnectivityStatus;

	/**
	 * @brief A global request handler delegate that'll be called ONCE when we fail a request due to connection problems. 
	 */
	UPROPERTY(BlueprintAssignable, Category="Beam|Status")
	FGlobalConnectivityChangedHandler GlobalConnectivityChangedHandler;

	/**
	 * \copydoc GlobalRequestErrorHandler	
	 * @brief Another global request handler --- this one can be used to bind lambdas from code. Use the other handler if you can.	 
	 */
	FGlobalConnectivityChangedCodeHandler GlobalConnectivityChangedCodeHandler;


	/**	 
	 * @return Whether or not the last request made from BeamBackend was able to connect to the server it was trying to reach.
	 */
	UFUNCTION(BlueprintGetter, Category="Beam|Status")
	bool IsConnected() const;
};