
#include "AutoGen/AccountsBasicAccountLibrary.h"

#include "CoreMinimal.h"


FString UAccountsBasicAccountLibrary::AccountsBasicAccountToJsonString(const UAccountsBasicAccount* Serializable, const bool Pretty)
{
	FString Result = FString{};
	if(Pretty)
	{
		TUnrealPrettyJsonSerializer JsonSerializer = TJsonStringWriter<TPrettyJsonPrintPolicy<wchar_t>>::Create(&Result);
		Serializable->BeamSerialize(JsonSerializer);
		JsonSerializer->Close();
	}
	else
	{
		TUnrealJsonSerializer JsonSerializer = TJsonStringWriter<TCondensedJsonPrintPolicy<wchar_t>>::Create(&Result);
		Serializable->BeamSerialize(JsonSerializer);
		JsonSerializer->Close();			
	}
	return Result;
}	

UAccountsBasicAccount* UAccountsBasicAccountLibrary::Make(bool bPrivilegedAccount, int64 Id, int64 CreatedTimeMillis, int64 UpdatedTimeMillis, TArray<UThirdPartyAssociation*> ThirdParties, TArray<UGamerTagAssociation*> GamerTags, FOptionalBool bWasMigrated, FOptionalString UserName, FOptionalString DeviceId, FOptionalString Language, FOptionalString Password, FOptionalString Country, FOptionalString RoleString, FOptionalString Email, FOptionalString RealmId, FOptionalInt64 Heartbeat, FOptionalArrayOfRoleMapping Roles, FOptionalArrayOfString DeviceIds, FOptionalArrayOfInFlightMessage InFlight, UObject* Outer)
{
	auto Serializable = NewObject<UAccountsBasicAccount>(Outer);
	Serializable->bPrivilegedAccount = bPrivilegedAccount;
	Serializable->Id = Id;
	Serializable->CreatedTimeMillis = CreatedTimeMillis;
	Serializable->UpdatedTimeMillis = UpdatedTimeMillis;
	Serializable->ThirdParties = ThirdParties;
	Serializable->GamerTags = GamerTags;
	Serializable->bWasMigrated = bWasMigrated;
	Serializable->UserName = UserName;
	Serializable->DeviceId = DeviceId;
	Serializable->Language = Language;
	Serializable->Password = Password;
	Serializable->Country = Country;
	Serializable->RoleString = RoleString;
	Serializable->Email = Email;
	Serializable->RealmId = RealmId;
	Serializable->Heartbeat = Heartbeat;
	Serializable->Roles = Roles;
	Serializable->DeviceIds = DeviceIds;
	Serializable->InFlight = InFlight;
	
	return Serializable;
}

void UAccountsBasicAccountLibrary::Break(const UAccountsBasicAccount* Serializable, bool& bPrivilegedAccount, int64& Id, int64& CreatedTimeMillis, int64& UpdatedTimeMillis, TArray<UThirdPartyAssociation*>& ThirdParties, TArray<UGamerTagAssociation*>& GamerTags, FOptionalBool& bWasMigrated, FOptionalString& UserName, FOptionalString& DeviceId, FOptionalString& Language, FOptionalString& Password, FOptionalString& Country, FOptionalString& RoleString, FOptionalString& Email, FOptionalString& RealmId, FOptionalInt64& Heartbeat, FOptionalArrayOfRoleMapping& Roles, FOptionalArrayOfString& DeviceIds, FOptionalArrayOfInFlightMessage& InFlight)
{
	bPrivilegedAccount = Serializable->bPrivilegedAccount;
	Id = Serializable->Id;
	CreatedTimeMillis = Serializable->CreatedTimeMillis;
	UpdatedTimeMillis = Serializable->UpdatedTimeMillis;
	ThirdParties = Serializable->ThirdParties;
	GamerTags = Serializable->GamerTags;
	bWasMigrated = Serializable->bWasMigrated;
	UserName = Serializable->UserName;
	DeviceId = Serializable->DeviceId;
	Language = Serializable->Language;
	Password = Serializable->Password;
	Country = Serializable->Country;
	RoleString = Serializable->RoleString;
	Email = Serializable->Email;
	RealmId = Serializable->RealmId;
	Heartbeat = Serializable->Heartbeat;
	Roles = Serializable->Roles;
	DeviceIds = Serializable->DeviceIds;
	InFlight = Serializable->InFlight;
		
}

