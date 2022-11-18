
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/Optionals/OptionalInt64.h"
#include "AutoGen/Optionals/OptionalString.h"
#include "AutoGen/Optionals/OptionalInt32.h"

#include "GetLogsUrlRequestBody.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UGetLogsUrlRequestBody : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Service Name", Category="Beam")
	FString ServiceName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Start Time", Category="Beam")
	FOptionalInt64 StartTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Next Token", Category="Beam")
	FOptionalString NextToken;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Filter", Category="Beam")
	FOptionalString Filter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="End Time", Category="Beam")
	FOptionalInt64 EndTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Limit", Category="Beam")
	FOptionalInt32 Limit;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};