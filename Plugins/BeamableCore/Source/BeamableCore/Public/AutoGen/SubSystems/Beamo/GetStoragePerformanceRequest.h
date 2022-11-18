
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"

#include "AutoGen/Optionals/OptionalString.h"

#include "AutoGen/PerformanceResponse.h"

#include "GetStoragePerformanceRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UGetStoragePerformanceRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="End Date", Category="Beam")
	FOptionalString EndDate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Storage Object Name", Category="Beam")
	FString StorageObjectName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Granularity", Category="Beam")
	FString Granularity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Start Date", Category="Beam")
	FOptionalString StartDate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Period", Category="Beam")
	FOptionalString Period;

	// Body Params
	

	// Beam Base Request Declaration
	UGetStoragePerformanceRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Beamo", DisplayName="Beam - Make GetStoragePerformance",  meta=(DefaultToSelf="RequestOwner", AdvancedDisplay="_EndDate,_StartDate,_Period,RequestOwner"))
	static UGetStoragePerformanceRequest* Make(FOptionalString _EndDate, FString _StorageObjectName, FString _Granularity, FOptionalString _StartDate, FOptionalString _Period, UObject* RequestOwner);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetStoragePerformanceSuccess, FBeamRequestContext, Context, UGetStoragePerformanceRequest*, Request, UPerformanceResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetStoragePerformanceError, FBeamRequestContext, Context, UGetStoragePerformanceRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnGetStoragePerformanceComplete, FBeamRequestContext, Context, UGetStoragePerformanceRequest*, Request);

using FGetStoragePerformanceFullResponse = FBeamFullResponse<UGetStoragePerformanceRequest*, UPerformanceResponse*>;
DECLARE_DELEGATE_OneParam(FOnGetStoragePerformanceFullResponse, FGetStoragePerformanceFullResponse);
