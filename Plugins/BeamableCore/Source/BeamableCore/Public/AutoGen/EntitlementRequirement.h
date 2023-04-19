
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "BeamableCore/Public/AutoGen/Optionals/OptionalString.h"

#include "EntitlementRequirement.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UEntitlementRequirement : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Symbol", Category="Beam")
	FString Symbol;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Constraint", Category="Beam")
	FString Constraint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="State", Category="Beam")
	FString State;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Specialization", Category="Beam")
	FOptionalString Specialization;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
	
};