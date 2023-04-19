
#pragma once

#include "CoreMinimal.h"
#include "BeamableCore/Public/AutoGen/NewCustomerRequestBody.h"

#include "NewCustomerRequestBodyLibrary.generated.h"


UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UNewCustomerRequestBodyLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category="Beam|Json", DisplayName="Beam - NewCustomerRequestBody To JSON String")
	static FString NewCustomerRequestBodyToJsonString(const UNewCustomerRequestBody* Serializable, const bool Pretty);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Make NewCustomerRequestBody", meta=(DefaultToSelf="Outer", AdvancedDisplay="bHierarchy, CustomerName, Alias, Outer", NativeMakeFunc))
	static UNewCustomerRequestBody* Make(FString ProjectName, FString Email, FString Password, FOptionalBool bHierarchy, FOptionalString CustomerName, FOptionalString Alias, UObject* Outer);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Break NewCustomerRequestBody", meta=(NativeBreakFunc))
	static void Break(const UNewCustomerRequestBody* Serializable, FString& ProjectName, FString& Email, FString& Password, FOptionalBool& bHierarchy, FOptionalString& CustomerName, FOptionalString& Alias);
};