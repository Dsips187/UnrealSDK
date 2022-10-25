
#pragma once

#include "CoreMinimal.h"
#include "AutoGen/RedisShardRequestBody.h"

#include "RedisShardRequestBodyLibrary.generated.h"


UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API URedisShardRequestBodyLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category="Beam|Json", DisplayName="Beam - RedisShardRequestBody To JSON String")
	static FString RedisShardRequestBodyToJsonString(const URedisShardRequestBody* Serializable, const bool Pretty);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Make RedisShardRequestBody", meta=(DefaultToSelf="Outer", AdvancedDisplay="Outer", NativeMakeFunc))
	static URedisShardRequestBody* Make(int32 ShardId, FString MasterHost, FString SlaveHosts, UObject* Outer);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Break RedisShardRequestBody", meta=(NativeBreakFunc))
	static void Break(const URedisShardRequestBody* Serializable, int32& ShardId, FString& MasterHost, FString& SlaveHosts);
};