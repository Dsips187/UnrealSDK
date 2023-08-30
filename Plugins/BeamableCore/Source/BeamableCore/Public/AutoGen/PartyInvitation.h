#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "BeamableCore/Public/AutoGen/Optionals/OptionalString.h"

#include "PartyInvitation.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UPartyInvitation : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Party Id", Category="Beam")
	FOptionalString PartyId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Invited By", Category="Beam")
	FOptionalString InvitedBy;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
	
};