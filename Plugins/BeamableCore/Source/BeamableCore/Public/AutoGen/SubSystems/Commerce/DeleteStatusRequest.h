
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"


#include "AutoGen/ClearStatusRequestBody.h"
#include "AutoGen/CommonResponse.h"

#include "DeleteStatusRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UDeleteStatusRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Object Id", Category="Beam")
	int64 ObjectId;
	
	// Query Params
	

	// Body Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="", Category="Beam")
	UClearStatusRequestBody* Body;

	// Beam Base Request Declaration
	UDeleteStatusRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Commerce", DisplayName="Beam - Make DeleteStatus",  meta=(DefaultToSelf="Outer", AdvancedDisplay="Outer"))
	static UDeleteStatusRequest* Make(int64 _ObjectId, FString _Store, UObject* Outer);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnDeleteStatusSuccess, FBeamRequestContext, Context, UDeleteStatusRequest*, Request, UCommonResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnDeleteStatusError, FBeamRequestContext, Context, UDeleteStatusRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnDeleteStatusComplete, FBeamRequestContext, Context, UDeleteStatusRequest*, Request);

using FDeleteStatusFullResponse = FBeamFullResponse<UDeleteStatusRequest*, UCommonResponse*>;
DECLARE_DELEGATE_OneParam(FOnDeleteStatusFullResponse, FDeleteStatusFullResponse);
