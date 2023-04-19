
#include "BeamableCore/Public/AutoGen/SubSystems/Accounts/BasicAccountsPostRegisterRequest.h"

void UBasicAccountsPostRegisterRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("POST");
}

void UBasicAccountsPostRegisterRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/basic/accounts/register");
	
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UBasicAccountsPostRegisterRequest::BuildBody(FString& BodyString) const
{
	ensureAlways(Body);

	TUnrealJsonSerializer JsonSerializer = TJsonStringWriter<TCondensedJsonPrintPolicy<wchar_t>>::Create(&BodyString);
	Body->BeamSerialize(JsonSerializer);
	JsonSerializer->Close();
}

UBasicAccountsPostRegisterRequest* UBasicAccountsPostRegisterRequest::Make(FString _Email, FString _Password, UObject* RequestOwner)
{
	UBasicAccountsPostRegisterRequest* Req = NewObject<UBasicAccountsPostRegisterRequest>(RequestOwner);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	Req->Body = NewObject<UAccountRegistration>(Req);
	Req->Body->Email = _Email;
	Req->Body->Password = _Password;
	

	return Req;
}
