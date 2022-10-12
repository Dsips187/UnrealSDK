
#pragma once

#include "CoreMinimal.h"
#include "Serialization/BeamJsonSerializable.h"


#include "ItemDeleteRequestBody.generated.h"

UCLASS(BlueprintType)
class UItemDeleteRequestBody : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Content Id")
	FString ContentId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Id")
	int64 Id;

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};