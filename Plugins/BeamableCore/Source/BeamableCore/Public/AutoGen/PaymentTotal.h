#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "BeamableCore/Public/AutoGen/Optionals/OptionalString.h"

#include "PaymentTotal.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UPaymentTotal : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Total Revenue", Category="Beam")
	int64 TotalRevenue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Currency Code", Category="Beam")
	FOptionalString CurrencyCode;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
	
};