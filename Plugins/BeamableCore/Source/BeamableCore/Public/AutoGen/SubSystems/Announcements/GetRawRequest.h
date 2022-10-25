
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"


#include "AutoGen/AnnouncementRawResponse.h"

#include "GetRawRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UGetRawRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Object Id", Category="Beam")
	int64 ObjectId;
	
	// Query Params
	

	// Body Params
	

	// Beam Base Request Declaration
	UGetRawRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Announcements", DisplayName="Beam - Make GetRaw",  meta=(DefaultToSelf="Outer", AdvancedDisplay="Outer"))
	static UGetRawRequest* Make(int64 _ObjectId, UObject* Outer);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetRawSuccess, FBeamRequestContext, Context, UGetRawRequest*, Request, UAnnouncementRawResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetRawError, FBeamRequestContext, Context, UGetRawRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnGetRawComplete, FBeamRequestContext, Context, UGetRawRequest*, Request);

using FGetRawFullResponse = FBeamFullResponse<UGetRawRequest*, UAnnouncementRawResponse*>;
DECLARE_DELEGATE_OneParam(FOnGetRawFullResponse, FGetRawFullResponse);
