
#pragma once

#include "CoreMinimal.h"
#include "AutoGen/AccountsBasicAccount.h"

#include "AccountsBasicAccountLibrary.generated.h"


UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UAccountsBasicAccountLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category="Beam|Json", DisplayName="Beam - AccountsBasicAccount To JSON String")
	static FString AccountsBasicAccountToJsonString(const UAccountsBasicAccount* Serializable, const bool Pretty);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Make AccountsBasicAccount", meta=(DefaultToSelf="Outer", AdvancedDisplay="bWasMigrated, UserName, DeviceId, Language, Password, Country, RoleString, Email, RealmId, Heartbeat, Roles, DeviceIds, InFlight, Outer", NativeMakeFunc))
	static UAccountsBasicAccount* Make(bool bPrivilegedAccount, int64 Id, int64 CreatedTimeMillis, int64 UpdatedTimeMillis, TArray<UThirdPartyAssociation*> ThirdParties, TArray<UGamerTagAssociation*> GamerTags, FOptionalBool bWasMigrated, FOptionalString UserName, FOptionalString DeviceId, FOptionalString Language, FOptionalString Password, FOptionalString Country, FOptionalString RoleString, FOptionalString Email, FOptionalString RealmId, FOptionalInt64 Heartbeat, FOptionalArrayOfRoleMapping Roles, FOptionalArrayOfString DeviceIds, FOptionalArrayOfInFlightMessage InFlight, UObject* Outer);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Break AccountsBasicAccount", meta=(NativeBreakFunc))
	static void Break(const UAccountsBasicAccount* Serializable, bool& bPrivilegedAccount, int64& Id, int64& CreatedTimeMillis, int64& UpdatedTimeMillis, TArray<UThirdPartyAssociation*>& ThirdParties, TArray<UGamerTagAssociation*>& GamerTags, FOptionalBool& bWasMigrated, FOptionalString& UserName, FOptionalString& DeviceId, FOptionalString& Language, FOptionalString& Password, FOptionalString& Country, FOptionalString& RoleString, FOptionalString& Email, FOptionalString& RealmId, FOptionalInt64& Heartbeat, FOptionalArrayOfRoleMapping& Roles, FOptionalArrayOfString& DeviceIds, FOptionalArrayOfInFlightMessage& InFlight);
};