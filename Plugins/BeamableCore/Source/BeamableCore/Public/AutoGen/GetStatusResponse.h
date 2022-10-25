
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseResponseBodyInterface.h"
#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/ServiceStatus.h"
#include "AutoGen/Optionals/OptionalArrayOfServiceStorageStatus.h"

#include "GetStatusResponse.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UGetStatusResponse : public UObject, public FBeamJsonSerializable, public IBeamBaseResponseBodyInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="B Is Current", Category="Beam")
	bool bIsCurrent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Services", Category="Beam")
	TArray<UServiceStatus*> Services;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Storage Statuses", Category="Beam")
	FOptionalArrayOfServiceStorageStatus StorageStatuses;

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};