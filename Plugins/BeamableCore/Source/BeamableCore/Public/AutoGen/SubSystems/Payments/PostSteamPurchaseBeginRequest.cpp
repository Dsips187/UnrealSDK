
#include "PostSteamPurchaseBeginRequest.h"

void UPostSteamPurchaseBeginRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("POST");
}

void UPostSteamPurchaseBeginRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/basic/payments/steam/purchase/begin");
	
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UPostSteamPurchaseBeginRequest::BuildBody(FString& BodyString) const
{
	ensureAlways(Body);

	TUnrealJsonSerializer JsonSerializer = TJsonStringWriter<TCondensedJsonPrintPolicy<wchar_t>>::Create(&BodyString);
	Body->BeamSerialize(JsonSerializer);
	JsonSerializer->Close();
}

UPostSteamPurchaseBeginRequest* UPostSteamPurchaseBeginRequest::MakePostSteamPurchaseBeginRequest(FString _PurchaseId, FOptionalString _Language, FOptionalString _Time, UObject* Outer)
{
	UPostSteamPurchaseBeginRequest* Req = NewObject<UPostSteamPurchaseBeginRequest>(Outer);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	Req->Body = NewObject<UBeginPurchaseRequestBody>(Req);
	Req->Body->PurchaseId = _PurchaseId;
	Req->Body->Language = _Language;
	Req->Body->Time = _Time;
	

	return Req;
}
