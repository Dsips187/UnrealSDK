
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"

#include "AutoGen/NotificationRequestBody.h"
#include "AutoGen/CommonResponse.h"

#include "PostPlayerRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UPostPlayerRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	

	// Body Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="", Category="Beam")
	UNotificationRequestBody* Body;

	// Beam Base Request Declaration
	UPostPlayerRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Notification", DisplayName="Beam - Make PostPlayer",  meta=(DefaultToSelf="Outer", AdvancedDisplay="_bUseSignalWhenPossible,_CustomChannelSuffix,_Dbid,_Dbids,Outer"))
	static UPostPlayerRequest* Make(UNotificationRequestData* _Payload, FOptionalBool _bUseSignalWhenPossible, FOptionalString _CustomChannelSuffix, FOptionalInt64 _Dbid, FOptionalArrayOfInt64 _Dbids, UObject* Outer);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostPlayerSuccess, FBeamRequestContext, Context, UPostPlayerRequest*, Request, UCommonResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostPlayerError, FBeamRequestContext, Context, UPostPlayerRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnPostPlayerComplete, FBeamRequestContext, Context, UPostPlayerRequest*, Request);

using FPostPlayerFullResponse = FBeamFullResponse<UPostPlayerRequest*, UCommonResponse*>;
DECLARE_DELEGATE_OneParam(FOnPostPlayerFullResponse, FPostPlayerFullResponse);
