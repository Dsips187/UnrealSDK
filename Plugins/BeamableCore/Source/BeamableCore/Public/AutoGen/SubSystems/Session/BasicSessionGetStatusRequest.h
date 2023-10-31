
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"



#include "BeamableCore/Public/AutoGen/OnlineStatusResponses.h"

#include "BasicSessionGetStatusRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UBasicSessionGetStatusRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Player Ids", Category="Beam")
	FString PlayerIds;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Interval Secs", Category="Beam")
	int64 IntervalSecs;

	// Body Params
	

	// Beam Base Request Declaration
	UBasicSessionGetStatusRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Session", DisplayName="Beam - Make BasicSessionGetStatus",  meta=(DefaultToSelf="RequestOwner", AdvancedDisplay="RequestOwner"))
	static UBasicSessionGetStatusRequest* Make(FString _PlayerIds, int64 _IntervalSecs, UObject* RequestOwner);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnBasicSessionGetStatusSuccess, FBeamRequestContext, Context, UBasicSessionGetStatusRequest*, Request, UOnlineStatusResponses*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnBasicSessionGetStatusError, FBeamRequestContext, Context, UBasicSessionGetStatusRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnBasicSessionGetStatusComplete, FBeamRequestContext, Context, UBasicSessionGetStatusRequest*, Request);

using FBasicSessionGetStatusFullResponse = FBeamFullResponse<UBasicSessionGetStatusRequest*, UOnlineStatusResponses*>;
DECLARE_DELEGATE_OneParam(FOnBasicSessionGetStatusFullResponse, FBasicSessionGetStatusFullResponse);
