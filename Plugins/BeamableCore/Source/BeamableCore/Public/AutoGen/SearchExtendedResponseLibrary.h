
#pragma once

#include "CoreMinimal.h"
#include "AutoGen/SearchExtendedResponse.h"

#include "SearchExtendedResponseLibrary.generated.h"


UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API USearchExtendedResponseLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category="Beam|Json", DisplayName="Beam - SearchExtendedResponse To JSON String")
	static FString SearchExtendedResponseToJsonString(const USearchExtendedResponse* Serializable, const bool Pretty);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Make SearchExtendedResponse", meta=(DefaultToSelf="Outer", AdvancedDisplay="Outer", NativeMakeFunc))
	static USearchExtendedResponse* Make(TMap<FString, FMapOfString> GamerStats, UObject* Outer);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Break SearchExtendedResponse", meta=(NativeBreakFunc))
	static void Break(const USearchExtendedResponse* Serializable, TMap<FString, FMapOfString>& GamerStats);
};