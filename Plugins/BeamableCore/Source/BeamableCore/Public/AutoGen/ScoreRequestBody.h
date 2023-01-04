
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/Optionals/OptionalMapOfString.h"
#include "AutoGen/Optionals/OptionalBool.h"

#include "ScoreRequestBody.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UScoreRequestBody : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Tournament Id", Category="Beam")
	FString TournamentId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Score", Category="Beam")
	double Score;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Player Id", Category="Beam")
	int64 PlayerId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="B Increment", Category="Beam")
	FOptionalBool bIncrement;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Stats", Category="Beam")
	FOptionalMapOfString Stats;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};