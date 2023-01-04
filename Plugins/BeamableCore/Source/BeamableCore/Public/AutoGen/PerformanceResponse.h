
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseResponseBodyInterface.h"
#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/PANamespace.h"
#include "AutoGen/PASuggestedIndex.h"
#include "AutoGen/PASlowQuery.h"
#include "AutoGen/DatabaseMeasurements.h"

#include "PerformanceResponse.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UPerformanceResponse : public UObject, public FBeamJsonSerializable, public IBeamBaseResponseBodyInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Database Measurements", Category="Beam")
	UDatabaseMeasurements* DatabaseMeasurements;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Namespaces", Category="Beam")
	TArray<UPANamespace*> Namespaces;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Indexes", Category="Beam")
	TArray<UPASuggestedIndex*> Indexes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Queries", Category="Beam")
	TArray<UPASlowQuery*> Queries;

	virtual void DeserializeRequestResponse(UObject* RequestData, FString ResponseContent) override;

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};