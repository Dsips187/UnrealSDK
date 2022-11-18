
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/MatchMakingRanking.h"

#include "MatchMakingWindowResp.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UMatchMakingWindowResp : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Difficulty", Category="Beam")
	int32 Difficulty;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Matches", Category="Beam")
	TArray<UMatchMakingRanking*> Matches;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};