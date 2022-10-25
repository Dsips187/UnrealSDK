
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/Optionals/OptionalArrayOfMetadataPair.h"
#include "AutoGen/Optionals/OptionalInt64.h"

#include "UploadRequestFromPortal.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UUploadRequestFromPortal : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Object Key", Category="Beam")
	FString ObjectKey;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Size In Bytes", Category="Beam")
	int64 SizeInBytes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Last Modified", Category="Beam")
	FOptionalInt64 LastModified;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Metadata", Category="Beam")
	FOptionalArrayOfMetadataPair Metadata;

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};