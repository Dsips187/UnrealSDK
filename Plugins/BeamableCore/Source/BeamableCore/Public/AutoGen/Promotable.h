#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"


#include "Promotable.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UPromotable : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Checksum", Category="Beam")
	FString Checksum;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Created At", Category="Beam")
	int64 CreatedAt;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
	
};