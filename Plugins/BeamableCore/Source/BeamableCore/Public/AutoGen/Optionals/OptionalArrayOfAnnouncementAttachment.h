
#pragma once

#include "CoreMinimal.h"
#include "Serialization/BeamOptional.h"
#include "AutoGen/AnnouncementAttachment.h"

#include "OptionalArrayOfAnnouncementAttachment.generated.h"

// Has Native Make/Break require static blueprint pure functions to present as nodes that
// don't require an execution pin connection. This is super relevant for Blueprint UX. 
USTRUCT(BlueprintType, meta=(HasNativeMake="BeamableCore.OptionalArrayOfAnnouncementAttachmentLibrary.MakeOptionalArrayOfAnnouncementAttachment"))
struct FOptionalArrayOfAnnouncementAttachment : public FBeamOptional
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	TArray<UAnnouncementAttachment*> Val;

	FOptionalArrayOfAnnouncementAttachment();

	explicit FOptionalArrayOfAnnouncementAttachment(TArray<UAnnouncementAttachment*> Val);

	virtual const void* GetAddr() const override;

	virtual void Set(const void* Data) override;
};