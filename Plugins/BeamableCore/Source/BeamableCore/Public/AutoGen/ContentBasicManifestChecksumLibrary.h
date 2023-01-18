
#pragma once

#include "CoreMinimal.h"
#include "AutoGen/ContentBasicManifestChecksum.h"

#include "ContentBasicManifestChecksumLibrary.generated.h"


UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UContentBasicManifestChecksumLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category="Beam|Json", DisplayName="Beam - ContentBasicManifestChecksum To JSON String")
	static FString ContentBasicManifestChecksumToJsonString(const UContentBasicManifestChecksum* Serializable, const bool Pretty);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Make ContentBasicManifestChecksum", meta=(DefaultToSelf="Outer", AdvancedDisplay="bArchived, Outer", NativeMakeFunc))
	static UContentBasicManifestChecksum* Make(FBeamContentManifestId Id, FString Checksum, int64 CreatedAt, FOptionalBool bArchived, UObject* Outer);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Break ContentBasicManifestChecksum", meta=(NativeBreakFunc))
	static void Break(const UContentBasicManifestChecksum* Serializable, FBeamContentManifestId& Id, FString& Checksum, int64& CreatedAt, FOptionalBool& bArchived);
};