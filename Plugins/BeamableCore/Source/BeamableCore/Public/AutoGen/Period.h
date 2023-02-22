
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/Optionals/OptionalString.h"

#include "Period.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UPeriod : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Start", Category="Beam")
	FString Start;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="End", Category="Beam")
	FOptionalString End;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
	
};