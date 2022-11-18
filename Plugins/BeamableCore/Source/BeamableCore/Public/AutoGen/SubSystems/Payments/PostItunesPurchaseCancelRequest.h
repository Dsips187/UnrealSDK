
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"

#include "AutoGen/CancelPurchaseRequestBody.h"
#include "AutoGen/PaymentResultResponse.h"

#include "PostItunesPurchaseCancelRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UPostItunesPurchaseCancelRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	

	// Body Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="", Category="Beam")
	UCancelPurchaseRequestBody* Body;

	// Beam Base Request Declaration
	UPostItunesPurchaseCancelRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Payments", DisplayName="Beam - Make PostItunesPurchaseCancel",  meta=(DefaultToSelf="RequestOwner", AdvancedDisplay="RequestOwner"))
	static UPostItunesPurchaseCancelRequest* Make(int64 _Txid, UObject* RequestOwner);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostItunesPurchaseCancelSuccess, FBeamRequestContext, Context, UPostItunesPurchaseCancelRequest*, Request, UPaymentResultResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostItunesPurchaseCancelError, FBeamRequestContext, Context, UPostItunesPurchaseCancelRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnPostItunesPurchaseCancelComplete, FBeamRequestContext, Context, UPostItunesPurchaseCancelRequest*, Request);

using FPostItunesPurchaseCancelFullResponse = FBeamFullResponse<UPostItunesPurchaseCancelRequest*, UPaymentResultResponse*>;
DECLARE_DELEGATE_OneParam(FOnPostItunesPurchaseCancelFullResponse, FPostItunesPurchaseCancelFullResponse);
