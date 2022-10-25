
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"

#include "AutoGen/VerifyPurchaseRequestBody.h"
#include "AutoGen/PaymentResultResponse.h"

#include "PostItunesPurchaseVerifyRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UPostItunesPurchaseVerifyRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	

	// Body Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="", Category="Beam")
	UVerifyPurchaseRequestBody* Body;

	// Beam Base Request Declaration
	UPostItunesPurchaseVerifyRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Payments", DisplayName="Beam - Make PostItunesPurchaseVerify",  meta=(DefaultToSelf="Outer", AdvancedDisplay="Outer"))
	static UPostItunesPurchaseVerifyRequest* Make(FString _Receipt, UObject* Outer);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostItunesPurchaseVerifySuccess, FBeamRequestContext, Context, UPostItunesPurchaseVerifyRequest*, Request, UPaymentResultResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostItunesPurchaseVerifyError, FBeamRequestContext, Context, UPostItunesPurchaseVerifyRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnPostItunesPurchaseVerifyComplete, FBeamRequestContext, Context, UPostItunesPurchaseVerifyRequest*, Request);

using FPostItunesPurchaseVerifyFullResponse = FBeamFullResponse<UPostItunesPurchaseVerifyRequest*, UPaymentResultResponse*>;
DECLARE_DELEGATE_OneParam(FOnPostItunesPurchaseVerifyFullResponse, FPostItunesPurchaseVerifyFullResponse);
