
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"



#include "AutoGen/LeaderboardMembershipResponse.h"

#include "GetMembershipRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UGetMembershipRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Object Id", Category="Beam")
	FString ObjectId;
	
	// Query Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Player Id", Category="Beam")
	int64 PlayerId;

	// Body Params
	

	// Beam Base Request Declaration
	UGetMembershipRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", DisplayName="Beam - Make GetMembership",  meta=(DefaultToSelf="RequestOwner", AdvancedDisplay="RequestOwner"))
	static UGetMembershipRequest* Make(FString _ObjectId, int64 _PlayerId, UObject* RequestOwner);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetMembershipSuccess, FBeamRequestContext, Context, UGetMembershipRequest*, Request, ULeaderboardMembershipResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetMembershipError, FBeamRequestContext, Context, UGetMembershipRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnGetMembershipComplete, FBeamRequestContext, Context, UGetMembershipRequest*, Request);

using FGetMembershipFullResponse = FBeamFullResponse<UGetMembershipRequest*, ULeaderboardMembershipResponse*>;
DECLARE_DELEGATE_OneParam(FOnGetMembershipFullResponse, FGetMembershipFullResponse);
