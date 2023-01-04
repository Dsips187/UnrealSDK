

#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBackend.h"
#include "RequestTracker/BeamRequestTracker.h"

#include "Commerce/GetSkusRequest.h"
#include "Commerce/GetCouponsCountRequest.h"
#include "Commerce/PostCatalogLegacyRequest.h"
#include "Commerce/GetCatalogRequest.h"
#include "Commerce/PostSkusRequest.h"
#include "Commerce/GetCommerceRequest.h"
#include "Commerce/PutListingsCooldownRequest.h"
#include "Commerce/GetOffersAdminRequest.h"
#include "Commerce/PostPurchaseRequest.h"
#include "Commerce/PutPurchaseRequest.h"
#include "Commerce/GetListingsRequest.h"
#include "Commerce/DeleteStatusRequest.h"
#include "Commerce/PostCouponsRequest.h"
#include "Commerce/PostStatsUpdateRequest.h"
#include "Commerce/GetOffersRequest.h"

#include "BeamCommerceApi.generated.h"


/**
 * Subsystem containing request calls for the Commerce service.
 */
UCLASS(NotBlueprintType)
class BEAMABLECORE_API UBeamCommerceApi : public UEngineSubsystem
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
	void BP_GetSkusImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, FBeamConnectivity& ConnectivityStatus, UGetSkusRequest* RequestData,
	                                const FOnGetSkusSuccess& OnSuccess, const FOnGetSkusError& OnError, const FOnGetSkusComplete& OnComplete,
	                                int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_GetSkusImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, FBeamConnectivity& ConnectivityStatus, UGetSkusRequest* RequestData,
	                                 const FOnGetSkusFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;

		
	/**
	 * @brief Private implementation that all overloaded BP UFunctions call.	  
	 */
	void BP_GetCouponsCountImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, FBeamConnectivity& ConnectivityStatus, UGetCouponsCountRequest* RequestData,
	                                const FOnGetCouponsCountSuccess& OnSuccess, const FOnGetCouponsCountError& OnError, const FOnGetCouponsCountComplete& OnComplete,
	                                int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_GetCouponsCountImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, FBeamConnectivity& ConnectivityStatus, UGetCouponsCountRequest* RequestData,
	                                 const FOnGetCouponsCountFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;


	
	/**
	 * @brief Private implementation for requests that require authentication that all overloaded BP UFunctions call.	  
	 */
	void BP_PostCatalogLegacyImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UPostCatalogLegacyRequest* RequestData,
	                  const FOnPostCatalogLegacySuccess& OnSuccess, const FOnPostCatalogLegacyError& OnError, const FOnPostCatalogLegacyComplete& OnComplete, 
					  int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_PostCatalogLegacyImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UPostCatalogLegacyRequest* RequestData,
	                   const FOnPostCatalogLegacyFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
		
	/**
	 * @brief Private implementation for requests that require authentication that all overloaded BP UFunctions call.	  
	 */
	void BP_GetCatalogImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UGetCatalogRequest* RequestData,
	                  const FOnGetCatalogSuccess& OnSuccess, const FOnGetCatalogError& OnError, const FOnGetCatalogComplete& OnComplete, 
					  int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_GetCatalogImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UGetCatalogRequest* RequestData,
	                   const FOnGetCatalogFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
		
	/**
	 * @brief Private implementation for requests that require authentication that all overloaded BP UFunctions call.	  
	 */
	void BP_PostSkusImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UPostSkusRequest* RequestData,
	                  const FOnPostSkusSuccess& OnSuccess, const FOnPostSkusError& OnError, const FOnPostSkusComplete& OnComplete, 
					  int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_PostSkusImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UPostSkusRequest* RequestData,
	                   const FOnPostSkusFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
		
	/**
	 * @brief Private implementation for requests that require authentication that all overloaded BP UFunctions call.	  
	 */
	void BP_GetCommerceImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UGetCommerceRequest* RequestData,
	                  const FOnGetCommerceSuccess& OnSuccess, const FOnGetCommerceError& OnError, const FOnGetCommerceComplete& OnComplete, 
					  int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_GetCommerceImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UGetCommerceRequest* RequestData,
	                   const FOnGetCommerceFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
		
	/**
	 * @brief Private implementation for requests that require authentication that all overloaded BP UFunctions call.	  
	 */
	void BP_PutListingsCooldownImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UPutListingsCooldownRequest* RequestData,
	                  const FOnPutListingsCooldownSuccess& OnSuccess, const FOnPutListingsCooldownError& OnError, const FOnPutListingsCooldownComplete& OnComplete, 
					  int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_PutListingsCooldownImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UPutListingsCooldownRequest* RequestData,
	                   const FOnPutListingsCooldownFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
		
	/**
	 * @brief Private implementation for requests that require authentication that all overloaded BP UFunctions call.	  
	 */
	void BP_GetOffersAdminImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UGetOffersAdminRequest* RequestData,
	                  const FOnGetOffersAdminSuccess& OnSuccess, const FOnGetOffersAdminError& OnError, const FOnGetOffersAdminComplete& OnComplete, 
					  int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_GetOffersAdminImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UGetOffersAdminRequest* RequestData,
	                   const FOnGetOffersAdminFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
		
	/**
	 * @brief Private implementation for requests that require authentication that all overloaded BP UFunctions call.	  
	 */
	void BP_PostPurchaseImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UPostPurchaseRequest* RequestData,
	                  const FOnPostPurchaseSuccess& OnSuccess, const FOnPostPurchaseError& OnError, const FOnPostPurchaseComplete& OnComplete, 
					  int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_PostPurchaseImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UPostPurchaseRequest* RequestData,
	                   const FOnPostPurchaseFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
		
	/**
	 * @brief Private implementation for requests that require authentication that all overloaded BP UFunctions call.	  
	 */
	void BP_PutPurchaseImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UPutPurchaseRequest* RequestData,
	                  const FOnPutPurchaseSuccess& OnSuccess, const FOnPutPurchaseError& OnError, const FOnPutPurchaseComplete& OnComplete, 
					  int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_PutPurchaseImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UPutPurchaseRequest* RequestData,
	                   const FOnPutPurchaseFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
		
	/**
	 * @brief Private implementation for requests that require authentication that all overloaded BP UFunctions call.	  
	 */
	void BP_GetListingsImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UGetListingsRequest* RequestData,
	                  const FOnGetListingsSuccess& OnSuccess, const FOnGetListingsError& OnError, const FOnGetListingsComplete& OnComplete, 
					  int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_GetListingsImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UGetListingsRequest* RequestData,
	                   const FOnGetListingsFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
		
	/**
	 * @brief Private implementation for requests that require authentication that all overloaded BP UFunctions call.	  
	 */
	void BP_DeleteStatusImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UDeleteStatusRequest* RequestData,
	                  const FOnDeleteStatusSuccess& OnSuccess, const FOnDeleteStatusError& OnError, const FOnDeleteStatusComplete& OnComplete, 
					  int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_DeleteStatusImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UDeleteStatusRequest* RequestData,
	                   const FOnDeleteStatusFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
		
	/**
	 * @brief Private implementation for requests that require authentication that all overloaded BP UFunctions call.	  
	 */
	void BP_PostCouponsImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UPostCouponsRequest* RequestData,
	                  const FOnPostCouponsSuccess& OnSuccess, const FOnPostCouponsError& OnError, const FOnPostCouponsComplete& OnComplete, 
					  int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_PostCouponsImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UPostCouponsRequest* RequestData,
	                   const FOnPostCouponsFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
		
	/**
	 * @brief Private implementation for requests that require authentication that all overloaded BP UFunctions call.	  
	 */
	void BP_PostStatsUpdateImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UPostStatsUpdateRequest* RequestData,
	                  const FOnPostStatsUpdateSuccess& OnSuccess, const FOnPostStatsUpdateError& OnError, const FOnPostStatsUpdateComplete& OnComplete, 
					  int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_PostStatsUpdateImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UPostStatsUpdateRequest* RequestData,
	                   const FOnPostStatsUpdateFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
		
	/**
	 * @brief Private implementation for requests that require authentication that all overloaded BP UFunctions call.	  
	 */
	void BP_GetOffersImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UGetOffersRequest* RequestData,
	                  const FOnGetOffersSuccess& OnSuccess, const FOnGetOffersError& OnError, const FOnGetOffersComplete& OnComplete, 
					  int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_GetOffersImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UGetOffersRequest* RequestData,
	                   const FOnGetOffersFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;

public:
	
	/** Used by a helper blueprint node so that you can easily chain requests in BP-land. */
	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly)
	static UBeamCommerceApi* GetSelf() { return GEngine->GetEngineSubsystem<UBeamCommerceApi>(); }

	
	/**
	 * @brief Makes a request to the Get /basic/commerce/skus endpoint of the Commerce Service.
	 *
	 * PREFER THE UFUNCTION OVERLOAD AS OPPOSED TO THIS. THIS MAINLY EXISTS TO ALLOW LAMBDA BINDING THE HANDLER.
	 * (Dynamic delegates do not allow for that so... we autogen this one to make experimenting in CPP a bit faster and for whenever you need to capture variables).
	 * 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param Handler A callback that defines how to handle success, error and completion.
     * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
	 * @param OpHandle When made as part of an Operation, you can pass this in and it'll register the request with the operation automatically. 
	 */
	void CPP_GetSkus(UGetSkusRequest* Request, const FOnGetSkusFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;

		
	/**
	 * @brief Makes a request to the Get /object/commerce/{objectId}/coupons/count endpoint of the Commerce Service.
	 *
	 * PREFER THE UFUNCTION OVERLOAD AS OPPOSED TO THIS. THIS MAINLY EXISTS TO ALLOW LAMBDA BINDING THE HANDLER.
	 * (Dynamic delegates do not allow for that so... we autogen this one to make experimenting in CPP a bit faster and for whenever you need to capture variables).
	 * 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param Handler A callback that defines how to handle success, error and completion.
     * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
	 * @param OpHandle When made as part of an Operation, you can pass this in and it'll register the request with the operation automatically. 
	 */
	void CPP_GetCouponsCount(UGetCouponsCountRequest* Request, const FOnGetCouponsCountFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;


	
	/**
	 * @brief Makes an authenticated request to the Post /basic/commerce/catalog/legacy endpoint of the Commerce Service.
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
	void CPP_PostCatalogLegacy(const FUserSlot& UserSlot, UPostCatalogLegacyRequest* Request, const FOnPostCatalogLegacyFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr) const;

		
	/**
	 * @brief Makes an authenticated request to the Get /basic/commerce/catalog endpoint of the Commerce Service.
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
	void CPP_GetCatalog(const FUserSlot& UserSlot, UGetCatalogRequest* Request, const FOnGetCatalogFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr) const;

		
	/**
	 * @brief Makes an authenticated request to the Post /basic/commerce/skus endpoint of the Commerce Service.
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
	void CPP_PostSkus(const FUserSlot& UserSlot, UPostSkusRequest* Request, const FOnPostSkusFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr) const;

		
	/**
	 * @brief Makes an authenticated request to the Get /object/commerce/{objectId}/ endpoint of the Commerce Service.
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
	void CPP_GetCommerce(const FUserSlot& UserSlot, UGetCommerceRequest* Request, const FOnGetCommerceFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr) const;

		
	/**
	 * @brief Makes an authenticated request to the Put /object/commerce/{objectId}/listings/cooldown endpoint of the Commerce Service.
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
	void CPP_PutListingsCooldown(const FUserSlot& UserSlot, UPutListingsCooldownRequest* Request, const FOnPutListingsCooldownFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr) const;

		
	/**
	 * @brief Makes an authenticated request to the Get /object/commerce/{objectId}/offersAdmin endpoint of the Commerce Service.
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
	void CPP_GetOffersAdmin(const FUserSlot& UserSlot, UGetOffersAdminRequest* Request, const FOnGetOffersAdminFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr) const;

		
	/**
	 * @brief Makes an authenticated request to the Post /object/commerce/{objectId}/purchase endpoint of the Commerce Service.
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
	void CPP_PostPurchase(const FUserSlot& UserSlot, UPostPurchaseRequest* Request, const FOnPostPurchaseFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr) const;

		
	/**
	 * @brief Makes an authenticated request to the Put /object/commerce/{objectId}/purchase endpoint of the Commerce Service.
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
	void CPP_PutPurchase(const FUserSlot& UserSlot, UPutPurchaseRequest* Request, const FOnPutPurchaseFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr) const;

		
	/**
	 * @brief Makes an authenticated request to the Get /object/commerce/{objectId}/listings endpoint of the Commerce Service.
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
	void CPP_GetListings(const FUserSlot& UserSlot, UGetListingsRequest* Request, const FOnGetListingsFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr) const;

		
	/**
	 * @brief Makes an authenticated request to the Delete /object/commerce/{objectId}/status endpoint of the Commerce Service.
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
	void CPP_DeleteStatus(const FUserSlot& UserSlot, UDeleteStatusRequest* Request, const FOnDeleteStatusFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr) const;

		
	/**
	 * @brief Makes an authenticated request to the Post /object/commerce/{objectId}/coupons endpoint of the Commerce Service.
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
	void CPP_PostCoupons(const FUserSlot& UserSlot, UPostCouponsRequest* Request, const FOnPostCouponsFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr) const;

		
	/**
	 * @brief Makes an authenticated request to the Post /object/commerce/{objectId}/stats/update endpoint of the Commerce Service.
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
	void CPP_PostStatsUpdate(const FUserSlot& UserSlot, UPostStatsUpdateRequest* Request, const FOnPostStatsUpdateFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr) const;

		
	/**
	 * @brief Makes an authenticated request to the Get /object/commerce/{objectId}/offers endpoint of the Commerce Service.
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
	void CPP_GetOffers(const FUserSlot& UserSlot, UGetOffersRequest* Request, const FOnGetOffersFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr) const;


	
	/**
	 * @brief Makes a request to the Get /basic/commerce/skus endpoint of the Commerce Service.
	 *
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight. 
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Commerce", meta=(AdvancedDisplay="OpHandle", AutoCreateRefTerm="OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void GetSkus(UGetSkusRequest* Request, const FOnGetSkusSuccess& OnSuccess, const FOnGetSkusError& OnError, const FOnGetSkusComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle());

		
	/**
	 * @brief Makes a request to the Get /object/commerce/{objectId}/coupons/count endpoint of the Commerce Service.
	 *
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight. 
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Commerce", meta=(AdvancedDisplay="OpHandle", AutoCreateRefTerm="OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void GetCouponsCount(UGetCouponsCountRequest* Request, const FOnGetCouponsCountSuccess& OnSuccess, const FOnGetCouponsCountError& OnError, const FOnGetCouponsCountComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle());


	
	/**
	 * @brief Makes an authenticated request to the Post /basic/commerce/catalog/legacy endpoint of the Commerce Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId).
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Commerce", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="OpHandle,CallingContext",AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void PostCatalogLegacy(FUserSlot UserSlot, UPostCatalogLegacyRequest* Request, const FOnPostCatalogLegacySuccess& OnSuccess, const FOnPostCatalogLegacyError& OnError, const FOnPostCatalogLegacyComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr);

		
	/**
	 * @brief Makes an authenticated request to the Get /basic/commerce/catalog endpoint of the Commerce Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId).
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Commerce", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="OpHandle,CallingContext",AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void GetCatalog(FUserSlot UserSlot, UGetCatalogRequest* Request, const FOnGetCatalogSuccess& OnSuccess, const FOnGetCatalogError& OnError, const FOnGetCatalogComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr);

		
	/**
	 * @brief Makes an authenticated request to the Post /basic/commerce/skus endpoint of the Commerce Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId).
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Commerce", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="OpHandle,CallingContext",AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void PostSkus(FUserSlot UserSlot, UPostSkusRequest* Request, const FOnPostSkusSuccess& OnSuccess, const FOnPostSkusError& OnError, const FOnPostSkusComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr);

		
	/**
	 * @brief Makes an authenticated request to the Get /object/commerce/{objectId}/ endpoint of the Commerce Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId).
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Commerce", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="OpHandle,CallingContext",AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void GetCommerce(FUserSlot UserSlot, UGetCommerceRequest* Request, const FOnGetCommerceSuccess& OnSuccess, const FOnGetCommerceError& OnError, const FOnGetCommerceComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr);

		
	/**
	 * @brief Makes an authenticated request to the Put /object/commerce/{objectId}/listings/cooldown endpoint of the Commerce Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId).
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Commerce", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="OpHandle,CallingContext",AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void PutListingsCooldown(FUserSlot UserSlot, UPutListingsCooldownRequest* Request, const FOnPutListingsCooldownSuccess& OnSuccess, const FOnPutListingsCooldownError& OnError, const FOnPutListingsCooldownComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr);

		
	/**
	 * @brief Makes an authenticated request to the Get /object/commerce/{objectId}/offersAdmin endpoint of the Commerce Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId).
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Commerce", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="OpHandle,CallingContext",AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void GetOffersAdmin(FUserSlot UserSlot, UGetOffersAdminRequest* Request, const FOnGetOffersAdminSuccess& OnSuccess, const FOnGetOffersAdminError& OnError, const FOnGetOffersAdminComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr);

		
	/**
	 * @brief Makes an authenticated request to the Post /object/commerce/{objectId}/purchase endpoint of the Commerce Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId).
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Commerce", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="OpHandle,CallingContext",AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void PostPurchase(FUserSlot UserSlot, UPostPurchaseRequest* Request, const FOnPostPurchaseSuccess& OnSuccess, const FOnPostPurchaseError& OnError, const FOnPostPurchaseComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr);

		
	/**
	 * @brief Makes an authenticated request to the Put /object/commerce/{objectId}/purchase endpoint of the Commerce Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId).
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Commerce", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="OpHandle,CallingContext",AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void PutPurchase(FUserSlot UserSlot, UPutPurchaseRequest* Request, const FOnPutPurchaseSuccess& OnSuccess, const FOnPutPurchaseError& OnError, const FOnPutPurchaseComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr);

		
	/**
	 * @brief Makes an authenticated request to the Get /object/commerce/{objectId}/listings endpoint of the Commerce Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId).
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Commerce", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="OpHandle,CallingContext",AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void GetListings(FUserSlot UserSlot, UGetListingsRequest* Request, const FOnGetListingsSuccess& OnSuccess, const FOnGetListingsError& OnError, const FOnGetListingsComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr);

		
	/**
	 * @brief Makes an authenticated request to the Delete /object/commerce/{objectId}/status endpoint of the Commerce Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId).
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Commerce", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="OpHandle,CallingContext",AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void DeleteStatus(FUserSlot UserSlot, UDeleteStatusRequest* Request, const FOnDeleteStatusSuccess& OnSuccess, const FOnDeleteStatusError& OnError, const FOnDeleteStatusComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr);

		
	/**
	 * @brief Makes an authenticated request to the Post /object/commerce/{objectId}/coupons endpoint of the Commerce Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId).
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Commerce", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="OpHandle,CallingContext",AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void PostCoupons(FUserSlot UserSlot, UPostCouponsRequest* Request, const FOnPostCouponsSuccess& OnSuccess, const FOnPostCouponsError& OnError, const FOnPostCouponsComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr);

		
	/**
	 * @brief Makes an authenticated request to the Post /object/commerce/{objectId}/stats/update endpoint of the Commerce Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId).
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Commerce", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="OpHandle,CallingContext",AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void PostStatsUpdate(FUserSlot UserSlot, UPostStatsUpdateRequest* Request, const FOnPostStatsUpdateSuccess& OnSuccess, const FOnPostStatsUpdateError& OnError, const FOnPostStatsUpdateComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr);

		
	/**
	 * @brief Makes an authenticated request to the Get /object/commerce/{objectId}/offers endpoint of the Commerce Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId).
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Commerce", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="OpHandle,CallingContext",AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void GetOffers(FUserSlot UserSlot, UGetOffersRequest* Request, const FOnGetOffersSuccess& OnSuccess, const FOnGetOffersError& OnError, const FOnGetOffersComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr);
	

	
	/**
	 * @brief Makes a request to the Get /basic/commerce/skus endpoint of the Commerce Service.
	 *	 
	 * @param RetryConfig The retry config for this specific request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context -- used to query information about the request or to cancel it while it's in flight.	  
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Commerce", meta=(AutoCreateRefTerm="OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void GetSkusWithRetry(const FBeamRetryConfig& RetryConfig, UGetSkusRequest* Request, const FOnGetSkusSuccess& OnSuccess, const FOnGetSkusError& OnError, const FOnGetSkusComplete& OnComplete, FBeamRequestContext& OutRequestContext);
		
	/**
	 * @brief Makes a request to the Get /object/commerce/{objectId}/coupons/count endpoint of the Commerce Service.
	 *	 
	 * @param RetryConfig The retry config for this specific request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context -- used to query information about the request or to cancel it while it's in flight.	  
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Commerce", meta=(AutoCreateRefTerm="OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void GetCouponsCountWithRetry(const FBeamRetryConfig& RetryConfig, UGetCouponsCountRequest* Request, const FOnGetCouponsCountSuccess& OnSuccess, const FOnGetCouponsCountError& OnError, const FOnGetCouponsCountComplete& OnComplete, FBeamRequestContext& OutRequestContext);

	
	/**
	 * @brief Makes an authenticated request to the Post /basic/commerce/catalog/legacy endpoint of the Commerce Service.
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
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Commerce", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="CallingContext", AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void PostCatalogLegacyWithRetry(FUserSlot UserSlot, const FBeamRetryConfig& RetryConfig, UPostCatalogLegacyRequest* Request, const FOnPostCatalogLegacySuccess& OnSuccess, const FOnPostCatalogLegacyError& OnError, const FOnPostCatalogLegacyComplete& OnComplete, FBeamRequestContext& OutRequestContext, const UObject* CallingContext = nullptr);
		
	/**
	 * @brief Makes an authenticated request to the Get /basic/commerce/catalog endpoint of the Commerce Service.
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
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Commerce", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="CallingContext", AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void GetCatalogWithRetry(FUserSlot UserSlot, const FBeamRetryConfig& RetryConfig, UGetCatalogRequest* Request, const FOnGetCatalogSuccess& OnSuccess, const FOnGetCatalogError& OnError, const FOnGetCatalogComplete& OnComplete, FBeamRequestContext& OutRequestContext, const UObject* CallingContext = nullptr);
		
	/**
	 * @brief Makes an authenticated request to the Post /basic/commerce/skus endpoint of the Commerce Service.
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
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Commerce", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="CallingContext", AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void PostSkusWithRetry(FUserSlot UserSlot, const FBeamRetryConfig& RetryConfig, UPostSkusRequest* Request, const FOnPostSkusSuccess& OnSuccess, const FOnPostSkusError& OnError, const FOnPostSkusComplete& OnComplete, FBeamRequestContext& OutRequestContext, const UObject* CallingContext = nullptr);
		
	/**
	 * @brief Makes an authenticated request to the Get /object/commerce/{objectId}/ endpoint of the Commerce Service.
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
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Commerce", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="CallingContext", AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void GetCommerceWithRetry(FUserSlot UserSlot, const FBeamRetryConfig& RetryConfig, UGetCommerceRequest* Request, const FOnGetCommerceSuccess& OnSuccess, const FOnGetCommerceError& OnError, const FOnGetCommerceComplete& OnComplete, FBeamRequestContext& OutRequestContext, const UObject* CallingContext = nullptr);
		
	/**
	 * @brief Makes an authenticated request to the Put /object/commerce/{objectId}/listings/cooldown endpoint of the Commerce Service.
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
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Commerce", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="CallingContext", AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void PutListingsCooldownWithRetry(FUserSlot UserSlot, const FBeamRetryConfig& RetryConfig, UPutListingsCooldownRequest* Request, const FOnPutListingsCooldownSuccess& OnSuccess, const FOnPutListingsCooldownError& OnError, const FOnPutListingsCooldownComplete& OnComplete, FBeamRequestContext& OutRequestContext, const UObject* CallingContext = nullptr);
		
	/**
	 * @brief Makes an authenticated request to the Get /object/commerce/{objectId}/offersAdmin endpoint of the Commerce Service.
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
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Commerce", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="CallingContext", AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void GetOffersAdminWithRetry(FUserSlot UserSlot, const FBeamRetryConfig& RetryConfig, UGetOffersAdminRequest* Request, const FOnGetOffersAdminSuccess& OnSuccess, const FOnGetOffersAdminError& OnError, const FOnGetOffersAdminComplete& OnComplete, FBeamRequestContext& OutRequestContext, const UObject* CallingContext = nullptr);
		
	/**
	 * @brief Makes an authenticated request to the Post /object/commerce/{objectId}/purchase endpoint of the Commerce Service.
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
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Commerce", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="CallingContext", AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void PostPurchaseWithRetry(FUserSlot UserSlot, const FBeamRetryConfig& RetryConfig, UPostPurchaseRequest* Request, const FOnPostPurchaseSuccess& OnSuccess, const FOnPostPurchaseError& OnError, const FOnPostPurchaseComplete& OnComplete, FBeamRequestContext& OutRequestContext, const UObject* CallingContext = nullptr);
		
	/**
	 * @brief Makes an authenticated request to the Put /object/commerce/{objectId}/purchase endpoint of the Commerce Service.
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
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Commerce", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="CallingContext", AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void PutPurchaseWithRetry(FUserSlot UserSlot, const FBeamRetryConfig& RetryConfig, UPutPurchaseRequest* Request, const FOnPutPurchaseSuccess& OnSuccess, const FOnPutPurchaseError& OnError, const FOnPutPurchaseComplete& OnComplete, FBeamRequestContext& OutRequestContext, const UObject* CallingContext = nullptr);
		
	/**
	 * @brief Makes an authenticated request to the Get /object/commerce/{objectId}/listings endpoint of the Commerce Service.
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
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Commerce", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="CallingContext", AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void GetListingsWithRetry(FUserSlot UserSlot, const FBeamRetryConfig& RetryConfig, UGetListingsRequest* Request, const FOnGetListingsSuccess& OnSuccess, const FOnGetListingsError& OnError, const FOnGetListingsComplete& OnComplete, FBeamRequestContext& OutRequestContext, const UObject* CallingContext = nullptr);
		
	/**
	 * @brief Makes an authenticated request to the Delete /object/commerce/{objectId}/status endpoint of the Commerce Service.
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
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Commerce", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="CallingContext", AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void DeleteStatusWithRetry(FUserSlot UserSlot, const FBeamRetryConfig& RetryConfig, UDeleteStatusRequest* Request, const FOnDeleteStatusSuccess& OnSuccess, const FOnDeleteStatusError& OnError, const FOnDeleteStatusComplete& OnComplete, FBeamRequestContext& OutRequestContext, const UObject* CallingContext = nullptr);
		
	/**
	 * @brief Makes an authenticated request to the Post /object/commerce/{objectId}/coupons endpoint of the Commerce Service.
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
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Commerce", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="CallingContext", AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void PostCouponsWithRetry(FUserSlot UserSlot, const FBeamRetryConfig& RetryConfig, UPostCouponsRequest* Request, const FOnPostCouponsSuccess& OnSuccess, const FOnPostCouponsError& OnError, const FOnPostCouponsComplete& OnComplete, FBeamRequestContext& OutRequestContext, const UObject* CallingContext = nullptr);
		
	/**
	 * @brief Makes an authenticated request to the Post /object/commerce/{objectId}/stats/update endpoint of the Commerce Service.
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
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Commerce", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="CallingContext", AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void PostStatsUpdateWithRetry(FUserSlot UserSlot, const FBeamRetryConfig& RetryConfig, UPostStatsUpdateRequest* Request, const FOnPostStatsUpdateSuccess& OnSuccess, const FOnPostStatsUpdateError& OnError, const FOnPostStatsUpdateComplete& OnComplete, FBeamRequestContext& OutRequestContext, const UObject* CallingContext = nullptr);
		
	/**
	 * @brief Makes an authenticated request to the Get /object/commerce/{objectId}/offers endpoint of the Commerce Service.
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
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Commerce", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="CallingContext", AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void GetOffersWithRetry(FUserSlot UserSlot, const FBeamRetryConfig& RetryConfig, UGetOffersRequest* Request, const FOnGetOffersSuccess& OnSuccess, const FOnGetOffersError& OnError, const FOnGetOffersComplete& OnComplete, FBeamRequestContext& OutRequestContext, const UObject* CallingContext = nullptr);
};