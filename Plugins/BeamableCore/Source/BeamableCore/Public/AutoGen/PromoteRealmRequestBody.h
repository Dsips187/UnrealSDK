
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/Optionals/OptionalArrayOfString.h"

#include "PromoteRealmRequestBody.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UPromoteRealmRequestBody : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Source Pid", Category="Beam")
	FString SourcePid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Promotions", Category="Beam")
	FOptionalArrayOfString Promotions;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Content Manifest Ids", Category="Beam")
	FOptionalArrayOfString ContentManifestIds;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};