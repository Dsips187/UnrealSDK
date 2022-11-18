
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"

#include "AutoGen/CustomersResponse.h"

#include "GetCustomersRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UGetCustomersRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	

	// Body Params
	

	// Beam Base Request Declaration
	UGetCustomersRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Realms", DisplayName="Beam - Make GetCustomers",  meta=(DefaultToSelf="RequestOwner", AdvancedDisplay="RequestOwner"))
	static UGetCustomersRequest* Make(UObject* RequestOwner);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetCustomersSuccess, FBeamRequestContext, Context, UGetCustomersRequest*, Request, UCustomersResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetCustomersError, FBeamRequestContext, Context, UGetCustomersRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnGetCustomersComplete, FBeamRequestContext, Context, UGetCustomersRequest*, Request);

using FGetCustomersFullResponse = FBeamFullResponse<UGetCustomersRequest*, UCustomersResponse*>;
DECLARE_DELEGATE_OneParam(FOnGetCustomersFullResponse, FGetCustomersFullResponse);
