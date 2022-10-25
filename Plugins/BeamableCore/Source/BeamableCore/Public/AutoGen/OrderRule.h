
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"


#include "OrderRule.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UOrderRule : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="V", Category="Beam")
	FString V;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="O", Category="Beam")
	int32 O;

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};