

#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBackend.h"
#include "RequestTracker/BeamRequestTracker.h"

#include "Inventory/GetItemsRequest.h"
#include "Inventory/GetCurrencyRequest.h"
#include "Inventory/PutPreviewRequest.h"
#include "Inventory/GetMultipliersRequest.h"
#include "Inventory/GetInventoryRequest.h"
#include "Inventory/PostInventoryRequest.h"
#include "Inventory/PutInventoryRequest.h"
#include "Inventory/DeleteTransactionRequest.h"
#include "Inventory/PutTransferRequest.h"

#include "BeamInventoryApi.generated.h"


/**
 * Subsystem containing request calls for the Inventory service.
 */
UCLASS(NotBlueprintType)
class BEAMABLECORE_API UBeamInventoryApi : public UEngineSubsystem
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
	void BP_GetItemsImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, FBeamConnectivity& ConnectivityStatus, UGetItemsRequest* RequestData,
	                                const FOnGetItemsSuccess& OnSuccess, const FOnGetItemsError& OnError, const FOnGetItemsComplete& OnComplete,
	                                int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_GetItemsImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, FBeamConnectivity& ConnectivityStatus, UGetItemsRequest* RequestData,
	                                 const FOnGetItemsFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;

		
	/**
	 * @brief Private implementation that all overloaded BP UFunctions call.	  
	 */
	void BP_GetCurrencyImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, FBeamConnectivity& ConnectivityStatus, UGetCurrencyRequest* RequestData,
	                                const FOnGetCurrencySuccess& OnSuccess, const FOnGetCurrencyError& OnError, const FOnGetCurrencyComplete& OnComplete,
	                                int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_GetCurrencyImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, FBeamConnectivity& ConnectivityStatus, UGetCurrencyRequest* RequestData,
	                                 const FOnGetCurrencyFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;

		
	/**
	 * @brief Private implementation that all overloaded BP UFunctions call.	  
	 */
	void BP_PutPreviewImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, FBeamConnectivity& ConnectivityStatus, UPutPreviewRequest* RequestData,
	                                const FOnPutPreviewSuccess& OnSuccess, const FOnPutPreviewError& OnError, const FOnPutPreviewComplete& OnComplete,
	                                int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_PutPreviewImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, FBeamConnectivity& ConnectivityStatus, UPutPreviewRequest* RequestData,
	                                 const FOnPutPreviewFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;

		
	/**
	 * @brief Private implementation that all overloaded BP UFunctions call.	  
	 */
	void BP_GetMultipliersImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, FBeamConnectivity& ConnectivityStatus, UGetMultipliersRequest* RequestData,
	                                const FOnGetMultipliersSuccess& OnSuccess, const FOnGetMultipliersError& OnError, const FOnGetMultipliersComplete& OnComplete,
	                                int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_GetMultipliersImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, FBeamConnectivity& ConnectivityStatus, UGetMultipliersRequest* RequestData,
	                                 const FOnGetMultipliersFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;

		
	/**
	 * @brief Private implementation that all overloaded BP UFunctions call.	  
	 */
	void BP_GetInventoryImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, FBeamConnectivity& ConnectivityStatus, UGetInventoryRequest* RequestData,
	                                const FOnGetInventorySuccess& OnSuccess, const FOnGetInventoryError& OnError, const FOnGetInventoryComplete& OnComplete,
	                                int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_GetInventoryImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, FBeamConnectivity& ConnectivityStatus, UGetInventoryRequest* RequestData,
	                                 const FOnGetInventoryFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;

		
	/**
	 * @brief Private implementation that all overloaded BP UFunctions call.	  
	 */
	void BP_PostInventoryImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, FBeamConnectivity& ConnectivityStatus, UPostInventoryRequest* RequestData,
	                                const FOnPostInventorySuccess& OnSuccess, const FOnPostInventoryError& OnError, const FOnPostInventoryComplete& OnComplete,
	                                int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_PostInventoryImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, FBeamConnectivity& ConnectivityStatus, UPostInventoryRequest* RequestData,
	                                 const FOnPostInventoryFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;

		
	/**
	 * @brief Private implementation that all overloaded BP UFunctions call.	  
	 */
	void BP_PutInventoryImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, FBeamConnectivity& ConnectivityStatus, UPutInventoryRequest* RequestData,
	                                const FOnPutInventorySuccess& OnSuccess, const FOnPutInventoryError& OnError, const FOnPutInventoryComplete& OnComplete,
	                                int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_PutInventoryImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, FBeamConnectivity& ConnectivityStatus, UPutInventoryRequest* RequestData,
	                                 const FOnPutInventoryFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;


	
	/**
	 * @brief Private implementation for requests that require authentication that all overloaded BP UFunctions call.	  
	 */
	void BP_DeleteTransactionImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UDeleteTransactionRequest* RequestData,
	                  const FOnDeleteTransactionSuccess& OnSuccess, const FOnDeleteTransactionError& OnError, const FOnDeleteTransactionComplete& OnComplete, 
					  int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_DeleteTransactionImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UDeleteTransactionRequest* RequestData,
	                   const FOnDeleteTransactionFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
		
	/**
	 * @brief Private implementation for requests that require authentication that all overloaded BP UFunctions call.	  
	 */
	void BP_PutTransferImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UPutTransferRequest* RequestData,
	                  const FOnPutTransferSuccess& OnSuccess, const FOnPutTransferError& OnError, const FOnPutTransferComplete& OnComplete, 
					  int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;
	/**
	 * @brief Overload version for binding lambdas when in C++ land. Prefer the BP version whenever possible, this is here mostly for quick experimentation purposes.	 
	 */
	void CPP_PutTransferImpl(const FBeamRealmHandle& TargetRealm, const FBeamRetryConfig& RetryConfig, const FBeamAuthToken& AuthToken, FBeamConnectivity& ConnectivityStatus, UPutTransferRequest* RequestData,
	                   const FOnPutTransferFullResponse& Handler, int64& OutRequestId, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;

public:
	
	/** Used by a helper blueprint node so that you can easily chain requests in BP-land. */
	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly)
	static UBeamInventoryApi* GetSelf() { return GEngine->GetEngineSubsystem<UBeamInventoryApi>(); }

	
	/**
	 * @brief Makes a request to the Get /basic/inventory/items endpoint of the Inventory Service.
	 *
	 * PREFER THE UFUNCTION OVERLOAD AS OPPOSED TO THIS. THIS MAINLY EXISTS TO ALLOW LAMBDA BINDING THE HANDLER.
	 * (Dynamic delegates do not allow for that so... we autogen this one to make experimenting in CPP a bit faster and for whenever you need to capture variables).
	 * 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param Handler A callback that defines how to handle success, error and completion.
     * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
	 * @param OpHandle When made as part of an Operation, you can pass this in and it'll register the request with the operation automatically. 
	 */
	void CPP_GetItems(UGetItemsRequest* Request, const FOnGetItemsFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;

		
	/**
	 * @brief Makes a request to the Get /basic/inventory/currency endpoint of the Inventory Service.
	 *
	 * PREFER THE UFUNCTION OVERLOAD AS OPPOSED TO THIS. THIS MAINLY EXISTS TO ALLOW LAMBDA BINDING THE HANDLER.
	 * (Dynamic delegates do not allow for that so... we autogen this one to make experimenting in CPP a bit faster and for whenever you need to capture variables).
	 * 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param Handler A callback that defines how to handle success, error and completion.
     * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
	 * @param OpHandle When made as part of an Operation, you can pass this in and it'll register the request with the operation automatically. 
	 */
	void CPP_GetCurrency(UGetCurrencyRequest* Request, const FOnGetCurrencyFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;

		
	/**
	 * @brief Makes a request to the Put /object/inventory/{objectId}/preview endpoint of the Inventory Service.
	 *
	 * PREFER THE UFUNCTION OVERLOAD AS OPPOSED TO THIS. THIS MAINLY EXISTS TO ALLOW LAMBDA BINDING THE HANDLER.
	 * (Dynamic delegates do not allow for that so... we autogen this one to make experimenting in CPP a bit faster and for whenever you need to capture variables).
	 * 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param Handler A callback that defines how to handle success, error and completion.
     * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
	 * @param OpHandle When made as part of an Operation, you can pass this in and it'll register the request with the operation automatically. 
	 */
	void CPP_PutPreview(UPutPreviewRequest* Request, const FOnPutPreviewFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;

		
	/**
	 * @brief Makes a request to the Get /object/inventory/{objectId}/multipliers endpoint of the Inventory Service.
	 *
	 * PREFER THE UFUNCTION OVERLOAD AS OPPOSED TO THIS. THIS MAINLY EXISTS TO ALLOW LAMBDA BINDING THE HANDLER.
	 * (Dynamic delegates do not allow for that so... we autogen this one to make experimenting in CPP a bit faster and for whenever you need to capture variables).
	 * 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param Handler A callback that defines how to handle success, error and completion.
     * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
	 * @param OpHandle When made as part of an Operation, you can pass this in and it'll register the request with the operation automatically. 
	 */
	void CPP_GetMultipliers(UGetMultipliersRequest* Request, const FOnGetMultipliersFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;

		
	/**
	 * @brief Makes a request to the Get /object/inventory/{objectId}/ endpoint of the Inventory Service.
	 *
	 * PREFER THE UFUNCTION OVERLOAD AS OPPOSED TO THIS. THIS MAINLY EXISTS TO ALLOW LAMBDA BINDING THE HANDLER.
	 * (Dynamic delegates do not allow for that so... we autogen this one to make experimenting in CPP a bit faster and for whenever you need to capture variables).
	 * 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param Handler A callback that defines how to handle success, error and completion.
     * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
	 * @param OpHandle When made as part of an Operation, you can pass this in and it'll register the request with the operation automatically. 
	 */
	void CPP_GetInventory(UGetInventoryRequest* Request, const FOnGetInventoryFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;

		
	/**
	 * @brief Makes a request to the Post /object/inventory/{objectId}/ endpoint of the Inventory Service.
	 *
	 * PREFER THE UFUNCTION OVERLOAD AS OPPOSED TO THIS. THIS MAINLY EXISTS TO ALLOW LAMBDA BINDING THE HANDLER.
	 * (Dynamic delegates do not allow for that so... we autogen this one to make experimenting in CPP a bit faster and for whenever you need to capture variables).
	 * 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param Handler A callback that defines how to handle success, error and completion.
     * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
	 * @param OpHandle When made as part of an Operation, you can pass this in and it'll register the request with the operation automatically. 
	 */
	void CPP_PostInventory(UPostInventoryRequest* Request, const FOnPostInventoryFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;

		
	/**
	 * @brief Makes a request to the Put /object/inventory/{objectId}/ endpoint of the Inventory Service.
	 *
	 * PREFER THE UFUNCTION OVERLOAD AS OPPOSED TO THIS. THIS MAINLY EXISTS TO ALLOW LAMBDA BINDING THE HANDLER.
	 * (Dynamic delegates do not allow for that so... we autogen this one to make experimenting in CPP a bit faster and for whenever you need to capture variables).
	 * 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param Handler A callback that defines how to handle success, error and completion.
     * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
	 * @param OpHandle When made as part of an Operation, you can pass this in and it'll register the request with the operation automatically. 
	 */
	void CPP_PutInventory(UPutInventoryRequest* Request, const FOnPutInventoryFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle()) const;


	
	/**
	 * @brief Makes an authenticated request to the Delete /object/inventory/{objectId}/transaction endpoint of the Inventory Service.
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
	void CPP_DeleteTransaction(const FUserSlot& UserSlot, UDeleteTransactionRequest* Request, const FOnDeleteTransactionFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr) const;

		
	/**
	 * @brief Makes an authenticated request to the Put /object/inventory/{objectId}/transfer endpoint of the Inventory Service.
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
	void CPP_PutTransfer(const FUserSlot& UserSlot, UPutTransferRequest* Request, const FOnPutTransferFullResponse& Handler, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr) const;


	
	/**
	 * @brief Makes a request to the Get /basic/inventory/items endpoint of the Inventory Service.
	 *
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight. 
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Inventory", meta=(AdvancedDisplay="OpHandle", AutoCreateRefTerm="OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void GetItems(UGetItemsRequest* Request, const FOnGetItemsSuccess& OnSuccess, const FOnGetItemsError& OnError, const FOnGetItemsComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle());

		
	/**
	 * @brief Makes a request to the Get /basic/inventory/currency endpoint of the Inventory Service.
	 *
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight. 
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Inventory", meta=(AdvancedDisplay="OpHandle", AutoCreateRefTerm="OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void GetCurrency(UGetCurrencyRequest* Request, const FOnGetCurrencySuccess& OnSuccess, const FOnGetCurrencyError& OnError, const FOnGetCurrencyComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle());

		
	/**
	 * @brief Makes a request to the Put /object/inventory/{objectId}/preview endpoint of the Inventory Service.
	 *
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight. 
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Inventory", meta=(AdvancedDisplay="OpHandle", AutoCreateRefTerm="OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void PutPreview(UPutPreviewRequest* Request, const FOnPutPreviewSuccess& OnSuccess, const FOnPutPreviewError& OnError, const FOnPutPreviewComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle());

		
	/**
	 * @brief Makes a request to the Get /object/inventory/{objectId}/multipliers endpoint of the Inventory Service.
	 *
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight. 
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Inventory", meta=(AdvancedDisplay="OpHandle", AutoCreateRefTerm="OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void GetMultipliers(UGetMultipliersRequest* Request, const FOnGetMultipliersSuccess& OnSuccess, const FOnGetMultipliersError& OnError, const FOnGetMultipliersComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle());

		
	/**
	 * @brief Makes a request to the Get /object/inventory/{objectId}/ endpoint of the Inventory Service.
	 *
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight. 
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Inventory", meta=(AdvancedDisplay="OpHandle", AutoCreateRefTerm="OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void GetInventory(UGetInventoryRequest* Request, const FOnGetInventorySuccess& OnSuccess, const FOnGetInventoryError& OnError, const FOnGetInventoryComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle());

		
	/**
	 * @brief Makes a request to the Post /object/inventory/{objectId}/ endpoint of the Inventory Service.
	 *
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight. 
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Inventory", meta=(AdvancedDisplay="OpHandle", AutoCreateRefTerm="OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void PostInventory(UPostInventoryRequest* Request, const FOnPostInventorySuccess& OnSuccess, const FOnPostInventoryError& OnError, const FOnPostInventoryComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle());

		
	/**
	 * @brief Makes a request to the Put /object/inventory/{objectId}/ endpoint of the Inventory Service.
	 *
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight. 
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Inventory", meta=(AdvancedDisplay="OpHandle", AutoCreateRefTerm="OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void PutInventory(UPutInventoryRequest* Request, const FOnPutInventorySuccess& OnSuccess, const FOnPutInventoryError& OnError, const FOnPutInventoryComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle());


	
	/**
	 * @brief Makes an authenticated request to the Delete /object/inventory/{objectId}/transaction endpoint of the Inventory Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId).
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Inventory", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="OpHandle,CallingContext",AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void DeleteTransaction(FUserSlot UserSlot, UDeleteTransactionRequest* Request, const FOnDeleteTransactionSuccess& OnSuccess, const FOnDeleteTransactionError& OnError, const FOnDeleteTransactionComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr);

		
	/**
	 * @brief Makes an authenticated request to the Put /object/inventory/{objectId}/transfer endpoint of the Inventory Service.
	 *
	 * @param UserSlot The authenticated UserSlot with the user making the request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context associated with this request -- used to query information about the request or to cancel it while it's in flight.
     * @param CallingContext A UObject managed by the world that's making the request. Used to support multiple PIEs (see UBeamUserSlot::GetNamespacedSlotId).
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Inventory", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="OpHandle,CallingContext",AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete,OpHandle", BeamFlowFunction))
	void PutTransfer(FUserSlot UserSlot, UPutTransferRequest* Request, const FOnPutTransferSuccess& OnSuccess, const FOnPutTransferError& OnError, const FOnPutTransferComplete& OnComplete, FBeamRequestContext& OutRequestContext, FBeamOperationHandle OpHandle = FBeamOperationHandle(), const UObject* CallingContext = nullptr);
	

	
	/**
	 * @brief Makes a request to the Get /basic/inventory/items endpoint of the Inventory Service.
	 *	 
	 * @param RetryConfig The retry config for this specific request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context -- used to query information about the request or to cancel it while it's in flight.	  
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Inventory", meta=(AutoCreateRefTerm="OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void GetItemsWithRetry(const FBeamRetryConfig& RetryConfig, UGetItemsRequest* Request, const FOnGetItemsSuccess& OnSuccess, const FOnGetItemsError& OnError, const FOnGetItemsComplete& OnComplete, FBeamRequestContext& OutRequestContext);
		
	/**
	 * @brief Makes a request to the Get /basic/inventory/currency endpoint of the Inventory Service.
	 *	 
	 * @param RetryConfig The retry config for this specific request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context -- used to query information about the request or to cancel it while it's in flight.	  
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Inventory", meta=(AutoCreateRefTerm="OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void GetCurrencyWithRetry(const FBeamRetryConfig& RetryConfig, UGetCurrencyRequest* Request, const FOnGetCurrencySuccess& OnSuccess, const FOnGetCurrencyError& OnError, const FOnGetCurrencyComplete& OnComplete, FBeamRequestContext& OutRequestContext);
		
	/**
	 * @brief Makes a request to the Put /object/inventory/{objectId}/preview endpoint of the Inventory Service.
	 *	 
	 * @param RetryConfig The retry config for this specific request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context -- used to query information about the request or to cancel it while it's in flight.	  
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Inventory", meta=(AutoCreateRefTerm="OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void PutPreviewWithRetry(const FBeamRetryConfig& RetryConfig, UPutPreviewRequest* Request, const FOnPutPreviewSuccess& OnSuccess, const FOnPutPreviewError& OnError, const FOnPutPreviewComplete& OnComplete, FBeamRequestContext& OutRequestContext);
		
	/**
	 * @brief Makes a request to the Get /object/inventory/{objectId}/multipliers endpoint of the Inventory Service.
	 *	 
	 * @param RetryConfig The retry config for this specific request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context -- used to query information about the request or to cancel it while it's in flight.	  
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Inventory", meta=(AutoCreateRefTerm="OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void GetMultipliersWithRetry(const FBeamRetryConfig& RetryConfig, UGetMultipliersRequest* Request, const FOnGetMultipliersSuccess& OnSuccess, const FOnGetMultipliersError& OnError, const FOnGetMultipliersComplete& OnComplete, FBeamRequestContext& OutRequestContext);
		
	/**
	 * @brief Makes a request to the Get /object/inventory/{objectId}/ endpoint of the Inventory Service.
	 *	 
	 * @param RetryConfig The retry config for this specific request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context -- used to query information about the request or to cancel it while it's in flight.	  
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Inventory", meta=(AutoCreateRefTerm="OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void GetInventoryWithRetry(const FBeamRetryConfig& RetryConfig, UGetInventoryRequest* Request, const FOnGetInventorySuccess& OnSuccess, const FOnGetInventoryError& OnError, const FOnGetInventoryComplete& OnComplete, FBeamRequestContext& OutRequestContext);
		
	/**
	 * @brief Makes a request to the Post /object/inventory/{objectId}/ endpoint of the Inventory Service.
	 *	 
	 * @param RetryConfig The retry config for this specific request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context -- used to query information about the request or to cancel it while it's in flight.	  
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Inventory", meta=(AutoCreateRefTerm="OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void PostInventoryWithRetry(const FBeamRetryConfig& RetryConfig, UPostInventoryRequest* Request, const FOnPostInventorySuccess& OnSuccess, const FOnPostInventoryError& OnError, const FOnPostInventoryComplete& OnComplete, FBeamRequestContext& OutRequestContext);
		
	/**
	 * @brief Makes a request to the Put /object/inventory/{objectId}/ endpoint of the Inventory Service.
	 *	 
	 * @param RetryConfig The retry config for this specific request. 
	 * @param Request The Request UObject. All (de)serialized data the request data creates is tied to the lifecycle of this object.
	 * @param OnSuccess What to do if the requests receives a successful response.
	 * @param OnError What to do if the request receives an error response.
	 * @param OnComplete What to after either OnSuccess or OnError have finished executing.
	 * @param OutRequestContext The Request Context -- used to query information about the request or to cancel it while it's in flight.	  
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Inventory", meta=(AutoCreateRefTerm="OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void PutInventoryWithRetry(const FBeamRetryConfig& RetryConfig, UPutInventoryRequest* Request, const FOnPutInventorySuccess& OnSuccess, const FOnPutInventoryError& OnError, const FOnPutInventoryComplete& OnComplete, FBeamRequestContext& OutRequestContext);

	
	/**
	 * @brief Makes an authenticated request to the Delete /object/inventory/{objectId}/transaction endpoint of the Inventory Service.
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
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Inventory", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="CallingContext", AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void DeleteTransactionWithRetry(FUserSlot UserSlot, const FBeamRetryConfig& RetryConfig, UDeleteTransactionRequest* Request, const FOnDeleteTransactionSuccess& OnSuccess, const FOnDeleteTransactionError& OnError, const FOnDeleteTransactionComplete& OnComplete, FBeamRequestContext& OutRequestContext, const UObject* CallingContext = nullptr);
		
	/**
	 * @brief Makes an authenticated request to the Put /object/inventory/{objectId}/transfer endpoint of the Inventory Service.
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
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category="Beam|Backend|Inventory", meta=(DefaultToSelf="CallingContext", AdvancedDisplay="CallingContext", AutoCreateRefTerm="UserSlot,OnSuccess,OnError,OnComplete", BeamFlowFunction))
	void PutTransferWithRetry(FUserSlot UserSlot, const FBeamRetryConfig& RetryConfig, UPutTransferRequest* Request, const FOnPutTransferSuccess& OnSuccess, const FOnPutTransferError& OnError, const FOnPutTransferComplete& OnComplete, FBeamRequestContext& OutRequestContext, const UObject* CallingContext = nullptr);
};
