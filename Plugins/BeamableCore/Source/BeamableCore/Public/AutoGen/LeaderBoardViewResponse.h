
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseResponseBodyInterface.h"
#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/LeaderBoardView.h"

#include "LeaderBoardViewResponse.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API ULeaderBoardViewResponse : public UObject, public FBeamJsonSerializable, public IBeamBaseResponseBodyInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Result", Category="Beam")
	FString Result;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Lb", Category="Beam")
	ULeaderBoardView* Lb;

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};