
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"

#include "AutoGen/AccountPortalView.h"

#include "GetAdminMeRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UGetAdminMeRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	

	// Body Params
	

	// Beam Base Request Declaration
	UGetAdminMeRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Accounts", DisplayName="Beam - Make GetAdminMe",  meta=(DefaultToSelf="Outer", AdvancedDisplay="Outer"))
	static UGetAdminMeRequest* Make(UObject* Outer);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetAdminMeSuccess, FBeamRequestContext, Context, UGetAdminMeRequest*, Request, UAccountPortalView*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetAdminMeError, FBeamRequestContext, Context, UGetAdminMeRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnGetAdminMeComplete, FBeamRequestContext, Context, UGetAdminMeRequest*, Request);

using FGetAdminMeFullResponse = FBeamFullResponse<UGetAdminMeRequest*, UAccountPortalView*>;
DECLARE_DELEGATE_OneParam(FOnGetAdminMeFullResponse, FGetAdminMeFullResponse);
