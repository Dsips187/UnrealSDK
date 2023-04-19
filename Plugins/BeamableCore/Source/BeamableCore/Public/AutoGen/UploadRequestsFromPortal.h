
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "BeamableCore/Public/AutoGen/UploadRequestFromPortal.h"
#include "BeamableCore/Public/AutoGen/Optionals/OptionalInt64.h"

#include "UploadRequestsFromPortal.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UUploadRequestsFromPortal : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Request", Category="Beam")
	TArray<UUploadRequestFromPortal*> Request;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Player Id", Category="Beam")
	FOptionalInt64 PlayerId;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
	
};