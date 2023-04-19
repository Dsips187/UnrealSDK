
#pragma once

#include "CoreMinimal.h"
#include "BeamableCore/Public/AutoGen/Attachment.h"

#include "AttachmentLibrary.generated.h"


UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UAttachmentLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category="Beam|Json", DisplayName="Beam - Attachment To JSON String")
	static FString AttachmentToJsonString(const UAttachment* Serializable, const bool Pretty);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Make Attachment", meta=(DefaultToSelf="Outer", AdvancedDisplay="Target, Outer", NativeMakeFunc))
	static UAttachment* Make(int64 Id, UEntitlementGenerator* Wrapped, FString State, FOptionalInt64 Target, UObject* Outer);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Break Attachment", meta=(NativeBreakFunc))
	static void Break(const UAttachment* Serializable, int64& Id, UEntitlementGenerator*& Wrapped, FString& State, FOptionalInt64& Target);
};