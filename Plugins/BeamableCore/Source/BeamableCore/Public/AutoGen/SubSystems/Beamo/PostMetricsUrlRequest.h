
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"

#include "AutoGen/GetMetricsUrlRequestBody.h"
#include "AutoGen/GetSignedUrlResponse.h"

#include "PostMetricsUrlRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UPostMetricsUrlRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	

	// Body Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="", Category="Beam")
	UGetMetricsUrlRequestBody* Body;

	// Beam Base Request Declaration
	UPostMetricsUrlRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Beamo", DisplayName="Beam - Make PostMetricsUrl",  meta=(DefaultToSelf="Outer", AdvancedDisplay="_StartTime,_EndTime,_Period,Outer"))
	static UPostMetricsUrlRequest* Make(FString _ServiceName, FString _MetricName, FOptionalInt64 _StartTime, FOptionalInt64 _EndTime, FOptionalInt32 _Period, UObject* Outer);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostMetricsUrlSuccess, FBeamRequestContext, Context, UPostMetricsUrlRequest*, Request, UGetSignedUrlResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostMetricsUrlError, FBeamRequestContext, Context, UPostMetricsUrlRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnPostMetricsUrlComplete, FBeamRequestContext, Context, UPostMetricsUrlRequest*, Request);

using FPostMetricsUrlFullResponse = FBeamFullResponse<UPostMetricsUrlRequest*, UGetSignedUrlResponse*>;
DECLARE_DELEGATE_OneParam(FOnPostMetricsUrlFullResponse, FPostMetricsUrlFullResponse);
