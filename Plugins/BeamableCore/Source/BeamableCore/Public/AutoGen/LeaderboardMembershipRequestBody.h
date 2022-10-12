
#pragma once

#include "CoreMinimal.h"
#include "Serialization/BeamJsonSerializable.h"


#include "LeaderboardMembershipRequestBody.generated.h"

UCLASS(BlueprintType)
class ULeaderboardMembershipRequestBody : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Player Id")
	int64 PlayerId;

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};