
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"


#include "Link.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API ULink : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Href", Category="Beam")
	FString Href;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Rel", Category="Beam")
	FString Rel;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
	
};