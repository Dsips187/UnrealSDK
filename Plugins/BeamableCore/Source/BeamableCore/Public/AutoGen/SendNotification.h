
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/Optionals/OptionalString.h"

#include "SendNotification.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API USendNotification : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Title", Category="Beam")
	FOptionalString Title;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Body", Category="Beam")
	FOptionalString Body;

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};