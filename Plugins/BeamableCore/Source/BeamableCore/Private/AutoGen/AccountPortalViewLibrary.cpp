
#include "AutoGen/AccountPortalViewLibrary.h"

#include "CoreMinimal.h"


FString UAccountPortalViewLibrary::AccountPortalViewToJsonString(const UAccountPortalView* Serializable, const bool Pretty)
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

UAccountPortalView* UAccountPortalViewLibrary::Make(int64 Id, TArray<FString> Scopes, TArray<FString> ThirdPartyAppAssociations, FOptionalString Email, FOptionalString RoleString, FOptionalString Language, FOptionalArrayOfRoleMapping Roles, UObject* Outer)
{
	auto Serializable = NewObject<UAccountPortalView>(Outer);
	Serializable->Id = Id;
	Serializable->Scopes = Scopes;
	Serializable->ThirdPartyAppAssociations = ThirdPartyAppAssociations;
	Serializable->Email = Email;
	Serializable->RoleString = RoleString;
	Serializable->Language = Language;
	Serializable->Roles = Roles;
	
	return Serializable;
}

void UAccountPortalViewLibrary::Break(const UAccountPortalView* Serializable, int64& Id, TArray<FString>& Scopes, TArray<FString>& ThirdPartyAppAssociations, FOptionalString& Email, FOptionalString& RoleString, FOptionalString& Language, FOptionalArrayOfRoleMapping& Roles)
{
	Id = Serializable->Id;
	Scopes = Serializable->Scopes;
	ThirdPartyAppAssociations = Serializable->ThirdPartyAppAssociations;
	Email = Serializable->Email;
	RoleString = Serializable->RoleString;
	Language = Serializable->Language;
	Roles = Serializable->Roles;
		
}

