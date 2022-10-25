
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"


#include "AutoGen/StatUpdateRequestBody.h"
#include "AutoGen/EmptyResponse.h"

#include "PostClientRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UPostClientRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Object Id", Category="Beam")
	FString ObjectId;
	
	// Query Params
	

	// Body Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="", Category="Beam")
	UStatUpdateRequestBody* Body;

	// Beam Base Request Declaration
	UPostClientRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Stats", DisplayName="Beam - Make PostClient",  meta=(DefaultToSelf="Outer", AdvancedDisplay="_bEmitAnalytics,Body_ObjectId,_Set,_Add,Outer"))
	static UPostClientRequest* Make(FString _ObjectId, FOptionalBool _bEmitAnalytics, FOptionalString Body_ObjectId, FOptionalMapOfString _Set, FOptionalMapOfString _Add, UObject* Outer);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostClientSuccess, FBeamRequestContext, Context, UPostClientRequest*, Request, UEmptyResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostClientError, FBeamRequestContext, Context, UPostClientRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnPostClientComplete, FBeamRequestContext, Context, UPostClientRequest*, Request);

using FPostClientFullResponse = FBeamFullResponse<UPostClientRequest*, UEmptyResponse*>;
DECLARE_DELEGATE_OneParam(FOnPostClientFullResponse, FPostClientFullResponse);
