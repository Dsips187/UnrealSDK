
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"

#include "AutoGen/SaveCatalogRequestBody.h"
#include "AutoGen/ResultResponse.h"

#include "PostCatalogLegacyRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UPostCatalogLegacyRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	

	// Body Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="", Category="Beam")
	USaveCatalogRequestBody* Body;

	// Beam Base Request Declaration
	UPostCatalogLegacyRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Commerce", DisplayName="Beam - Make PostCatalogLegacy",  meta=(DefaultToSelf="RequestOwner", AdvancedDisplay="RequestOwner"))
	static UPostCatalogLegacyRequest* Make(TArray<UStore*> _Stores, TArray<UOfferDefinition*> _OfferDefinitions, UObject* RequestOwner);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostCatalogLegacySuccess, FBeamRequestContext, Context, UPostCatalogLegacyRequest*, Request, UResultResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostCatalogLegacyError, FBeamRequestContext, Context, UPostCatalogLegacyRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnPostCatalogLegacyComplete, FBeamRequestContext, Context, UPostCatalogLegacyRequest*, Request);

using FPostCatalogLegacyFullResponse = FBeamFullResponse<UPostCatalogLegacyRequest*, UResultResponse*>;
DECLARE_DELEGATE_OneParam(FOnPostCatalogLegacyFullResponse, FPostCatalogLegacyFullResponse);
