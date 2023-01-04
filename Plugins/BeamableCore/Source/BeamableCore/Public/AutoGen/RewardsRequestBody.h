
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/Optionals/OptionalString.h"

#include "RewardsRequestBody.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API URewardsRequestBody : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Tournament Id", Category="Beam")
	FOptionalString TournamentId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Content Id", Category="Beam")
	FOptionalString ContentId;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};