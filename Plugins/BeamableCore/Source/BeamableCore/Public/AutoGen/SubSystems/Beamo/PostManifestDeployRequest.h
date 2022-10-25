
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"

#include "AutoGen/EmptyResponse.h"

#include "PostManifestDeployRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UPostManifestDeployRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	

	// Body Params
	

	// Beam Base Request Declaration
	UPostManifestDeployRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Beamo", DisplayName="Beam - Make PostManifestDeploy",  meta=(DefaultToSelf="Outer", AdvancedDisplay="Outer"))
	static UPostManifestDeployRequest* Make(UObject* Outer);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostManifestDeploySuccess, FBeamRequestContext, Context, UPostManifestDeployRequest*, Request, UEmptyResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostManifestDeployError, FBeamRequestContext, Context, UPostManifestDeployRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnPostManifestDeployComplete, FBeamRequestContext, Context, UPostManifestDeployRequest*, Request);

using FPostManifestDeployFullResponse = FBeamFullResponse<UPostManifestDeployRequest*, UEmptyResponse*>;
DECLARE_DELEGATE_OneParam(FOnPostManifestDeployFullResponse, FPostManifestDeployFullResponse);
