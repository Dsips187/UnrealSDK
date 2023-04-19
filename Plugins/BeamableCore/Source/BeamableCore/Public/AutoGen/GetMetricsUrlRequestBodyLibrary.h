
#pragma once

#include "CoreMinimal.h"
#include "BeamableCore/Public/AutoGen/GetMetricsUrlRequestBody.h"

#include "GetMetricsUrlRequestBodyLibrary.generated.h"


UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UGetMetricsUrlRequestBodyLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category="Beam|Json", DisplayName="Beam - GetMetricsUrlRequestBody To JSON String")
	static FString GetMetricsUrlRequestBodyToJsonString(const UGetMetricsUrlRequestBody* Serializable, const bool Pretty);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Make GetMetricsUrlRequestBody", meta=(DefaultToSelf="Outer", AdvancedDisplay="StartTime, EndTime, Period, Outer", NativeMakeFunc))
	static UGetMetricsUrlRequestBody* Make(FString ServiceName, FString MetricName, FOptionalInt64 StartTime, FOptionalInt64 EndTime, FOptionalInt32 Period, UObject* Outer);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Break GetMetricsUrlRequestBody", meta=(NativeBreakFunc))
	static void Break(const UGetMetricsUrlRequestBody* Serializable, FString& ServiceName, FString& MetricName, FOptionalInt64& StartTime, FOptionalInt64& EndTime, FOptionalInt32& Period);
};