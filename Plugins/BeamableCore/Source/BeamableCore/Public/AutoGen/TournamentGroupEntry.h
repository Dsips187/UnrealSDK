
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "BeamableCore/Public/AutoGen/TournamentCurrencyReward.h"

#include "TournamentGroupEntry.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UTournamentGroupEntry : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Rank", Category="Beam")
	int64 Rank;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Score", Category="Beam")
	double Score;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Group Id", Category="Beam")
	int64 GroupId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Stage Change", Category="Beam")
	int32 StageChange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Currency Rewards", Category="Beam")
	TArray<UTournamentCurrencyReward*> CurrencyRewards;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
	
};