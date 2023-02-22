
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/Optionals/OptionalInt64.h"

#include "GroupUserMember.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UGroupUserMember : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Id", Category="Beam")
	int64 Id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Sub Groups", Category="Beam")
	TArray<UGroupUserMember*> SubGroups;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Joined", Category="Beam")
	FOptionalInt64 Joined;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
	
};