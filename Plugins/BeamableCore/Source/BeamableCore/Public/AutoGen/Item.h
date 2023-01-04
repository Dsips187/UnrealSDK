
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/Optionals/OptionalInt64.h"
#include "AutoGen/Optionals/OptionalString.h"
#include "AutoGen/ItemProperty.h"

#include "Item.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UItem : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Id", Category="Beam")
	int64 Id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Properties", Category="Beam")
	TArray<UItemProperty*> Properties;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Updated At", Category="Beam")
	FOptionalInt64 UpdatedAt;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Proxy Id", Category="Beam")
	FOptionalString ProxyId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Created At", Category="Beam")
	FOptionalInt64 CreatedAt;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};