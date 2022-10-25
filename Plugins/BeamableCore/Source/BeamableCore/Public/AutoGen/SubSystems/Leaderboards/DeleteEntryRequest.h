
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"


#include "AutoGen/LeaderboardRemoveEntryRequestBody.h"
#include "AutoGen/CommonResponse.h"

#include "DeleteEntryRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UDeleteEntryRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Object Id", Category="Beam")
	FString ObjectId;
	
	// Query Params
	

	// Body Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="", Category="Beam")
	ULeaderboardRemoveEntryRequestBody* Body;

	// Beam Base Request Declaration
	UDeleteEntryRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Leaderboards", DisplayName="Beam - Make DeleteEntry",  meta=(DefaultToSelf="Outer", AdvancedDisplay="Outer"))
	static UDeleteEntryRequest* Make(FString _ObjectId, int64 _Id, UObject* Outer);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnDeleteEntrySuccess, FBeamRequestContext, Context, UDeleteEntryRequest*, Request, UCommonResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnDeleteEntryError, FBeamRequestContext, Context, UDeleteEntryRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnDeleteEntryComplete, FBeamRequestContext, Context, UDeleteEntryRequest*, Request);

using FDeleteEntryFullResponse = FBeamFullResponse<UDeleteEntryRequest*, UCommonResponse*>;
DECLARE_DELEGATE_OneParam(FOnDeleteEntryFullResponse, FDeleteEntryFullResponse);
