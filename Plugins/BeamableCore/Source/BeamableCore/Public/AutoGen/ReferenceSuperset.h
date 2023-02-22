
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/Optionals/OptionalArrayOfString.h"
#include "BeamBackend/SemanticTypes/BeamContentId.h"
#include "AutoGen/Optionals/OptionalString.h"

#include "ReferenceSuperset.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UReferenceSuperset : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Uri", Category="Beam")
	FString Uri;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Version", Category="Beam")
	FString Version;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Id", Category="Beam")
	FBeamContentId Id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Type", Category="Beam")
	FString Type;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Checksum", Category="Beam")
	FOptionalString Checksum;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Visibility", Category="Beam")
	FOptionalString Visibility;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Tags", Category="Beam")
	FOptionalArrayOfString Tags;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
	
};