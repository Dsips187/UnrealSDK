
#pragma once

#include "CoreMinimal.h"
#include "AutoGen/PromotionScope.h"

#include "PromotionScopeLibrary.generated.h"


UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UPromotionScopeLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category="Beam|Json", DisplayName="Beam - PromotionScope To JSON String")
	static FString PromotionScopeToJsonString(const UPromotionScope* Serializable, const bool Pretty);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Make PromotionScope", meta=(DefaultToSelf="Outer", AdvancedDisplay="Outer", NativeMakeFunc))
	static UPromotionScope* Make(FString Name, TArray<UPromotion*> Promotions, UObject* Outer);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Break PromotionScope", meta=(NativeBreakFunc))
	static void Break(const UPromotionScope* Serializable, FString& Name, TArray<UPromotion*>& Promotions);
};