
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"


#include "AutoGen/AccountAvailableResponse.h"

#include "GetAvailableDeviceIdRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UGetAvailableDeviceIdRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Device Id", Category="Beam")
	FString DeviceId;

	// Body Params
	

	// Beam Base Request Declaration
	UGetAvailableDeviceIdRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Accounts", DisplayName="Beam - Make GetAvailableDeviceId",  meta=(DefaultToSelf="RequestOwner", AdvancedDisplay="RequestOwner"))
	static UGetAvailableDeviceIdRequest* Make(FString _DeviceId, UObject* RequestOwner);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetAvailableDeviceIdSuccess, FBeamRequestContext, Context, UGetAvailableDeviceIdRequest*, Request, UAccountAvailableResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetAvailableDeviceIdError, FBeamRequestContext, Context, UGetAvailableDeviceIdRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnGetAvailableDeviceIdComplete, FBeamRequestContext, Context, UGetAvailableDeviceIdRequest*, Request);

using FGetAvailableDeviceIdFullResponse = FBeamFullResponse<UGetAvailableDeviceIdRequest*, UAccountAvailableResponse*>;
DECLARE_DELEGATE_OneParam(FOnGetAvailableDeviceIdFullResponse, FGetAvailableDeviceIdFullResponse);
