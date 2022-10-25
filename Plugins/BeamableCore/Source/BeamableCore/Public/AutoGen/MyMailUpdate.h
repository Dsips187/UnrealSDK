
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/UpdateMailRequestBody.h"

#include "MyMailUpdate.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UMyMailUpdate : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Id", Category="Beam")
	int64 Id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Update", Category="Beam")
	UUpdateMailRequestBody* Update;

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};