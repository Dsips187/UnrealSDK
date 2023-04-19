
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "BeamBackend/SemanticTypes/BeamGamerTag.h"
#include "BeamableCore/Public/AutoGen/Enums/FriendSource.h"

#include "Friend.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UFriend : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Player Id", Category="Beam")
	FBeamGamerTag PlayerId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Source", Category="Beam")
	EFriendSource Source;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
	
};