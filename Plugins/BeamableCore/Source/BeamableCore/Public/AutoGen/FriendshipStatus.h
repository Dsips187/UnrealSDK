
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseResponseBodyInterface.h"
#include "Serialization/BeamJsonSerializable.h"


#include "FriendshipStatus.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UFriendshipStatus : public UObject, public FBeamJsonSerializable, public IBeamBaseResponseBodyInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="B Is Blocked", Category="Beam")
	bool bIsBlocked;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Friend Id", Category="Beam")
	FString FriendId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Player Id", Category="Beam")
	FString PlayerId;

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};