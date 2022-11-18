
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/Optionals/OptionalInt64.h"
#include "AutoGen/Optionals/OptionalString.h"
#include "AutoGen/Optionals/OptionalArrayOfServiceDependencyReference.h"

#include "ServiceReference.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UServiceReference : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="B Archived", Category="Beam")
	bool bArchived;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="B Arm", Category="Beam")
	bool bArm;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="B Enabled", Category="Beam")
	bool bEnabled;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Service Name", Category="Beam")
	FString ServiceName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Checksum", Category="Beam")
	FString Checksum;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Template Id", Category="Beam")
	FString TemplateId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Image Id", Category="Beam")
	FString ImageId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Container Health Check Port", Category="Beam")
	FOptionalInt64 ContainerHealthCheckPort;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Image Cpu Arch", Category="Beam")
	FOptionalString ImageCpuArch;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Comments", Category="Beam")
	FOptionalString Comments;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Dependencies", Category="Beam")
	FOptionalArrayOfServiceDependencyReference Dependencies;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};