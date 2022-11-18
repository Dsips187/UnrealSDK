
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"

#include "AutoGen/Optionals/OptionalBool.h"
#include "AutoGen/GetCurrentManifestResponse.h"

#include "GetManifestCurrentRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UGetManifestCurrentRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="B Archived", Category="Beam")
	FOptionalBool bArchived;

	// Body Params
	

	// Beam Base Request Declaration
	UGetManifestCurrentRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Beamo", DisplayName="Beam - Make GetManifestCurrent",  meta=(DefaultToSelf="RequestOwner", AdvancedDisplay="_bArchived,RequestOwner"))
	static UGetManifestCurrentRequest* Make(FOptionalBool _bArchived, UObject* RequestOwner);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetManifestCurrentSuccess, FBeamRequestContext, Context, UGetManifestCurrentRequest*, Request, UGetCurrentManifestResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetManifestCurrentError, FBeamRequestContext, Context, UGetManifestCurrentRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnGetManifestCurrentComplete, FBeamRequestContext, Context, UGetManifestCurrentRequest*, Request);

using FGetManifestCurrentFullResponse = FBeamFullResponse<UGetManifestCurrentRequest*, UGetCurrentManifestResponse*>;
DECLARE_DELEGATE_OneParam(FOnGetManifestCurrentFullResponse, FGetManifestCurrentFullResponse);
