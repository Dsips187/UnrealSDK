#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "BeamableCore/Public/AutoGen/UploadURL.h"

#include "BeamoBasicURLResponse.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UBeamoBasicURLResponse : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Service Name", Category="Beam")
	FString ServiceName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="S3UR Ls", Category="Beam")
	TArray<UUploadURL*> S3URLs;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
	
};