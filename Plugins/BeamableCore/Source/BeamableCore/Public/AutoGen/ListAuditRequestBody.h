
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/Optionals/OptionalString.h"
#include "AutoGen/Optionals/OptionalInt64.h"
#include "AutoGen/Optionals/OptionalInt32.h"

#include "ListAuditRequestBody.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UListAuditRequestBody : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Providerid", Category="Beam")
	FOptionalString Providerid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Provider", Category="Beam")
	FOptionalString Provider;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="State", Category="Beam")
	FOptionalString State;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Txid", Category="Beam")
	FOptionalInt64 Txid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Player", Category="Beam")
	FOptionalInt64 Player;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Start", Category="Beam")
	FOptionalInt32 Start;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Limit", Category="Beam")
	FOptionalInt32 Limit;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};