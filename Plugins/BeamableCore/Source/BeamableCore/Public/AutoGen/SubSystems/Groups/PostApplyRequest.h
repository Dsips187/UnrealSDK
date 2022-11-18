
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"


#include "AutoGen/GroupApplication.h"
#include "AutoGen/CommonResponse.h"

#include "PostApplyRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UPostApplyRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Object Id", Category="Beam")
	int64 ObjectId;
	
	// Query Params
	

	// Body Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="", Category="Beam")
	UGroupApplication* Body;

	// Beam Base Request Declaration
	UPostApplyRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Groups", DisplayName="Beam - Make PostApply",  meta=(DefaultToSelf="RequestOwner", AdvancedDisplay="_SubGroup,RequestOwner"))
	static UPostApplyRequest* Make(int64 _ObjectId, FOptionalInt64 _SubGroup, UObject* RequestOwner);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostApplySuccess, FBeamRequestContext, Context, UPostApplyRequest*, Request, UCommonResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostApplyError, FBeamRequestContext, Context, UPostApplyRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnPostApplyComplete, FBeamRequestContext, Context, UPostApplyRequest*, Request);

using FPostApplyFullResponse = FBeamFullResponse<UPostApplyRequest*, UCommonResponse*>;
DECLARE_DELEGATE_OneParam(FOnPostApplyFullResponse, FPostApplyFullResponse);
