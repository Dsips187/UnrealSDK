
#pragma once

#include "CoreMinimal.h"
#include "BeamableCore/Public/AutoGen/Promotion.h"

#include "PromotionLibrary.generated.h"


UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UPromotionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category="Beam|Json", DisplayName="Beam - Promotion To JSON String")
	static FString PromotionToJsonString(const UPromotion* Serializable, const bool Pretty);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Make Promotion", meta=(DefaultToSelf="Outer", AdvancedDisplay="Outer", NativeMakeFunc))
	static UPromotion* Make(FString Id, UPromotable* Source, UPromotable* Destination, UObject* Outer);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Break Promotion", meta=(NativeBreakFunc))
	static void Break(const UPromotion* Serializable, FString& Id, UPromotable*& Source, UPromotable*& Destination);
};