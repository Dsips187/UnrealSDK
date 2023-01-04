
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/Optionals/OptionalString.h"

#include "BeginPurchaseRequestBody.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UBeginPurchaseRequestBody : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Purchase Id", Category="Beam")
	FString PurchaseId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Language", Category="Beam")
	FOptionalString Language;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Time", Category="Beam")
	FOptionalString Time;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};