#pragma once

#include "CoreMinimal.h"
#include "Serialization/BeamOptional.h"
#include "BeamableCore/Public/AutoGen/WebhookReward.h"

#include "OptionalArrayOfWebhookReward.generated.h"

// Has Native Make/Break require static blueprint pure functions to present as nodes that
// don't require an execution pin connection. This is super relevant for Blueprint UX. 
USTRUCT(BlueprintType, meta=(HasNativeMake="BeamableCore.OptionalArrayOfWebhookRewardLibrary.MakeOptional", BeamOptionalType="TArray<UWebhookReward*>"))
struct BEAMABLECORE_API FOptionalArrayOfWebhookReward : public FBeamOptional
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	TArray<UWebhookReward*> Val;

	FOptionalArrayOfWebhookReward();

	explicit FOptionalArrayOfWebhookReward(TArray<UWebhookReward*> Val);

	virtual const void* GetAddr() const override;

	virtual void Set(const void* Data) override;
};