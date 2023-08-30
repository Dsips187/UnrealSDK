#pragma once

#include "CoreMinimal.h"
#include "BeamableCore/Public/AutoGen/InviteToParty.h"

#include "InviteToPartyLibrary.generated.h"


UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UInviteToPartyLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category="Beam|Json", DisplayName="Beam - InviteToParty To JSON String")
	static FString InviteToPartyToJsonString(const UInviteToParty* Serializable, const bool Pretty);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Make InviteToParty", meta=(DefaultToSelf="Outer", AdvancedDisplay="PlayerId, Outer", NativeMakeFunc))
	static UInviteToParty* Make(FOptionalString PlayerId, UObject* Outer);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Break InviteToParty", meta=(NativeBreakFunc))
	static void Break(const UInviteToParty* Serializable, FOptionalString& PlayerId);
};