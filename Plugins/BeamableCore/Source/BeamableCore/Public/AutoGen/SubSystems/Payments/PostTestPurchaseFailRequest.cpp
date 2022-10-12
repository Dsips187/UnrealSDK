
#include "PostTestPurchaseFailRequest.h"

void UPostTestPurchaseFailRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("POST");
}

void UPostTestPurchaseFailRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/basic/payments/test/purchase/fail");
	
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UPostTestPurchaseFailRequest::BuildBody(FString& BodyString) const
{
	ensureAlways(Body);

	TUnrealJsonSerializer JsonSerializer = TJsonStringWriter<TCondensedJsonPrintPolicy<wchar_t>>::Create(&BodyString);
	Body->BeamSerialize(JsonSerializer);
	JsonSerializer->Close();
}

UPostTestPurchaseFailRequest* UPostTestPurchaseFailRequest::MakePostTestPurchaseFailRequest(int64 _Txid, FString _Reason, UObject* Outer)
{
	UPostTestPurchaseFailRequest* Req = NewObject<UPostTestPurchaseFailRequest>(Outer);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	Req->Body = NewObject<UFailPurchaseRequestBody>(Req);
	Req->Body->Txid = _Txid;
	Req->Body->Reason = _Reason;
	

	return Req;
}
