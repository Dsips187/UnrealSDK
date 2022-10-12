
#pragma once

#include "CoreMinimal.h"
#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/PlayerStatus.h"

#include "GetPlayerStatusResponse.generated.h"

UCLASS(BlueprintType)
class UGetPlayerStatusResponse : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Statuses")
	TArray<UPlayerStatus*> Statuses;

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};