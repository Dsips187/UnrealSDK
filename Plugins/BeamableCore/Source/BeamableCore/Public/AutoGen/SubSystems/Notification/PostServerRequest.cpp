
#include "PostServerRequest.h"

void UPostServerRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("POST");
}

void UPostServerRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/basic/notification/server");
	
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UPostServerRequest::BuildBody(FString& BodyString) const
{
	ensureAlways(Body);

	TUnrealJsonSerializer JsonSerializer = TJsonStringWriter<TCondensedJsonPrintPolicy<wchar_t>>::Create(&BodyString);
	Body->BeamSerialize(JsonSerializer);
	JsonSerializer->Close();
}

UPostServerRequest* UPostServerRequest::MakePostServerRequest(FString _Event, FOptionalString _Payload, bool _bToAll, UObject* Outer)
{
	UPostServerRequest* Req = NewObject<UPostServerRequest>(Outer);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	Req->Body = NewObject<UServerEvent>(Req);
	Req->Body->Event = _Event;
	Req->Body->Payload = _Payload;
	Req->Body->bToAll = _bToAll;
	

	return Req;
}
