
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/Optionals/OptionalString.h"
#include "AutoGen/Optionals/OptionalArrayOfExternalIdentity.h"
#include "AutoGen/Optionals/OptionalGamerTagAssociation.h"

#include "AccountUpdate.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UAccountUpdate : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="B Has Third Party Token", Category="Beam")
	bool bHasThirdPartyToken;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Third Party", Category="Beam")
	FOptionalString ThirdParty;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Country", Category="Beam")
	FOptionalString Country;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Language", Category="Beam")
	FOptionalString Language;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Gamer Tag Assoc", Category="Beam")
	FOptionalGamerTagAssociation GamerTagAssoc;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Token", Category="Beam")
	FOptionalString Token;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Device Id", Category="Beam")
	FOptionalString DeviceId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="User Name", Category="Beam")
	FOptionalString UserName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="External", Category="Beam")
	FOptionalArrayOfExternalIdentity External;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};