
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/Optionals/OptionalArrayOfEventRule.h"

#include "EventPhase.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UEventPhase : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Name", Category="Beam")
	FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Duration Minutes", Category="Beam")
	int32 DurationMinutes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Duration Millis", Category="Beam")
	int64 DurationMillis;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Duration Seconds", Category="Beam")
	int64 DurationSeconds;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Rules", Category="Beam")
	FOptionalArrayOfEventRule Rules;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
	
};