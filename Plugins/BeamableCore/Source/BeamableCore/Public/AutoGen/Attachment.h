
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "BeamableCore/Public/AutoGen/EntitlementGenerator.h"
#include "BeamableCore/Public/AutoGen/Optionals/OptionalInt64.h"

#include "Attachment.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UAttachment : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Id", Category="Beam")
	int64 Id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Wrapped", Category="Beam")
	UEntitlementGenerator* Wrapped;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="State", Category="Beam")
	FString State;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Target", Category="Beam")
	FOptionalInt64 Target;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
	
};