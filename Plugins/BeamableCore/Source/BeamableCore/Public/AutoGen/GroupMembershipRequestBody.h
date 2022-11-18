
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/Optionals/OptionalInt64.h"
#include "AutoGen/Enums/GroupType.h"

#include "GroupMembershipRequestBody.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UGroupMembershipRequestBody : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Type", Category="Beam")
	EGroupType Type;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Group", Category="Beam")
	int64 Group;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Successor", Category="Beam")
	FOptionalInt64 Successor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Score", Category="Beam")
	FOptionalInt64 Score;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Sub Group", Category="Beam")
	FOptionalInt64 SubGroup;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};