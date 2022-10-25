
#pragma once

#include "CoreMinimal.h"
#include "AutoGen/EventObjectData.h"

#include "EventObjectDataLibrary.generated.h"


UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UEventObjectDataLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category="Beam|Json", DisplayName="Beam - EventObjectData To JSON String")
	static FString EventObjectDataToJsonString(const UEventObjectData* Serializable, const bool Pretty);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Make EventObjectData", meta=(DefaultToSelf="Outer", AdvancedDisplay="LastChildEventId, StartTime, RootEventId, OriginType, Phase, Permissions, EndTime, Origin, CreatedAt, InFlight, PhaseTimes, Outer", NativeMakeFunc))
	static UEventObjectData* Make(bool bDone, bool bRunning, EEventState State, FString LeaderboardId, FString Id, UEvent* Content, FOptionalString LastChildEventId, FOptionalInt64 StartTime, FOptionalString RootEventId, FOptionalString OriginType, FOptionalEventPhaseRuntime Phase, FOptionalClientPermission Permissions, FOptionalInt64 EndTime, FOptionalString Origin, FOptionalInt64 CreatedAt, FOptionalArrayOfInFlightMessage InFlight, FOptionalArrayOfEventPhaseTime PhaseTimes, UObject* Outer);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Break EventObjectData", meta=(NativeBreakFunc))
	static void Break(const UEventObjectData* Serializable, bool& bDone, bool& bRunning, EEventState& State, FString& LeaderboardId, FString& Id, UEvent*& Content, FOptionalString& LastChildEventId, FOptionalInt64& StartTime, FOptionalString& RootEventId, FOptionalString& OriginType, FOptionalEventPhaseRuntime& Phase, FOptionalClientPermission& Permissions, FOptionalInt64& EndTime, FOptionalString& Origin, FOptionalInt64& CreatedAt, FOptionalArrayOfInFlightMessage& InFlight, FOptionalArrayOfEventPhaseTime& PhaseTimes);
};