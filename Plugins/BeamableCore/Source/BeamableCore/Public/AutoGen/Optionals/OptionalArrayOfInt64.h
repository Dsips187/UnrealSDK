
#pragma once

#include "CoreMinimal.h"
#include "Serialization/BeamOptional.h"


#include "OptionalArrayOfInt64.generated.h"

// Has Native Make/Break require static blueprint pure functions to present as nodes that
// don't require an execution pin connection. This is super relevant for Blueprint UX. 
USTRUCT(BlueprintType, meta=(HasNativeMake="BeamableCore.OptionalArrayOfInt64Library.MakeOptional"))
struct BEAMABLECORE_API FOptionalArrayOfInt64 : public FBeamOptional
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	TArray<int64> Val;

	FOptionalArrayOfInt64();

	explicit FOptionalArrayOfInt64(TArray<int64> Val);

	virtual const void* GetAddr() const override;

	virtual void Set(const void* Data) override;
};