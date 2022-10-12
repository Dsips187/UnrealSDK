
#pragma once

#include "CoreMinimal.h"
#include "Serialization/BeamJsonSerializable.h"


#include "RankEntryStat.generated.h"

UCLASS(BlueprintType)
class URankEntryStat : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Name")
	FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Value")
	FString Value;

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};