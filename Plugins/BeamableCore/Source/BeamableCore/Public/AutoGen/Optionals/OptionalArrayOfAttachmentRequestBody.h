
#pragma once

#include "CoreMinimal.h"
#include "Serialization/BeamOptional.h"
#include "AutoGen/AttachmentRequestBody.h"

#include "OptionalArrayOfAttachmentRequestBody.generated.h"

// Has Native Make/Break require static blueprint pure functions to present as nodes that
// don't require an execution pin connection. This is super relevant for Blueprint UX. 
USTRUCT(BlueprintType, meta=(HasNativeMake="BeamableCore.OptionalArrayOfAttachmentRequestBodyLibrary.MakeOptionalArrayOfAttachmentRequestBody"))
struct FOptionalArrayOfAttachmentRequestBody : public FBeamOptional
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	TArray<UAttachmentRequestBody*> Val;

	FOptionalArrayOfAttachmentRequestBody();

	explicit FOptionalArrayOfAttachmentRequestBody(TArray<UAttachmentRequestBody*> Val);

	virtual const void* GetAddr() const override;

	virtual void Set(const void* Data) override;
};