
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/Optionals/OptionalInt32.h"
#include "AutoGen/Optionals/OptionalBool.h"

#include "GetManifestsRequestBody.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UGetManifestsRequestBody : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="B Archived", Category="Beam")
	FOptionalBool bArchived;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Limit", Category="Beam")
	FOptionalInt32 Limit;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Offset", Category="Beam")
	FOptionalInt32 Offset;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
	
};