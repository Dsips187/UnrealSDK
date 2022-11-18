
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"

#include "AutoGen/BatchSetStatsRequestBody.h"
#include "AutoGen/EmptyResponse.h"

#include "PostBatchRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UPostBatchRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	

	// Body Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="", Category="Beam")
	UBatchSetStatsRequestBody* Body;

	// Beam Base Request Declaration
	UPostBatchRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Stats", DisplayName="Beam - Make PostBatch",  meta=(DefaultToSelf="RequestOwner", AdvancedDisplay="RequestOwner"))
	static UPostBatchRequest* Make(TArray<UStatUpdateRequestBody*> _Updates, UObject* RequestOwner);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostBatchSuccess, FBeamRequestContext, Context, UPostBatchRequest*, Request, UEmptyResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostBatchError, FBeamRequestContext, Context, UPostBatchRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnPostBatchComplete, FBeamRequestContext, Context, UPostBatchRequest*, Request);

using FPostBatchFullResponse = FBeamFullResponse<UPostBatchRequest*, UEmptyResponse*>;
DECLARE_DELEGATE_OneParam(FOnPostBatchFullResponse, FPostBatchFullResponse);
