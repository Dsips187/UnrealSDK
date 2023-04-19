
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "BeamableCore/Public/AutoGen/Optionals/OptionalString.h"

#include "ServerEvent.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UServerEvent : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Event", Category="Beam")
	FString Event;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="B To All", Category="Beam")
	bool bToAll;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Payload", Category="Beam")
	FOptionalString Payload;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
	
};