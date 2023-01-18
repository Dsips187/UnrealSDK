
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"

#include "AutoGen/Optionals/OptionalInt64.h"
#include "AutoGen/CloudsavingBasicManifest.h"

#include "GetCloudsavingRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UGetCloudsavingRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Player Id", Category="Beam")
	FOptionalInt64 PlayerId;

	// Body Params
	

	// Beam Base Request Declaration
	UGetCloudsavingRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Cloudsaving", DisplayName="Beam - Make GetCloudsaving",  meta=(DefaultToSelf="RequestOwner", AdvancedDisplay="_PlayerId,RequestOwner"))
	static UGetCloudsavingRequest* Make(FOptionalInt64 _PlayerId, UObject* RequestOwner);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetCloudsavingSuccess, FBeamRequestContext, Context, UGetCloudsavingRequest*, Request, UCloudsavingBasicManifest*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetCloudsavingError, FBeamRequestContext, Context, UGetCloudsavingRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnGetCloudsavingComplete, FBeamRequestContext, Context, UGetCloudsavingRequest*, Request);

using FGetCloudsavingFullResponse = FBeamFullResponse<UGetCloudsavingRequest*, UCloudsavingBasicManifest*>;
DECLARE_DELEGATE_OneParam(FOnGetCloudsavingFullResponse, FGetCloudsavingFullResponse);
