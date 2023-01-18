
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"

#include "AutoGen/ArchiveOrUnarchiveManifestsRequestBody.h"
#include "AutoGen/EmptyResponse.h"

#include "PostManifestsArchiveRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UPostManifestsArchiveRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	

	// Body Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="", Category="Beam")
	UArchiveOrUnarchiveManifestsRequestBody* Body;

	// Beam Base Request Declaration
	UPostManifestsArchiveRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Content", DisplayName="Beam - Make PostManifestsArchive",  meta=(DefaultToSelf="RequestOwner", AdvancedDisplay="RequestOwner"))
	static UPostManifestsArchiveRequest* Make(TArray<FBeamContentManifestId> _ManifestIds, UObject* RequestOwner);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostManifestsArchiveSuccess, FBeamRequestContext, Context, UPostManifestsArchiveRequest*, Request, UEmptyResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostManifestsArchiveError, FBeamRequestContext, Context, UPostManifestsArchiveRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnPostManifestsArchiveComplete, FBeamRequestContext, Context, UPostManifestsArchiveRequest*, Request);

using FPostManifestsArchiveFullResponse = FBeamFullResponse<UPostManifestsArchiveRequest*, UEmptyResponse*>;
DECLARE_DELEGATE_OneParam(FOnPostManifestsArchiveFullResponse, FPostManifestsArchiveFullResponse);
