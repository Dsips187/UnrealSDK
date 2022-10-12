
#pragma once

#include "CoreMinimal.h"
#include "BeamCoreTypes.h"

#include "AutoGen/GetAdminsResponse.h"

#include "GetAdminAdminUsersRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UGetAdminAdminUsersRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	

	// Body Params
	

	// Beam Base Request Declaration
	UGetAdminAdminUsersRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, meta=(DefaultToSelf="Outer", AdvancedDisplay="Outer"))
	static UGetAdminAdminUsersRequest* MakeGetAdminAdminUsersRequest(UObject* Outer);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetAdminAdminUsersSuccess, FBeamRequestContext, Context, UGetAdminAdminUsersRequest*, Request, UGetAdminsResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetAdminAdminUsersError, FBeamRequestContext, Context, UGetAdminAdminUsersRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnGetAdminAdminUsersComplete, FBeamRequestContext, Context, UGetAdminAdminUsersRequest*, Request);

using FGetAdminAdminUsersFullResponse = FBeamFullResponse<UGetAdminAdminUsersRequest*, UGetAdminsResponse*>;
DECLARE_DELEGATE_OneParam(FOnGetAdminAdminUsersFullResponse, FGetAdminAdminUsersFullResponse);
