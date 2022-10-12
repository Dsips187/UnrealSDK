
#pragma once

#include "CoreMinimal.h"
#include "BeamCoreTypes.h"

#include "AutoGen/VerifyPurchaseRequestBody.h"
#include "AutoGen/PaymentResultResponse.h"

#include "PostFacebookPurchaseVerifyRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UPostFacebookPurchaseVerifyRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	

	// Body Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="")
	UVerifyPurchaseRequestBody* Body;

	// Beam Base Request Declaration
	UPostFacebookPurchaseVerifyRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, meta=(DefaultToSelf="Outer", AdvancedDisplay="Outer"))
	static UPostFacebookPurchaseVerifyRequest* MakePostFacebookPurchaseVerifyRequest(FString _Receipt, UObject* Outer);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostFacebookPurchaseVerifySuccess, FBeamRequestContext, Context, UPostFacebookPurchaseVerifyRequest*, Request, UPaymentResultResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostFacebookPurchaseVerifyError, FBeamRequestContext, Context, UPostFacebookPurchaseVerifyRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnPostFacebookPurchaseVerifyComplete, FBeamRequestContext, Context, UPostFacebookPurchaseVerifyRequest*, Request);

using FPostFacebookPurchaseVerifyFullResponse = FBeamFullResponse<UPostFacebookPurchaseVerifyRequest*, UPaymentResultResponse*>;
DECLARE_DELEGATE_OneParam(FOnPostFacebookPurchaseVerifyFullResponse, FPostFacebookPurchaseVerifyFullResponse);
