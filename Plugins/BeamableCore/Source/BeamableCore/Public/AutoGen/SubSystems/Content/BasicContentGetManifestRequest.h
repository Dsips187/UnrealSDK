
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"

#include "AutoGen/Optionals/OptionalBeamContentManifestId.h"
#include "AutoGen/ContentBasicManifest.h"

#include "BasicContentGetManifestRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UBasicContentGetManifestRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Id", Category="Beam")
	FOptionalBeamContentManifestId Id;

	// Body Params
	

	// Beam Base Request Declaration
	UBasicContentGetManifestRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Content", DisplayName="Beam - Make BasicContentGetManifest",  meta=(DefaultToSelf="RequestOwner", AdvancedDisplay="_Id,RequestOwner"))
	static UBasicContentGetManifestRequest* Make(FOptionalBeamContentManifestId _Id, UObject* RequestOwner);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnBasicContentGetManifestSuccess, FBeamRequestContext, Context, UBasicContentGetManifestRequest*, Request, UContentBasicManifest*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnBasicContentGetManifestError, FBeamRequestContext, Context, UBasicContentGetManifestRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnBasicContentGetManifestComplete, FBeamRequestContext, Context, UBasicContentGetManifestRequest*, Request);

using FBasicContentGetManifestFullResponse = FBeamFullResponse<UBasicContentGetManifestRequest*, UContentBasicManifest*>;
DECLARE_DELEGATE_OneParam(FOnBasicContentGetManifestFullResponse, FBasicContentGetManifestFullResponse);