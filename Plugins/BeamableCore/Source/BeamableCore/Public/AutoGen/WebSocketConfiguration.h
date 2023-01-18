
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/Optionals/OptionalString.h"

#include "WebSocketConfiguration.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UWebSocketConfiguration : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Provider", Category="Beam")
	FString Provider;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Uri", Category="Beam")
	FOptionalString Uri;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};