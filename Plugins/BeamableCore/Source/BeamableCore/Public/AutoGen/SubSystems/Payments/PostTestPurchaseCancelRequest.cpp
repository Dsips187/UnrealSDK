
#include "PostTestPurchaseCancelRequest.h"

void UPostTestPurchaseCancelRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("POST");
}

void UPostTestPurchaseCancelRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/basic/payments/test/purchase/cancel");
	
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UPostTestPurchaseCancelRequest::BuildBody(FString& BodyString) const
{
	ensureAlways(Body);

	TUnrealJsonSerializer JsonSerializer = TJsonStringWriter<TCondensedJsonPrintPolicy<wchar_t>>::Create(&BodyString);
	Body->BeamSerialize(JsonSerializer);
	JsonSerializer->Close();
}

UPostTestPurchaseCancelRequest* UPostTestPurchaseCancelRequest::MakePostTestPurchaseCancelRequest(int64 _Txid, UObject* Outer)
{
	UPostTestPurchaseCancelRequest* Req = NewObject<UPostTestPurchaseCancelRequest>(Outer);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	Req->Body = NewObject<UCancelPurchaseRequestBody>(Req);
	Req->Body->Txid = _Txid;
	

	return Req;
}
