
#include "AutoGen/AccountPersonallyIdentifiableInformationResponseLibrary.h"

#include "CoreMinimal.h"


FString UAccountPersonallyIdentifiableInformationResponseLibrary::AccountPersonallyIdentifiableInformationResponseToJsonString(const UAccountPersonallyIdentifiableInformationResponse* Serializable, const bool Pretty)
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

UAccountPersonallyIdentifiableInformationResponse* UAccountPersonallyIdentifiableInformationResponseLibrary::Make(UAccountsBasicAccount* Account, UListAuditResponse* PaymentAudits, TArray<UStatsResponse*> Stats, UObject* Outer)
{
	auto Serializable = NewObject<UAccountPersonallyIdentifiableInformationResponse>(Outer);
	Serializable->Account = Account;
	Serializable->PaymentAudits = PaymentAudits;
	Serializable->Stats = Stats;
	
	return Serializable;
}

void UAccountPersonallyIdentifiableInformationResponseLibrary::Break(const UAccountPersonallyIdentifiableInformationResponse* Serializable, UAccountsBasicAccount*& Account, UListAuditResponse*& PaymentAudits, TArray<UStatsResponse*>& Stats)
{
	Account = Serializable->Account;
	PaymentAudits = Serializable->PaymentAudits;
	Stats = Serializable->Stats;
		
}

