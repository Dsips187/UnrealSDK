
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/EventRule.h"

#include "EventPlayerPhaseView.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UEventPlayerPhaseView : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Name", Category="Beam")
	FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Duration Seconds", Category="Beam")
	int64 DurationSeconds;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Rules", Category="Beam")
	TArray<UEventRule*> Rules;

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};