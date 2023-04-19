
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"


#include "BeamableCore/Public/AutoGen/AccountAvailableResponse.h"

#include "GetAvailableRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UGetAvailableRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Email", Category="Beam")
	FString Email;

	// Body Params
	

	// Beam Base Request Declaration
	UGetAvailableRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Accounts", DisplayName="Beam - Make GetAvailable",  meta=(DefaultToSelf="RequestOwner", AdvancedDisplay="RequestOwner"))
	static UGetAvailableRequest* Make(FString _Email, UObject* RequestOwner);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetAvailableSuccess, FBeamRequestContext, Context, UGetAvailableRequest*, Request, UAccountAvailableResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetAvailableError, FBeamRequestContext, Context, UGetAvailableRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnGetAvailableComplete, FBeamRequestContext, Context, UGetAvailableRequest*, Request);

using FGetAvailableFullResponse = FBeamFullResponse<UGetAvailableRequest*, UAccountAvailableResponse*>;
DECLARE_DELEGATE_OneParam(FOnGetAvailableFullResponse, FGetAvailableFullResponse);
