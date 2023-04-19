
#pragma once

#include "CoreMinimal.h"
#include "BeamableCore/Public/AutoGen/CreateProjectRequestBody.h"

#include "CreateProjectRequestBodyLibrary.generated.h"


UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UCreateProjectRequestBodyLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category="Beam|Json", DisplayName="Beam - CreateProjectRequestBody To JSON String")
	static FString CreateProjectRequestBodyToJsonString(const UCreateProjectRequestBody* Serializable, const bool Pretty);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Make CreateProjectRequestBody", meta=(DefaultToSelf="Outer", AdvancedDisplay="bSharded, Plan, Parent, Outer", NativeMakeFunc))
	static UCreateProjectRequestBody* Make(FString Name, FOptionalBool bSharded, FOptionalString Plan, FOptionalString Parent, UObject* Outer);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Break CreateProjectRequestBody", meta=(NativeBreakFunc))
	static void Break(const UCreateProjectRequestBody* Serializable, FString& Name, FOptionalBool& bSharded, FOptionalString& Plan, FOptionalString& Parent);
};