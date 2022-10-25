
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"


#include "AutoGen/Optionals/OptionalArrayOfString.h"
#include "AutoGen/PromoteRealmResponseOld.h"

#include "GetProjectPromoteRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UGetProjectPromoteRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Source Pid", Category="Beam")
	FString SourcePid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Promotions", Category="Beam")
	FOptionalArrayOfString Promotions;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Content Manifest Ids", Category="Beam")
	FOptionalArrayOfString ContentManifestIds;

	// Body Params
	

	// Beam Base Request Declaration
	UGetProjectPromoteRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Realms", DisplayName="Beam - Make GetProjectPromote",  meta=(DefaultToSelf="Outer", AdvancedDisplay="_Promotions,_ContentManifestIds,Outer"))
	static UGetProjectPromoteRequest* Make(FString _SourcePid, FOptionalArrayOfString _Promotions, FOptionalArrayOfString _ContentManifestIds, UObject* Outer);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetProjectPromoteSuccess, FBeamRequestContext, Context, UGetProjectPromoteRequest*, Request, UPromoteRealmResponseOld*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetProjectPromoteError, FBeamRequestContext, Context, UGetProjectPromoteRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnGetProjectPromoteComplete, FBeamRequestContext, Context, UGetProjectPromoteRequest*, Request);

using FGetProjectPromoteFullResponse = FBeamFullResponse<UGetProjectPromoteRequest*, UPromoteRealmResponseOld*>;
DECLARE_DELEGATE_OneParam(FOnGetProjectPromoteFullResponse, FGetProjectPromoteFullResponse);
