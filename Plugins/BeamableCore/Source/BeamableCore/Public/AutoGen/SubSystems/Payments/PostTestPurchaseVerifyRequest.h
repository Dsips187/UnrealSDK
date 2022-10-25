
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"

#include "AutoGen/VerifyPurchaseRequestBody.h"
#include "AutoGen/PaymentResultResponse.h"

#include "PostTestPurchaseVerifyRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UPostTestPurchaseVerifyRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	

	// Body Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="", Category="Beam")
	UVerifyPurchaseRequestBody* Body;

	// Beam Base Request Declaration
	UPostTestPurchaseVerifyRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Payments", DisplayName="Beam - Make PostTestPurchaseVerify",  meta=(DefaultToSelf="Outer", AdvancedDisplay="Outer"))
	static UPostTestPurchaseVerifyRequest* Make(FString _Receipt, UObject* Outer);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostTestPurchaseVerifySuccess, FBeamRequestContext, Context, UPostTestPurchaseVerifyRequest*, Request, UPaymentResultResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostTestPurchaseVerifyError, FBeamRequestContext, Context, UPostTestPurchaseVerifyRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnPostTestPurchaseVerifyComplete, FBeamRequestContext, Context, UPostTestPurchaseVerifyRequest*, Request);

using FPostTestPurchaseVerifyFullResponse = FBeamFullResponse<UPostTestPurchaseVerifyRequest*, UPaymentResultResponse*>;
DECLARE_DELEGATE_OneParam(FOnPostTestPurchaseVerifyFullResponse, FPostTestPurchaseVerifyFullResponse);
