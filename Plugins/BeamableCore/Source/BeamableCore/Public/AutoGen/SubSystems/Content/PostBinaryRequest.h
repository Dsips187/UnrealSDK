
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"

#include "AutoGen/SaveBinaryRequestBody.h"
#include "AutoGen/SaveBinaryResponse.h"

#include "PostBinaryRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UPostBinaryRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	

	// Body Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="", Category="Beam")
	USaveBinaryRequestBody* Body;

	// Beam Base Request Declaration
	UPostBinaryRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Content", DisplayName="Beam - Make PostBinary",  meta=(DefaultToSelf="RequestOwner", AdvancedDisplay="RequestOwner"))
	static UPostBinaryRequest* Make(TArray<UBinaryDefinition*> _Binary, UObject* RequestOwner);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostBinarySuccess, FBeamRequestContext, Context, UPostBinaryRequest*, Request, USaveBinaryResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostBinaryError, FBeamRequestContext, Context, UPostBinaryRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnPostBinaryComplete, FBeamRequestContext, Context, UPostBinaryRequest*, Request);

using FPostBinaryFullResponse = FBeamFullResponse<UPostBinaryRequest*, USaveBinaryResponse*>;
DECLARE_DELEGATE_OneParam(FOnPostBinaryFullResponse, FPostBinaryFullResponse);