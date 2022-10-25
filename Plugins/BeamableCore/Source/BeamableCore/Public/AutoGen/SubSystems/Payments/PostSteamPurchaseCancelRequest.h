
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"

#include "AutoGen/CancelPurchaseRequestBody.h"
#include "AutoGen/PaymentResultResponse.h"

#include "PostSteamPurchaseCancelRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UPostSteamPurchaseCancelRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	

	// Body Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="", Category="Beam")
	UCancelPurchaseRequestBody* Body;

	// Beam Base Request Declaration
	UPostSteamPurchaseCancelRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Payments", DisplayName="Beam - Make PostSteamPurchaseCancel",  meta=(DefaultToSelf="Outer", AdvancedDisplay="Outer"))
	static UPostSteamPurchaseCancelRequest* Make(int64 _Txid, UObject* Outer);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostSteamPurchaseCancelSuccess, FBeamRequestContext, Context, UPostSteamPurchaseCancelRequest*, Request, UPaymentResultResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostSteamPurchaseCancelError, FBeamRequestContext, Context, UPostSteamPurchaseCancelRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnPostSteamPurchaseCancelComplete, FBeamRequestContext, Context, UPostSteamPurchaseCancelRequest*, Request);

using FPostSteamPurchaseCancelFullResponse = FBeamFullResponse<UPostSteamPurchaseCancelRequest*, UPaymentResultResponse*>;
DECLARE_DELEGATE_OneParam(FOnPostSteamPurchaseCancelFullResponse, FPostSteamPurchaseCancelFullResponse);
