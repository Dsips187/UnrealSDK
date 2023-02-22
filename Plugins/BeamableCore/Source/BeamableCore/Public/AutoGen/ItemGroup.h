
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/Item.h"

#include "ItemGroup.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UItemGroup : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Id", Category="Beam")
	FString Id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Items", Category="Beam")
	TArray<UItem*> Items;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
	
};