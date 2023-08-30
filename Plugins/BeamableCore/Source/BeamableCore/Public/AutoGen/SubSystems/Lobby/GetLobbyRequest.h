
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"


#include "BeamableCore/Public/AutoGen/Lobby.h"

#include "GetLobbyRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UGetLobbyRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Id", Category="Beam")
	FGuid Id;
	
	// Query Params
	

	// Body Params
	

	// Beam Base Request Declaration
	UGetLobbyRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Lobby", DisplayName="Beam - Make GetLobby",  meta=(DefaultToSelf="RequestOwner", AdvancedDisplay="RequestOwner"))
	static UGetLobbyRequest* Make(FGuid _Id, UObject* RequestOwner);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetLobbySuccess, FBeamRequestContext, Context, UGetLobbyRequest*, Request, ULobby*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetLobbyError, FBeamRequestContext, Context, UGetLobbyRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnGetLobbyComplete, FBeamRequestContext, Context, UGetLobbyRequest*, Request);

using FGetLobbyFullResponse = FBeamFullResponse<UGetLobbyRequest*, ULobby*>;
DECLARE_DELEGATE_OneParam(FOnGetLobbyFullResponse, FGetLobbyFullResponse);
