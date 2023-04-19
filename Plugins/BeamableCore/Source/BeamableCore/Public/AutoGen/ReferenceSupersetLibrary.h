
#pragma once

#include "CoreMinimal.h"
#include "BeamableCore/Public/AutoGen/ReferenceSuperset.h"

#include "ReferenceSupersetLibrary.generated.h"


UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UReferenceSupersetLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category="Beam|Json", DisplayName="Beam - ReferenceSuperset To JSON String")
	static FString ReferenceSupersetToJsonString(const UReferenceSuperset* Serializable, const bool Pretty);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Make ReferenceSuperset", meta=(DefaultToSelf="Outer", AdvancedDisplay="Checksum, Visibility, Tags, Outer", NativeMakeFunc))
	static UReferenceSuperset* Make(FString Uri, FString Version, FBeamContentId Id, FString Type, FOptionalString Checksum, FOptionalString Visibility, FOptionalArrayOfString Tags, UObject* Outer);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Break ReferenceSuperset", meta=(NativeBreakFunc))
	static void Break(const UReferenceSuperset* Serializable, FString& Uri, FString& Version, FBeamContentId& Id, FString& Type, FOptionalString& Checksum, FOptionalString& Visibility, FOptionalArrayOfString& Tags);
};