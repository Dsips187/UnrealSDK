
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/Optionals/OptionalString.h"
#include "AutoGen/Optionals/OptionalArrayOfString.h"
#include "AutoGen/Optionals/OptionalContextInfo.h"
#include "AutoGen/Optionals/OptionalChallengeSolution.h"
#include "AutoGen/Optionals/OptionalBool.h"

#include "TokenRequestWrapper.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UTokenRequestWrapper : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Grant Type", Category="Beam")
	FString GrantType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="B Customer Scoped", Category="Beam")
	FOptionalBool bCustomerScoped;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Device Id", Category="Beam")
	FOptionalString DeviceId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Username", Category="Beam")
	FOptionalString Username;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Refresh Token", Category="Beam")
	FOptionalString RefreshToken;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Context", Category="Beam")
	FOptionalContextInfo Context;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Third Party", Category="Beam")
	FOptionalString ThirdParty;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Redirect Uri", Category="Beam")
	FOptionalString RedirectUri;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Client Id", Category="Beam")
	FOptionalString ClientId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Challenge Solution", Category="Beam")
	FOptionalChallengeSolution ChallengeSolution;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="External Token", Category="Beam")
	FOptionalString ExternalToken;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Code", Category="Beam")
	FOptionalString Code;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Provider Address", Category="Beam")
	FOptionalString ProviderAddress;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Token", Category="Beam")
	FOptionalString Token;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Password", Category="Beam")
	FOptionalString Password;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Scope", Category="Beam")
	FOptionalArrayOfString Scope;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};