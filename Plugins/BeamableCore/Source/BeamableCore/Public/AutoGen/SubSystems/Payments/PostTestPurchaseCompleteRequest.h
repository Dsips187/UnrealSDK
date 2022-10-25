
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"

#include "AutoGen/CompletePurchaseRequestBody.h"
#include "AutoGen/PaymentResultResponse.h"

#include "PostTestPurchaseCompleteRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UPostTestPurchaseCompleteRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	

	// Body Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="", Category="Beam")
	UCompletePurchaseRequestBody* Body;

	// Beam Base Request Declaration
	UPostTestPurchaseCompleteRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Payments", DisplayName="Beam - Make PostTestPurchaseComplete",  meta=(DefaultToSelf="Outer", AdvancedDisplay="Outer"))
	static UPostTestPurchaseCompleteRequest* Make(int64 _Txid, FString _Receipt, FString _PriceInLocalCurrency, FString _IsoCurrencySymbol, UObject* Outer);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostTestPurchaseCompleteSuccess, FBeamRequestContext, Context, UPostTestPurchaseCompleteRequest*, Request, UPaymentResultResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostTestPurchaseCompleteError, FBeamRequestContext, Context, UPostTestPurchaseCompleteRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnPostTestPurchaseCompleteComplete, FBeamRequestContext, Context, UPostTestPurchaseCompleteRequest*, Request);

using FPostTestPurchaseCompleteFullResponse = FBeamFullResponse<UPostTestPurchaseCompleteRequest*, UPaymentResultResponse*>;
DECLARE_DELEGATE_OneParam(FOnPostTestPurchaseCompleteFullResponse, FPostTestPurchaseCompleteFullResponse);
