#pragma once

#include "CoreMinimal.h"
#include "BeamableCore/Public/AutoGen/MailResponse.h"

#include "MailResponseLibrary.generated.h"


UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UMailResponseLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category="Beam|Json", DisplayName="Beam - MailResponse To JSON String")
	static FString MailResponseToJsonString(const UMailResponse* Serializable, const bool Pretty);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Make MailResponse", meta=(DefaultToSelf="Outer", AdvancedDisplay="Result, Outer", NativeMakeFunc))
	static UMailResponse* Make(FOptionalMailBasicMessage Result, UObject* Outer);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Break MailResponse", meta=(NativeBreakFunc))
	static void Break(const UMailResponse* Serializable, FOptionalMailBasicMessage& Result);
};