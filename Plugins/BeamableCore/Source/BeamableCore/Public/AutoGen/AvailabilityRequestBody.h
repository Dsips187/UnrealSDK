
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/Optionals/OptionalString.h"
#include "AutoGen/Enums/GroupType.h"
#include "AutoGen/Optionals/OptionalBool.h"

#include "AvailabilityRequestBody.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UAvailabilityRequestBody : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Type", Category="Beam")
	EGroupType Type;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="B Sub Group", Category="Beam")
	FOptionalBool bSubGroup;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Name", Category="Beam")
	FOptionalString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Tag", Category="Beam")
	FOptionalString Tag;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};