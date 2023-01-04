
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/Optionals/OptionalMapOfString.h"
#include "AutoGen/Optionals/OptionalArrayOfItemCreateRequestBody.h"

#include "EventInventoryPendingRewards.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UEventInventoryPendingRewards : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="B Empty", Category="Beam")
	bool bEmpty;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Items", Category="Beam")
	FOptionalArrayOfItemCreateRequestBody Items;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Currencies", Category="Beam")
	FOptionalMapOfString Currencies;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};