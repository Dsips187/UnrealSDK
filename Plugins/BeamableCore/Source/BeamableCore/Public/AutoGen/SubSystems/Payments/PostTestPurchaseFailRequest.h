
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"

#include "AutoGen/FailPurchaseRequestBody.h"
#include "AutoGen/PaymentResultResponse.h"

#include "PostTestPurchaseFailRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UPostTestPurchaseFailRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	

	// Body Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="", Category="Beam")
	UFailPurchaseRequestBody* Body;

	// Beam Base Request Declaration
	UPostTestPurchaseFailRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Payments", DisplayName="Beam - Make PostTestPurchaseFail",  meta=(DefaultToSelf="Outer", AdvancedDisplay="Outer"))
	static UPostTestPurchaseFailRequest* Make(int64 _Txid, FString _Reason, UObject* Outer);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostTestPurchaseFailSuccess, FBeamRequestContext, Context, UPostTestPurchaseFailRequest*, Request, UPaymentResultResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostTestPurchaseFailError, FBeamRequestContext, Context, UPostTestPurchaseFailRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnPostTestPurchaseFailComplete, FBeamRequestContext, Context, UPostTestPurchaseFailRequest*, Request);

using FPostTestPurchaseFailFullResponse = FBeamFullResponse<UPostTestPurchaseFailRequest*, UPaymentResultResponse*>;
DECLARE_DELEGATE_OneParam(FOnPostTestPurchaseFailFullResponse, FPostTestPurchaseFailFullResponse);
