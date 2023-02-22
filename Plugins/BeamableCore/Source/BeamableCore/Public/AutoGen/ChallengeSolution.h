
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"


#include "ChallengeSolution.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UChallengeSolution : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Challenge Token", Category="Beam")
	FString ChallengeToken;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Solution", Category="Beam")
	FString Solution;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
	
};