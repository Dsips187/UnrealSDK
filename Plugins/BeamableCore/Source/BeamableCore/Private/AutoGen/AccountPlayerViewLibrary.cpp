
#include "AutoGen/AccountPlayerViewLibrary.h"

#include "CoreMinimal.h"


FString UAccountPlayerViewLibrary::AccountPlayerViewToJsonString(const UAccountPlayerView* Serializable, const bool Pretty)
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

UAccountPlayerView* UAccountPlayerViewLibrary::Make(FBeamGamerTag Id, TArray<FString> DeviceIds, TArray<FString> Scopes, TArray<FString> ThirdPartyAppAssociations, FOptionalString Email, FOptionalString Language, FOptionalArrayOfExternalIdentity External, UObject* Outer)
{
	auto Serializable = NewObject<UAccountPlayerView>(Outer);
	Serializable->Id = Id;
	Serializable->DeviceIds = DeviceIds;
	Serializable->Scopes = Scopes;
	Serializable->ThirdPartyAppAssociations = ThirdPartyAppAssociations;
	Serializable->Email = Email;
	Serializable->Language = Language;
	Serializable->External = External;
	
	return Serializable;
}

void UAccountPlayerViewLibrary::Break(const UAccountPlayerView* Serializable, FBeamGamerTag& Id, TArray<FString>& DeviceIds, TArray<FString>& Scopes, TArray<FString>& ThirdPartyAppAssociations, FOptionalString& Email, FOptionalString& Language, FOptionalArrayOfExternalIdentity& External)
{
	Id = Serializable->Id;
	DeviceIds = Serializable->DeviceIds;
	Scopes = Serializable->Scopes;
	ThirdPartyAppAssociations = Serializable->ThirdPartyAppAssociations;
	Email = Serializable->Email;
	Language = Serializable->Language;
	External = Serializable->External;
		
}

