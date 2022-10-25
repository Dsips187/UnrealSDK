
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"


#include "AutoGen/GetProductResponse.h"

#include "GetFacebookProductRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UGetFacebookProductRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Sku", Category="Beam")
	FString Sku;

	// Body Params
	

	// Beam Base Request Declaration
	UGetFacebookProductRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Payments", DisplayName="Beam - Make GetFacebookProduct",  meta=(DefaultToSelf="Outer", AdvancedDisplay="Outer"))
	static UGetFacebookProductRequest* Make(FString _Sku, UObject* Outer);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetFacebookProductSuccess, FBeamRequestContext, Context, UGetFacebookProductRequest*, Request, UGetProductResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetFacebookProductError, FBeamRequestContext, Context, UGetFacebookProductRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnGetFacebookProductComplete, FBeamRequestContext, Context, UGetFacebookProductRequest*, Request);

using FGetFacebookProductFullResponse = FBeamFullResponse<UGetFacebookProductRequest*, UGetProductResponse*>;
DECLARE_DELEGATE_OneParam(FOnGetFacebookProductFullResponse, FGetFacebookProductFullResponse);
