
#include "AutoGen/SubSystems/Payments/PostTestPurchaseCompleteRequest.h"

void UPostTestPurchaseCompleteRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("POST");
}

void UPostTestPurchaseCompleteRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/basic/payments/test/purchase/complete");
	
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UPostTestPurchaseCompleteRequest::BuildBody(FString& BodyString) const
{
	ensureAlways(Body);

	TUnrealJsonSerializer JsonSerializer = TJsonStringWriter<TCondensedJsonPrintPolicy<wchar_t>>::Create(&BodyString);
	Body->BeamSerialize(JsonSerializer);
	JsonSerializer->Close();
}

UPostTestPurchaseCompleteRequest* UPostTestPurchaseCompleteRequest::Make(int64 _Txid, FString _Receipt, FString _PriceInLocalCurrency, FString _IsoCurrencySymbol, UObject* RequestOwner)
{
	UPostTestPurchaseCompleteRequest* Req = NewObject<UPostTestPurchaseCompleteRequest>(RequestOwner);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	Req->Body = NewObject<UCompletePurchaseRequestBody>(Req);
	Req->Body->Txid = _Txid;
	Req->Body->Receipt = _Receipt;
	Req->Body->PriceInLocalCurrency = _PriceInLocalCurrency;
	Req->Body->IsoCurrencySymbol = _IsoCurrencySymbol;
	

	return Req;
}
