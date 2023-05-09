#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"


#include "RoleMapping.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API URoleMapping : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Project Id", Category="Beam")
	FString ProjectId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Role", Category="Beam")
	FString Role;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
	
};