
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"

#include "AutoGen/UpdateGameHierarchyRequestBody.h"
#include "AutoGen/CommonResponse.h"

#include "PutGameRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UPutGameRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	

	// Body Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="", Category="Beam")
	UUpdateGameHierarchyRequestBody* Body;

	// Beam Base Request Declaration
	UPutGameRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Realms", DisplayName="Beam - Make PutGame",  meta=(DefaultToSelf="Outer", AdvancedDisplay="Outer"))
	static UPutGameRequest* Make(FString _RootPID, TArray<UProjectView*> _Projects, UObject* Outer);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPutGameSuccess, FBeamRequestContext, Context, UPutGameRequest*, Request, UCommonResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPutGameError, FBeamRequestContext, Context, UPutGameRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnPutGameComplete, FBeamRequestContext, Context, UPutGameRequest*, Request);

using FPutGameFullResponse = FBeamFullResponse<UPutGameRequest*, UCommonResponse*>;
DECLARE_DELEGATE_OneParam(FOnPutGameFullResponse, FPutGameFullResponse);
