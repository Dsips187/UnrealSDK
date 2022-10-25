
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"


#include "AnnouncementState.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UAnnouncementState : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="B Is Claimed", Category="Beam")
	bool bIsClaimed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="B Is Deleted", Category="Beam")
	bool bIsDeleted;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="B Is Read", Category="Beam")
	bool bIsRead;

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};