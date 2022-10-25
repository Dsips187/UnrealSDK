
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"

#include "AutoGen/CustomerViewResponse.h"

#include "GetCustomerRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UGetCustomerRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	

	// Body Params
	

	// Beam Base Request Declaration
	UGetCustomerRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Realms", DisplayName="Beam - Make GetCustomer",  meta=(DefaultToSelf="Outer", AdvancedDisplay="Outer"))
	static UGetCustomerRequest* Make(UObject* Outer);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetCustomerSuccess, FBeamRequestContext, Context, UGetCustomerRequest*, Request, UCustomerViewResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetCustomerError, FBeamRequestContext, Context, UGetCustomerRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnGetCustomerComplete, FBeamRequestContext, Context, UGetCustomerRequest*, Request);

using FGetCustomerFullResponse = FBeamFullResponse<UGetCustomerRequest*, UCustomerViewResponse*>;
DECLARE_DELEGATE_OneParam(FOnGetCustomerFullResponse, FGetCustomerFullResponse);
