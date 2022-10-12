
#pragma once

#include "CoreMinimal.h"
#include "Serialization/BeamOptional.h"
#include "AutoGen/EventPhaseRuntime.h"

#include "OptionalEventPhaseRuntime.generated.h"

// Has Native Make/Break require static blueprint pure functions to present as nodes that
// don't require an execution pin connection. This is super relevant for Blueprint UX. 
USTRUCT(BlueprintType, meta=(HasNativeMake="BeamableCore.OptionalEventPhaseRuntimeLibrary.MakeOptionalEventPhaseRuntime"))
struct FOptionalEventPhaseRuntime : public FBeamOptional
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	UEventPhaseRuntime* Val;

	FOptionalEventPhaseRuntime();

	explicit FOptionalEventPhaseRuntime(UEventPhaseRuntime* Val);

	virtual const void* GetAddr() const override;

	virtual void Set(const void* Data) override;
};