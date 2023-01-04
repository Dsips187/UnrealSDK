
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/Optionals/OptionalArrayOfStatStringListEntry.h"

#include "StatUpdateRequestStringListFormat.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UStatUpdateRequestStringListFormat : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Set", Category="Beam")
	FOptionalArrayOfStatStringListEntry Set;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};