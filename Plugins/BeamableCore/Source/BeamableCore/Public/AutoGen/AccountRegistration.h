#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"


#include "AccountRegistration.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UAccountRegistration : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Email", Category="Beam")
	FString Email;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Password", Category="Beam")
	FString Password;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
	
};