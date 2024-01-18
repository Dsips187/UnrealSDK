
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"


#include "BeamableCore/Public/AutoGen/CreateFederatedGameServer.h"
#include "BeamableCore/Public/AutoGen/ApiLobbiesServerPostLobbyResponse.h"

#include "ApiLobbyPostServerRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UApiLobbyPostServerRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Id", Category="Beam")
	FGuid Id = {};
	
	// Query Params
	

	// Body Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="", Category="Beam")
	UCreateFederatedGameServer* Body = {};

	// Beam Base Request Declaration
	UApiLobbyPostServerRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Lobby", DisplayName="Beam - Make ApiLobbyPostServer",  meta=(DefaultToSelf="RequestOwner", AdvancedDisplay="_MatchType,RequestOwner", AutoCreateRefTerm="CustomHeaders"))
	static UApiLobbyPostServerRequest* Make(FGuid _Id, FOptionalBeamContentId _MatchType, UObject* RequestOwner, TMap<FString, FString> CustomHeaders);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnApiLobbyPostServerSuccess, FBeamRequestContext, Context, UApiLobbyPostServerRequest*, Request, UApiLobbiesServerPostLobbyResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnApiLobbyPostServerError, FBeamRequestContext, Context, UApiLobbyPostServerRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnApiLobbyPostServerComplete, FBeamRequestContext, Context, UApiLobbyPostServerRequest*, Request);

using FApiLobbyPostServerFullResponse = FBeamFullResponse<UApiLobbyPostServerRequest*, UApiLobbiesServerPostLobbyResponse*>;
DECLARE_DELEGATE_OneParam(FOnApiLobbyPostServerFullResponse, FApiLobbyPostServerFullResponse);
