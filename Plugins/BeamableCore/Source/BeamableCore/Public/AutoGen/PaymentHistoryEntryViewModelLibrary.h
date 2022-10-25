
#pragma once

#include "CoreMinimal.h"
#include "AutoGen/PaymentHistoryEntryViewModel.h"

#include "PaymentHistoryEntryViewModelLibrary.generated.h"


UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UPaymentHistoryEntryViewModelLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category="Beam|Json", DisplayName="Beam - PaymentHistoryEntryViewModel To JSON String")
	static FString PaymentHistoryEntryViewModelToJsonString(const UPaymentHistoryEntryViewModel* Serializable, const bool Pretty);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Make PaymentHistoryEntryViewModel", meta=(DefaultToSelf="Outer", AdvancedDisplay="Data, Timestamp, Outer", NativeMakeFunc))
	static UPaymentHistoryEntryViewModel* Make(FString Change, FOptionalString Data, FOptionalString Timestamp, UObject* Outer);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Break PaymentHistoryEntryViewModel", meta=(NativeBreakFunc))
	static void Break(const UPaymentHistoryEntryViewModel* Serializable, FString& Change, FOptionalString& Data, FOptionalString& Timestamp);
};