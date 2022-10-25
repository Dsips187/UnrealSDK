
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"

#include "AutoGen/JoinRequestBody.h"
#include "AutoGen/PlayerStatus.h"

#include "PostTournamentsRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UPostTournamentsRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	

	// Body Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="", Category="Beam")
	UJoinRequestBody* Body;

	// Beam Base Request Declaration
	UPostTournamentsRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Tournaments", DisplayName="Beam - Make PostTournaments",  meta=(DefaultToSelf="Outer", AdvancedDisplay="Outer"))
	static UPostTournamentsRequest* Make(FString _TournamentId, UObject* Outer);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostTournamentsSuccess, FBeamRequestContext, Context, UPostTournamentsRequest*, Request, UPlayerStatus*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostTournamentsError, FBeamRequestContext, Context, UPostTournamentsRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnPostTournamentsComplete, FBeamRequestContext, Context, UPostTournamentsRequest*, Request);

using FPostTournamentsFullResponse = FBeamFullResponse<UPostTournamentsRequest*, UPlayerStatus*>;
DECLARE_DELEGATE_OneParam(FOnPostTournamentsFullResponse, FPostTournamentsFullResponse);
