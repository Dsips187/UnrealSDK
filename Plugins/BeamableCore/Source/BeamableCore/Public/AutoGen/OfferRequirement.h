#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "BeamableCore/Public/AutoGen/OfferConstraint.h"

#include "OfferRequirement.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UOfferRequirement : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Offer Symbol", Category="Beam")
	FString OfferSymbol;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Purchases", Category="Beam")
	UOfferConstraint* Purchases;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
	
};