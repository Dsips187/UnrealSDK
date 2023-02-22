
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"


#include "CohortRequirement.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UCohortRequirement : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Trial", Category="Beam")
	FString Trial;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Cohort", Category="Beam")
	FString Cohort;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Constraint", Category="Beam")
	FString Constraint;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
	
};