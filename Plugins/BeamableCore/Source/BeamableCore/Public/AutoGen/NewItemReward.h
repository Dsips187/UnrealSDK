
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "BeamableCore/Public/AutoGen/Optionals/OptionalMapOfString.h"

#include "NewItemReward.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UNewItemReward : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Symbol", Category="Beam")
	FString Symbol;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Properties", Category="Beam")
	FOptionalMapOfString Properties;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
	
};