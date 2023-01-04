
#pragma once

#include "CoreMinimal.h"
#include "AutoGen/Invite.h"

#include "InviteLibrary.generated.h"


UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UInviteLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category="Beam|Json", DisplayName="Beam - Invite To JSON String")
	static FString InviteToJsonString(const UInvite* Serializable, const bool Pretty);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Make Invite", meta=(DefaultToSelf="Outer", AdvancedDisplay="Outer", NativeMakeFunc))
	static UInvite* Make(FString PlayerId, EInvitationDirection Direction, UObject* Outer);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Break Invite", meta=(NativeBreakFunc))
	static void Break(const UInvite* Serializable, FString& PlayerId, EInvitationDirection& Direction);
};