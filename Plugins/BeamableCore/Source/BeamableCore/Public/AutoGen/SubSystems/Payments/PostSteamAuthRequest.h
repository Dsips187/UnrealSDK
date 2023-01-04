
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"

#include "AutoGen/SteamAuthRequestBody.h"
#include "AutoGen/EmptyResponse.h"

#include "PostSteamAuthRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UPostSteamAuthRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	

	// Body Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="", Category="Beam")
	USteamAuthRequestBody* Body;

	// Beam Base Request Declaration
	UPostSteamAuthRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Payments", DisplayName="Beam - Make PostSteamAuth",  meta=(DefaultToSelf="RequestOwner", AdvancedDisplay="RequestOwner"))
	static UPostSteamAuthRequest* Make(FString _Ticket, UObject* RequestOwner);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostSteamAuthSuccess, FBeamRequestContext, Context, UPostSteamAuthRequest*, Request, UEmptyResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostSteamAuthError, FBeamRequestContext, Context, UPostSteamAuthRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnPostSteamAuthComplete, FBeamRequestContext, Context, UPostSteamAuthRequest*, Request);

using FPostSteamAuthFullResponse = FBeamFullResponse<UPostSteamAuthRequest*, UEmptyResponse*>;
DECLARE_DELEGATE_OneParam(FOnPostSteamAuthFullResponse, FPostSteamAuthFullResponse);