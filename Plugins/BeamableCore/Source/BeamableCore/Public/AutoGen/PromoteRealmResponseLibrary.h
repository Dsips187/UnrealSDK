
#pragma once

#include "CoreMinimal.h"
#include "AutoGen/PromoteRealmResponse.h"

#include "PromoteRealmResponseLibrary.generated.h"


UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UPromoteRealmResponseLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category="Beam|Json", DisplayName="Beam - PromoteRealmResponse To JSON String")
	static FString PromoteRealmResponseToJsonString(const UPromoteRealmResponse* Serializable, const bool Pretty);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Make PromoteRealmResponse", meta=(DefaultToSelf="Outer", AdvancedDisplay="Outer", NativeMakeFunc))
	static UPromoteRealmResponse* Make(FString SourcePid, TArray<UPromotionScope*> Scopes, UObject* Outer);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Break PromoteRealmResponse", meta=(NativeBreakFunc))
	static void Break(const UPromoteRealmResponse* Serializable, FString& SourcePid, TArray<UPromotionScope*>& Scopes);
};