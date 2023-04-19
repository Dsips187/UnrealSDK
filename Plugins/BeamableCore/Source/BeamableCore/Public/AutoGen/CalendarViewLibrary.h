
#pragma once

#include "CoreMinimal.h"
#include "BeamableCore/Public/AutoGen/CalendarView.h"

#include "CalendarViewLibrary.generated.h"


UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UCalendarViewLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category="Beam|Json", DisplayName="Beam - CalendarView To JSON String")
	static FString CalendarViewToJsonString(const UCalendarView* Serializable, const bool Pretty);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Make CalendarView", meta=(DefaultToSelf="Outer", AdvancedDisplay="Outer", NativeMakeFunc))
	static UCalendarView* Make(int32 NextIndex, int64 NextClaimSeconds, FString Id, int64 RemainingSeconds, TArray<URewardCalendarDay*> Days, UObject* Outer);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Break CalendarView", meta=(NativeBreakFunc))
	static void Break(const UCalendarView* Serializable, int32& NextIndex, int64& NextClaimSeconds, FString& Id, int64& RemainingSeconds, TArray<URewardCalendarDay*>& Days);
};