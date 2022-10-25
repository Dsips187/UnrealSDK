
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseResponseBodyInterface.h"
#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/EventPlayerStateView.h"

#include "EventClaimResponse.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UEventClaimResponse : public UObject, public FBeamJsonSerializable, public IBeamBaseResponseBodyInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="View", Category="Beam")
	UEventPlayerStateView* View;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Game Rsp Json", Category="Beam")
	FString GameRspJson;

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};