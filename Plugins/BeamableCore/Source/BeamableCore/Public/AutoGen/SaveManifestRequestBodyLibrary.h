
#pragma once

#include "CoreMinimal.h"
#include "AutoGen/SaveManifestRequestBody.h"

#include "SaveManifestRequestBodyLibrary.generated.h"


UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API USaveManifestRequestBodyLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category="Beam|Json", DisplayName="Beam - SaveManifestRequestBody To JSON String")
	static FString SaveManifestRequestBodyToJsonString(const USaveManifestRequestBody* Serializable, const bool Pretty);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Make SaveManifestRequestBody", meta=(DefaultToSelf="Outer", AdvancedDisplay="Outer", NativeMakeFunc))
	static USaveManifestRequestBody* Make(FBeamContentManifestId Id, TArray<UReferenceSuperset*> References, UObject* Outer);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Break SaveManifestRequestBody", meta=(NativeBreakFunc))
	static void Break(const USaveManifestRequestBody* Serializable, FBeamContentManifestId& Id, TArray<UReferenceSuperset*>& References);
};