
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"

#include "BeamableCore/Public/AutoGen/Optionals/OptionalInt32.h"
#include "BeamableCore/Public/AutoGen/Optionals/OptionalBeamContentId.h"
#include "BeamableCore/Public/AutoGen/LobbyQueryResponse.h"

#include "GetLobbiesRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UGetLobbiesRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Skip", Category="Beam")
	FOptionalInt32 Skip = {};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Limit", Category="Beam")
	FOptionalInt32 Limit = {};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Match Type", Category="Beam")
	FOptionalBeamContentId MatchType = {};

	// Body Params
	

	// Beam Base Request Declaration
	UGetLobbiesRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Lobby", DisplayName="Beam - Make GetLobbies",  meta=(DefaultToSelf="RequestOwner", AdvancedDisplay="_Skip,_Limit,_MatchType,RequestOwner", AutoCreateRefTerm="CustomHeaders"))
	static UGetLobbiesRequest* Make(FOptionalInt32 _Skip, FOptionalInt32 _Limit, FOptionalBeamContentId _MatchType, UObject* RequestOwner, TMap<FString, FString> CustomHeaders);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetLobbiesSuccess, FBeamRequestContext, Context, UGetLobbiesRequest*, Request, ULobbyQueryResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetLobbiesError, FBeamRequestContext, Context, UGetLobbiesRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnGetLobbiesComplete, FBeamRequestContext, Context, UGetLobbiesRequest*, Request);

using FGetLobbiesFullResponse = FBeamFullResponse<UGetLobbiesRequest*, ULobbyQueryResponse*>;
DECLARE_DELEGATE_OneParam(FOnGetLobbiesFullResponse, FGetLobbiesFullResponse);
