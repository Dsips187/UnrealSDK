
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"


#include "AutoGen/SubscriptionVerificationResponse.h"

#include "GetFacebookUpdateRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UGetFacebookUpdateRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Hub Mode", Category="Beam")
	FString HubMode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Hub Challenge", Category="Beam")
	FString HubChallenge;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Hub Verify Token", Category="Beam")
	FString HubVerifyToken;

	// Body Params
	

	// Beam Base Request Declaration
	UGetFacebookUpdateRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Payments", DisplayName="Beam - Make GetFacebookUpdate",  meta=(DefaultToSelf="Outer", AdvancedDisplay="Outer"))
	static UGetFacebookUpdateRequest* Make(FString _HubMode, FString _HubChallenge, FString _HubVerifyToken, UObject* Outer);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetFacebookUpdateSuccess, FBeamRequestContext, Context, UGetFacebookUpdateRequest*, Request, USubscriptionVerificationResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetFacebookUpdateError, FBeamRequestContext, Context, UGetFacebookUpdateRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnGetFacebookUpdateComplete, FBeamRequestContext, Context, UGetFacebookUpdateRequest*, Request);

using FGetFacebookUpdateFullResponse = FBeamFullResponse<UGetFacebookUpdateRequest*, USubscriptionVerificationResponse*>;
DECLARE_DELEGATE_OneParam(FOnGetFacebookUpdateFullResponse, FGetFacebookUpdateFullResponse);
