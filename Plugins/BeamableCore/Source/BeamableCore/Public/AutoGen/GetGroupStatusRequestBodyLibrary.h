
#pragma once

#include "CoreMinimal.h"
#include "AutoGen/GetGroupStatusRequestBody.h"

#include "GetGroupStatusRequestBodyLibrary.generated.h"


UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UGetGroupStatusRequestBodyLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category="Beam|Json", DisplayName="Beam - GetGroupStatusRequestBody To JSON String")
	static FString GetGroupStatusRequestBodyToJsonString(const UGetGroupStatusRequestBody* Serializable, const bool Pretty);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Make GetGroupStatusRequestBody", meta=(DefaultToSelf="Outer", AdvancedDisplay="ContentId, Outer", NativeMakeFunc))
	static UGetGroupStatusRequestBody* Make(FOptionalString ContentId, UObject* Outer);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Break GetGroupStatusRequestBody", meta=(NativeBreakFunc))
	static void Break(const UGetGroupStatusRequestBody* Serializable, FOptionalString& ContentId);
};