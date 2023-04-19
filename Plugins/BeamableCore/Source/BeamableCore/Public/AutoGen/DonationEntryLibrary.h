
#pragma once

#include "CoreMinimal.h"
#include "BeamableCore/Public/AutoGen/DonationEntry.h"

#include "DonationEntryLibrary.generated.h"


UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UDonationEntryLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category="Beam|Json", DisplayName="Beam - DonationEntry To JSON String")
	static FString DonationEntryToJsonString(const UDonationEntry* Serializable, const bool Pretty);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Make DonationEntry", meta=(DefaultToSelf="Outer", AdvancedDisplay="bClaimed, Outer", NativeMakeFunc))
	static UDonationEntry* Make(int64 PlayerId, int64 Amount, int64 Time, FOptionalBool bClaimed, UObject* Outer);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Break DonationEntry", meta=(NativeBreakFunc))
	static void Break(const UDonationEntry* Serializable, int64& PlayerId, int64& Amount, int64& Time, FOptionalBool& bClaimed);
};