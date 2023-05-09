#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "BeamableCore/Public/AutoGen/RewardCalendarDay.h"

#include "CalendarView.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UCalendarView : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Next Index", Category="Beam")
	int32 NextIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Next Claim Seconds", Category="Beam")
	int64 NextClaimSeconds;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Id", Category="Beam")
	FString Id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Remaining Seconds", Category="Beam")
	int64 RemainingSeconds;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Days", Category="Beam")
	TArray<URewardCalendarDay*> Days;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
	
};