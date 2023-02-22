
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/UpdateListingCooldownRequestBody.h"

#include "CooldownModifierRequestBody.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UCooldownModifierRequestBody : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Gamer Tag", Category="Beam")
	int64 GamerTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Update Listing Cooldown Requests", Category="Beam")
	TArray<UUpdateListingCooldownRequestBody*> UpdateListingCooldownRequests;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
	
};