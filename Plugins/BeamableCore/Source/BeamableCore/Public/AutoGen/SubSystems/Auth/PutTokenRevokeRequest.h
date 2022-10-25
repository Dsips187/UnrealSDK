
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"

#include "AutoGen/RevokeTokenRequestBody.h"
#include "AutoGen/CommonResponse.h"

#include "PutTokenRevokeRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UPutTokenRevokeRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	

	// Body Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="", Category="Beam")
	URevokeTokenRequestBody* Body;

	// Beam Base Request Declaration
	UPutTokenRevokeRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Auth", DisplayName="Beam - Make PutTokenRevoke",  meta=(DefaultToSelf="Outer", AdvancedDisplay="Outer"))
	static UPutTokenRevokeRequest* Make(FString _Token, UObject* Outer);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPutTokenRevokeSuccess, FBeamRequestContext, Context, UPutTokenRevokeRequest*, Request, UCommonResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPutTokenRevokeError, FBeamRequestContext, Context, UPutTokenRevokeRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnPutTokenRevokeComplete, FBeamRequestContext, Context, UPutTokenRevokeRequest*, Request);

using FPutTokenRevokeFullResponse = FBeamFullResponse<UPutTokenRevokeRequest*, UCommonResponse*>;
DECLARE_DELEGATE_OneParam(FOnPutTokenRevokeFullResponse, FPutTokenRevokeFullResponse);
