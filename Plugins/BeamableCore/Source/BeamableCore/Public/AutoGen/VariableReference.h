
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"


#include "VariableReference.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UVariableReference : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Name", Category="Beam")
	FString Name;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
	
};