
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"


#include "AutoGen/GetProductResponse.h"

#include "GetGoogleplayProductRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UGetGoogleplayProductRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Sku", Category="Beam")
	FString Sku;

	// Body Params
	

	// Beam Base Request Declaration
	UGetGoogleplayProductRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Payments", DisplayName="Beam - Make GetGoogleplayProduct",  meta=(DefaultToSelf="Outer", AdvancedDisplay="Outer"))
	static UGetGoogleplayProductRequest* Make(FString _Sku, UObject* Outer);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetGoogleplayProductSuccess, FBeamRequestContext, Context, UGetGoogleplayProductRequest*, Request, UGetProductResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetGoogleplayProductError, FBeamRequestContext, Context, UGetGoogleplayProductRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnGetGoogleplayProductComplete, FBeamRequestContext, Context, UGetGoogleplayProductRequest*, Request);

using FGetGoogleplayProductFullResponse = FBeamFullResponse<UGetGoogleplayProductRequest*, UGetProductResponse*>;
DECLARE_DELEGATE_OneParam(FOnGetGoogleplayProductFullResponse, FGetGoogleplayProductFullResponse);
