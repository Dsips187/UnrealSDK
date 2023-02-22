
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/Optionals/OptionalInt64.h"
#include "AutoGen/Optionals/OptionalString.h"

#include "InFlightMessage.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UInFlightMessage : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Method", Category="Beam")
	FString Method;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Body", Category="Beam")
	FString Body;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Path", Category="Beam")
	FString Path;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Service", Category="Beam")
	FString Service;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Id", Category="Beam")
	FString Id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Gamer Tag", Category="Beam")
	FOptionalInt64 GamerTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Shard", Category="Beam")
	FOptionalString Shard;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
	
};