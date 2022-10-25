
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"


#include "AutoGen/AliasAvailableResponse.h"

#include "GetCustomerAliasAvailableRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UGetCustomerAliasAvailableRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Alias", Category="Beam")
	FString Alias;

	// Body Params
	

	// Beam Base Request Declaration
	UGetCustomerAliasAvailableRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Realms", DisplayName="Beam - Make GetCustomerAliasAvailable",  meta=(DefaultToSelf="Outer", AdvancedDisplay="Outer"))
	static UGetCustomerAliasAvailableRequest* Make(FString _Alias, UObject* Outer);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetCustomerAliasAvailableSuccess, FBeamRequestContext, Context, UGetCustomerAliasAvailableRequest*, Request, UAliasAvailableResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetCustomerAliasAvailableError, FBeamRequestContext, Context, UGetCustomerAliasAvailableRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnGetCustomerAliasAvailableComplete, FBeamRequestContext, Context, UGetCustomerAliasAvailableRequest*, Request);

using FGetCustomerAliasAvailableFullResponse = FBeamFullResponse<UGetCustomerAliasAvailableRequest*, UAliasAvailableResponse*>;
DECLARE_DELEGATE_OneParam(FOnGetCustomerAliasAvailableFullResponse, FGetCustomerAliasAvailableFullResponse);
