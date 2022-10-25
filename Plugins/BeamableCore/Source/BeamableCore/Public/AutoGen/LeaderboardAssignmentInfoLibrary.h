
#pragma once

#include "CoreMinimal.h"
#include "AutoGen/LeaderboardAssignmentInfo.h"

#include "LeaderboardAssignmentInfoLibrary.generated.h"


UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API ULeaderboardAssignmentInfoLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category="Beam|Json", DisplayName="Beam - LeaderboardAssignmentInfo To JSON String")
	static FString LeaderboardAssignmentInfoToJsonString(const ULeaderboardAssignmentInfo* Serializable, const bool Pretty);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Make LeaderboardAssignmentInfo", meta=(DefaultToSelf="Outer", AdvancedDisplay="Outer", NativeMakeFunc))
	static ULeaderboardAssignmentInfo* Make(int64 PlayerId, FString LeaderboardId, UObject* Outer);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Break LeaderboardAssignmentInfo", meta=(NativeBreakFunc))
	static void Break(const ULeaderboardAssignmentInfo* Serializable, int64& PlayerId, FString& LeaderboardId);
};