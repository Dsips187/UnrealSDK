
#include "PostSteamPurchaseCancelRequest.h"

void UPostSteamPurchaseCancelRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("POST");
}

void UPostSteamPurchaseCancelRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/basic/payments/steam/purchase/cancel");
	
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UPostSteamPurchaseCancelRequest::BuildBody(FString& BodyString) const
{
	ensureAlways(Body);

	TUnrealJsonSerializer JsonSerializer = TJsonStringWriter<TCondensedJsonPrintPolicy<wchar_t>>::Create(&BodyString);
	Body->BeamSerialize(JsonSerializer);
	JsonSerializer->Close();
}

UPostSteamPurchaseCancelRequest* UPostSteamPurchaseCancelRequest::MakePostSteamPurchaseCancelRequest(int64 _Txid, UObject* Outer)
{
	UPostSteamPurchaseCancelRequest* Req = NewObject<UPostSteamPurchaseCancelRequest>(Outer);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	Req->Body = NewObject<UCancelPurchaseRequestBody>(Req);
	Req->Body->Txid = _Txid;
	

	return Req;
}
