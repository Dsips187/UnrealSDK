
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/Optionals/OptionalArrayOfMailObjectMessage.h"

#include "MailSearchResponseClause.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UMailSearchResponseClause : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Name", Category="Beam")
	FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Count", Category="Beam")
	int64 Count;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Content", Category="Beam")
	FOptionalArrayOfMailObjectMessage Content;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};