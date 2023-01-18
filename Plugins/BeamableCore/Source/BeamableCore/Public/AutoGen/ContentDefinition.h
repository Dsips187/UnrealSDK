
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/Optionals/OptionalArrayOfString.h"
#include "BeamBackend/SemanticTypes/BeamContentId.h"
#include "AutoGen/ContentMeta.h"
#include "AutoGen/Optionals/OptionalArrayOfMapOfContentMeta.h"

#include "ContentDefinition.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UContentDefinition : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Prefix", Category="Beam")
	FString Prefix;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Id", Category="Beam")
	FBeamContentId Id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Checksum", Category="Beam")
	FString Checksum;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Properties", Category="Beam")
	TMap<FString, UContentMeta*> Properties;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Tags", Category="Beam")
	FOptionalArrayOfString Tags;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Variants", Category="Beam")
	FOptionalArrayOfMapOfContentMeta Variants;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};