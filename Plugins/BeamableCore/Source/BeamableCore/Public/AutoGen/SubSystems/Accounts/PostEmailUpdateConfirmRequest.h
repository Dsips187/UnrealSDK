
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"

#include "AutoGen/EmailUpdateConfirmation.h"
#include "AutoGen/EmptyResponse.h"

#include "PostEmailUpdateConfirmRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UPostEmailUpdateConfirmRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	

	// Body Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="", Category="Beam")
	UEmailUpdateConfirmation* Body;

	// Beam Base Request Declaration
	UPostEmailUpdateConfirmRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Accounts", DisplayName="Beam - Make PostEmailUpdateConfirm",  meta=(DefaultToSelf="Outer", AdvancedDisplay="Outer"))
	static UPostEmailUpdateConfirmRequest* Make(FString _Code, FString _Password, UObject* Outer);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostEmailUpdateConfirmSuccess, FBeamRequestContext, Context, UPostEmailUpdateConfirmRequest*, Request, UEmptyResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostEmailUpdateConfirmError, FBeamRequestContext, Context, UPostEmailUpdateConfirmRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnPostEmailUpdateConfirmComplete, FBeamRequestContext, Context, UPostEmailUpdateConfirmRequest*, Request);

using FPostEmailUpdateConfirmFullResponse = FBeamFullResponse<UPostEmailUpdateConfirmRequest*, UEmptyResponse*>;
DECLARE_DELEGATE_OneParam(FOnPostEmailUpdateConfirmFullResponse, FPostEmailUpdateConfirmFullResponse);
