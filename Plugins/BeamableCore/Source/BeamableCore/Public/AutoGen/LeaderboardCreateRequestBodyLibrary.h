
#pragma once

#include "CoreMinimal.h"
#include "BeamableCore/Public/AutoGen/LeaderboardCreateRequestBody.h"

#include "LeaderboardCreateRequestBodyLibrary.generated.h"


UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API ULeaderboardCreateRequestBodyLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category="Beam|Json", DisplayName="Beam - LeaderboardCreateRequestBody To JSON String")
	static FString LeaderboardCreateRequestBodyToJsonString(const ULeaderboardCreateRequestBody* Serializable, const bool Pretty);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Make LeaderboardCreateRequestBody", meta=(DefaultToSelf="Outer", AdvancedDisplay="bPartitioned, FreezeTime, ScoreName, CohortSettings, Permissions, MaxEntries, Ttl, Derivatives, Outer", NativeMakeFunc))
	static ULeaderboardCreateRequestBody* Make(bool bSharded, FOptionalBool bPartitioned, FOptionalInt64 FreezeTime, FOptionalString ScoreName, FOptionalLeaderboardCohortSettings CohortSettings, FOptionalClientPermission Permissions, FOptionalInt32 MaxEntries, FOptionalInt64 Ttl, FOptionalArrayOfString Derivatives, UObject* Outer);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Break LeaderboardCreateRequestBody", meta=(NativeBreakFunc))
	static void Break(const ULeaderboardCreateRequestBody* Serializable, bool& bSharded, FOptionalBool& bPartitioned, FOptionalInt64& FreezeTime, FOptionalString& ScoreName, FOptionalLeaderboardCohortSettings& CohortSettings, FOptionalClientPermission& Permissions, FOptionalInt32& MaxEntries, FOptionalInt64& Ttl, FOptionalArrayOfString& Derivatives);
};