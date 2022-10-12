
#include "PostEmailUpdateInitRequest.h"

void UPostEmailUpdateInitRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("POST");
}

void UPostEmailUpdateInitRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/basic/accounts/email-update/init");
	
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UPostEmailUpdateInitRequest::BuildBody(FString& BodyString) const
{
	ensureAlways(Body);

	TUnrealJsonSerializer JsonSerializer = TJsonStringWriter<TCondensedJsonPrintPolicy<wchar_t>>::Create(&BodyString);
	Body->BeamSerialize(JsonSerializer);
	JsonSerializer->Close();
}

UPostEmailUpdateInitRequest* UPostEmailUpdateInitRequest::MakePostEmailUpdateInitRequest(FString _NewEmail, FOptionalString _CodeType, UObject* Outer)
{
	UPostEmailUpdateInitRequest* Req = NewObject<UPostEmailUpdateInitRequest>(Outer);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	Req->Body = NewObject<UEmailUpdateRequestBody>(Req);
	Req->Body->NewEmail = _NewEmail;
	Req->Body->CodeType = _CodeType;
	

	return Req;
}
