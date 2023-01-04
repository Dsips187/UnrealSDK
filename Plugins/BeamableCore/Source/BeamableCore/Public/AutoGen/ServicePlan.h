
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/Optionals/OptionalString.h"
#include "AutoGen/DataDomain.h"
#include "AutoGen/Optionals/OptionalServiceLimits.h"
#include "AutoGen/Optionals/OptionalInt64.h"

#include "ServicePlan.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UServicePlan : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Name", Category="Beam")
	FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Data Domain", Category="Beam")
	UDataDomain* DataDomain;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Min Customer Status Saved", Category="Beam")
	FOptionalString MinCustomerStatusSaved;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Limits", Category="Beam")
	FOptionalServiceLimits Limits;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Created", Category="Beam")
	FOptionalInt64 Created;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};