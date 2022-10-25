
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"


#include "MatchMakingRanking.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UMatchMakingRanking : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="B Is Unranked", Category="Beam")
	bool bIsUnranked;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Gt", Category="Beam")
	int64 Gt;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Rank", Category="Beam")
	int32 Rank;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Variables", Category="Beam")
	TMap<FString, FString> Variables;

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};