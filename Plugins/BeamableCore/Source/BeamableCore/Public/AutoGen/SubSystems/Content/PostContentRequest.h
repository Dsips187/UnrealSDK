
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"

#include "AutoGen/SaveContentRequestBody.h"
#include "AutoGen/SaveContentResponse.h"

#include "PostContentRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UPostContentRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	

	// Body Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="", Category="Beam")
	USaveContentRequestBody* Body;

	// Beam Base Request Declaration
	UPostContentRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Content", DisplayName="Beam - Make PostContent",  meta=(DefaultToSelf="RequestOwner", AdvancedDisplay="RequestOwner"))
	static UPostContentRequest* Make(TArray<UContentDefinition*> _Content, UObject* RequestOwner);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostContentSuccess, FBeamRequestContext, Context, UPostContentRequest*, Request, USaveContentResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostContentError, FBeamRequestContext, Context, UPostContentRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnPostContentComplete, FBeamRequestContext, Context, UPostContentRequest*, Request);

using FPostContentFullResponse = FBeamFullResponse<UPostContentRequest*, USaveContentResponse*>;
DECLARE_DELEGATE_OneParam(FOnPostContentFullResponse, FPostContentFullResponse);
