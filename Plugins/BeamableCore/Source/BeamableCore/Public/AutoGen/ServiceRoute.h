
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/Enums/WebhookServiceType.h"

#include "ServiceRoute.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UServiceRoute : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Service", Category="Beam")
	FString Service;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Endpoint", Category="Beam")
	FString Endpoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Service Type Str", Category="Beam")
	EWebhookServiceType ServiceTypeStr;

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};