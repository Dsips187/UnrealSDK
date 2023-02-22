
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/SKU.h"

#include "SKUDefinitions.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API USKUDefinitions : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Version", Category="Beam")
	int64 Version;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Created", Category="Beam")
	int64 Created;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Definitions", Category="Beam")
	TArray<USKU*> Definitions;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
	
};