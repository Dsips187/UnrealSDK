
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"

#include "AutoGen/LeaderboardUidResponse.h"

#include "GetUidRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UGetUidRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	

	// Body Params
	

	// Beam Base Request Declaration
	UGetUidRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", DisplayName="Beam - Make GetUid",  meta=(DefaultToSelf="RequestOwner", AdvancedDisplay="RequestOwner"))
	static UGetUidRequest* Make(UObject* RequestOwner);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetUidSuccess, FBeamRequestContext, Context, UGetUidRequest*, Request, ULeaderboardUidResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetUidError, FBeamRequestContext, Context, UGetUidRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnGetUidComplete, FBeamRequestContext, Context, UGetUidRequest*, Request);

using FGetUidFullResponse = FBeamFullResponse<UGetUidRequest*, ULeaderboardUidResponse*>;
DECLARE_DELEGATE_OneParam(FOnGetUidFullResponse, FGetUidFullResponse);
