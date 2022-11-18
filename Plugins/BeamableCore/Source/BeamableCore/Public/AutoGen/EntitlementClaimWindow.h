
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"


#include "EntitlementClaimWindow.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UEntitlementClaimWindow : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Open", Category="Beam")
	int64 Open;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Close", Category="Beam")
	int64 Close;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};