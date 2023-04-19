
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "BeamableCore/Public/AutoGen/Optionals/OptionalRankEntry.h"
#include "BeamableCore/Public/AutoGen/RankEntry.h"

#include "LeaderBoardView.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API ULeaderBoardView : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Lb Id", Category="Beam")
	FString LbId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Board Size", Category="Beam")
	int64 BoardSize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Rankings", Category="Beam")
	TArray<URankEntry*> Rankings;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Rankgt", Category="Beam")
	FOptionalRankEntry Rankgt;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
	
};