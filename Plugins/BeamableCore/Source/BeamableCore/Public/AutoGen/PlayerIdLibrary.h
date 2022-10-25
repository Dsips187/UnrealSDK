
#pragma once

#include "CoreMinimal.h"
#include "AutoGen/PlayerId.h"

#include "PlayerIdLibrary.generated.h"


UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UPlayerIdLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category="Beam|Json", DisplayName="Beam - PlayerId To JSON String")
	static FString PlayerIdToJsonString(const UPlayerId* Serializable, const bool Pretty);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Make PlayerId", meta=(DefaultToSelf="Outer", AdvancedDisplay="Outer", NativeMakeFunc))
	static UPlayerId* Make(FString PlayerId, UObject* Outer);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Break PlayerId", meta=(NativeBreakFunc))
	static void Break(const UPlayerId* Serializable, FString& PlayerId);
};