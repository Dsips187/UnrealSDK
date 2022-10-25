
#pragma once

#include "CoreMinimal.h"
#include "Serialization/BeamOptional.h"
#include "AutoGen/ItemDeleteRequestBody.h"

#include "OptionalArrayOfItemDeleteRequestBody.generated.h"

// Has Native Make/Break require static blueprint pure functions to present as nodes that
// don't require an execution pin connection. This is super relevant for Blueprint UX. 
USTRUCT(BlueprintType, meta=(HasNativeMake="BeamableCore.OptionalArrayOfItemDeleteRequestBodyLibrary.MakeOptional"))
struct BEAMABLECORE_API FOptionalArrayOfItemDeleteRequestBody : public FBeamOptional
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	TArray<UItemDeleteRequestBody*> Val;

	FOptionalArrayOfItemDeleteRequestBody();

	explicit FOptionalArrayOfItemDeleteRequestBody(TArray<UItemDeleteRequestBody*> Val);

	virtual const void* GetAddr() const override;

	virtual void Set(const void* Data) override;
};