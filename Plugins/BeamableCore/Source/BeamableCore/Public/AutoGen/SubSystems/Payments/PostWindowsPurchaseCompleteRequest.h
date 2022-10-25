
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"

#include "AutoGen/CompletePurchaseRequestBody.h"
#include "AutoGen/PaymentResultResponse.h"

#include "PostWindowsPurchaseCompleteRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UPostWindowsPurchaseCompleteRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	

	// Body Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="", Category="Beam")
	UCompletePurchaseRequestBody* Body;

	// Beam Base Request Declaration
	UPostWindowsPurchaseCompleteRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Payments", DisplayName="Beam - Make PostWindowsPurchaseComplete",  meta=(DefaultToSelf="Outer", AdvancedDisplay="Outer"))
	static UPostWindowsPurchaseCompleteRequest* Make(int64 _Txid, FString _Receipt, FString _PriceInLocalCurrency, FString _IsoCurrencySymbol, UObject* Outer);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostWindowsPurchaseCompleteSuccess, FBeamRequestContext, Context, UPostWindowsPurchaseCompleteRequest*, Request, UPaymentResultResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostWindowsPurchaseCompleteError, FBeamRequestContext, Context, UPostWindowsPurchaseCompleteRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnPostWindowsPurchaseCompleteComplete, FBeamRequestContext, Context, UPostWindowsPurchaseCompleteRequest*, Request);

using FPostWindowsPurchaseCompleteFullResponse = FBeamFullResponse<UPostWindowsPurchaseCompleteRequest*, UPaymentResultResponse*>;
DECLARE_DELEGATE_OneParam(FOnPostWindowsPurchaseCompleteFullResponse, FPostWindowsPurchaseCompleteFullResponse);
