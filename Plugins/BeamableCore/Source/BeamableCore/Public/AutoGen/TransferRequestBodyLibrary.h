
#pragma once

#include "CoreMinimal.h"
#include "AutoGen/TransferRequestBody.h"

#include "TransferRequestBodyLibrary.generated.h"


UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UTransferRequestBodyLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category="Beam|Json", DisplayName="Beam - TransferRequestBody To JSON String")
	static FString TransferRequestBodyToJsonString(const UTransferRequestBody* Serializable, const bool Pretty);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Make TransferRequestBody", meta=(DefaultToSelf="Outer", AdvancedDisplay="Transaction, Currencies, Outer", NativeMakeFunc))
	static UTransferRequestBody* Make(int64 RecipientPlayer, FOptionalString Transaction, FOptionalMapOfInt64 Currencies, UObject* Outer);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Break TransferRequestBody", meta=(NativeBreakFunc))
	static void Break(const UTransferRequestBody* Serializable, int64& RecipientPlayer, FOptionalString& Transaction, FOptionalMapOfInt64& Currencies);
};