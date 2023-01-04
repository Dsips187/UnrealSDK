
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/Optionals/OptionalArrayOfString.h"
#include "AutoGen/Optionals/OptionalBool.h"
#include "AutoGen/Optionals/OptionalArrayOfRedisShard.h"

#include "DataDomain.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UDataDomain : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="B Mongo SSL Enabled", Category="Beam")
	bool bMongoSSLEnabled;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="B Mongo Sharded", Category="Beam")
	bool bMongoSharded;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Memcached Hosts", Category="Beam")
	TArray<FString> MemcachedHosts;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Mongo Hosts", Category="Beam")
	TArray<FString> MongoHosts;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="B Mongo SSL", Category="Beam")
	FOptionalBool bMongoSSL;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Message Bus Analytics", Category="Beam")
	FOptionalArrayOfString MessageBusAnalytics;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Message Bus Common", Category="Beam")
	FOptionalArrayOfString MessageBusCommon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Redis Shards", Category="Beam")
	FOptionalArrayOfRedisShard RedisShards;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};