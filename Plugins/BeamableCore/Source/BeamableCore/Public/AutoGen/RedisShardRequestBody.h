
#pragma once

#include "CoreMinimal.h"
#include "Serialization/BeamJsonSerializable.h"


#include "RedisShardRequestBody.generated.h"

UCLASS(BlueprintType)
class URedisShardRequestBody : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Shard Id")
	int32 ShardId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Master Host")
	FString MasterHost;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Slave Hosts")
	FString SlaveHosts;

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};