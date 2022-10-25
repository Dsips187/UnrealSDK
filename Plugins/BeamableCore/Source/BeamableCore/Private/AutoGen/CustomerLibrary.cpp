
#include "AutoGen/CustomerLibrary.h"

#include "CoreMinimal.h"


FString UCustomerLibrary::CustomerToJsonString(const UCustomer* Serializable, const bool Pretty)
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

UCustomer* UCustomerLibrary::Make(FString Name, int64 Cid, TArray<UProject*> Projects, TArray<URealmsBasicAccount*> Accounts, FOptionalString PaymentStatus, FOptionalString Image, FOptionalString Contact, FOptionalString Alias, FOptionalInt64 Updated, FOptionalString CrmLink, FOptionalInt64 Created, UObject* Outer)
{
	auto Serializable = NewObject<UCustomer>(Outer);
	Serializable->Name = Name;
	Serializable->Cid = Cid;
	Serializable->Projects = Projects;
	Serializable->Accounts = Accounts;
	Serializable->PaymentStatus = PaymentStatus;
	Serializable->Image = Image;
	Serializable->Contact = Contact;
	Serializable->Alias = Alias;
	Serializable->Updated = Updated;
	Serializable->CrmLink = CrmLink;
	Serializable->Created = Created;
	
	return Serializable;
}

void UCustomerLibrary::Break(const UCustomer* Serializable, FString& Name, int64& Cid, TArray<UProject*>& Projects, TArray<URealmsBasicAccount*>& Accounts, FOptionalString& PaymentStatus, FOptionalString& Image, FOptionalString& Contact, FOptionalString& Alias, FOptionalInt64& Updated, FOptionalString& CrmLink, FOptionalInt64& Created)
{
	Name = Serializable->Name;
	Cid = Serializable->Cid;
	Projects = Serializable->Projects;
	Accounts = Serializable->Accounts;
	PaymentStatus = Serializable->PaymentStatus;
	Image = Serializable->Image;
	Contact = Serializable->Contact;
	Alias = Serializable->Alias;
	Updated = Serializable->Updated;
	CrmLink = Serializable->CrmLink;
	Created = Serializable->Created;
		
}

