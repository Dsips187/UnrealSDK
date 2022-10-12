
#pragma once

#include "CoreMinimal.h"
#include "Serialization/BeamOptional.h"
#include "AutoGen/PlayerReward.h"

#include "OptionalPlayerReward.generated.h"

// Has Native Make/Break require static blueprint pure functions to present as nodes that
// don't require an execution pin connection. This is super relevant for Blueprint UX. 
USTRUCT(BlueprintType, meta=(HasNativeMake="BeamableCore.OptionalPlayerRewardLibrary.MakeOptionalPlayerReward"))
struct FOptionalPlayerReward : public FBeamOptional
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	UPlayerReward* Val;

	FOptionalPlayerReward();

	explicit FOptionalPlayerReward(UPlayerReward* Val);

	virtual const void* GetAddr() const override;

	virtual void Set(const void* Data) override;
};