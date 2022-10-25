
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"


#include "FacebookUpdatedEntry.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UFacebookUpdatedEntry : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Id", Category="Beam")
	FString Id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Time", Category="Beam")
	int64 Time;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Changed Fields", Category="Beam")
	TArray<FString> ChangedFields;

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};