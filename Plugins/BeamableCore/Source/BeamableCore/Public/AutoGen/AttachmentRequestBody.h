#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "BeamableCore/Public/AutoGen/Optionals/OptionalInt32.h"
#include "BeamableCore/Public/AutoGen/Optionals/OptionalString.h"
#include "BeamableCore/Public/AutoGen/Optionals/OptionalInt64.h"

#include "AttachmentRequestBody.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UAttachmentRequestBody : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Symbol", Category="Beam")
	FString Symbol;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Action", Category="Beam")
	FString Action;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Quantity", Category="Beam")
	FOptionalInt32 Quantity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Specialization", Category="Beam")
	FOptionalString Specialization;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Target", Category="Beam")
	FOptionalInt64 Target;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
	
};