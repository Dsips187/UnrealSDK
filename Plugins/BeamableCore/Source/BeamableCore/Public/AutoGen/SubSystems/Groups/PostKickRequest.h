
#pragma once

#include "CoreMinimal.h"
#include "BeamCoreTypes.h"


#include "AutoGen/KickRequestBody.h"
#include "AutoGen/GroupMembershipResponse.h"

#include "PostKickRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UPostKickRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Object Id")
	int64 ObjectId;
	
	// Query Params
	

	// Body Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="")
	UKickRequestBody* Body;

	// Beam Base Request Declaration
	UPostKickRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, meta=(DefaultToSelf="Outer", AdvancedDisplay="_SubGroup,Outer"))
	static UPostKickRequest* MakePostKickRequest(int64 _ObjectId, int64 _GamerTag, FOptionalInt64 _SubGroup, UObject* Outer);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostKickSuccess, FBeamRequestContext, Context, UPostKickRequest*, Request, UGroupMembershipResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostKickError, FBeamRequestContext, Context, UPostKickRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnPostKickComplete, FBeamRequestContext, Context, UPostKickRequest*, Request);

using FPostKickFullResponse = FBeamFullResponse<UPostKickRequest*, UGroupMembershipResponse*>;
DECLARE_DELEGATE_OneParam(FOnPostKickFullResponse, FPostKickFullResponse);
