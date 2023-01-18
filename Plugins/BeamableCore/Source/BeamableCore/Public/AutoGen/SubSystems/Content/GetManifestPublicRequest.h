
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"

#include "AutoGen/Optionals/OptionalBeamContentManifestId.h"
#include "AutoGen/ClientManifestCsvResponse.h"

#include "GetManifestPublicRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UGetManifestPublicRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Id", Category="Beam")
	FOptionalBeamContentManifestId Id;

	// Body Params
	

	// Beam Base Request Declaration
	UGetManifestPublicRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Content", DisplayName="Beam - Make GetManifestPublic",  meta=(DefaultToSelf="RequestOwner", AdvancedDisplay="_Id,RequestOwner"))
	static UGetManifestPublicRequest* Make(FOptionalBeamContentManifestId _Id, UObject* RequestOwner);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetManifestPublicSuccess, FBeamRequestContext, Context, UGetManifestPublicRequest*, Request, UClientManifestCsvResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetManifestPublicError, FBeamRequestContext, Context, UGetManifestPublicRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnGetManifestPublicComplete, FBeamRequestContext, Context, UGetManifestPublicRequest*, Request);

using FGetManifestPublicFullResponse = FBeamFullResponse<UGetManifestPublicRequest*, UClientManifestCsvResponse*>;
DECLARE_DELEGATE_OneParam(FOnGetManifestPublicFullResponse, FGetManifestPublicFullResponse);