#pragma once

#include "CoreMinimal.h"
#include "Serialization/BeamOptional.h"
#include "BeamableCore/Public/AutoGen/Period.h"

#include "OptionalPeriod.generated.h"

// Has Native Make/Break require static blueprint pure functions to present as nodes that
// don't require an execution pin connection. This is super relevant for Blueprint UX. 
USTRUCT(BlueprintType, meta=(HasNativeMake="/Script/BeamableCore.OptionalPeriodLibrary.MakeOptional", BeamOptionalType="UPeriod*"))
struct BEAMABLECORE_API FOptionalPeriod : public FBeamOptional
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	UPeriod* Val;

	FOptionalPeriod();

	explicit FOptionalPeriod(UPeriod* Val);

	virtual const void* GetAddr() const override;

	virtual void Set(const void* Data) override;
};