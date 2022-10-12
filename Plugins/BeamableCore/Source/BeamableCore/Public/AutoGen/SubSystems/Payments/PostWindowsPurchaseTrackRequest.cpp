
#include "PostWindowsPurchaseTrackRequest.h"

void UPostWindowsPurchaseTrackRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("POST");
}

void UPostWindowsPurchaseTrackRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/basic/payments/windows/purchase/track");
	
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UPostWindowsPurchaseTrackRequest::BuildBody(FString& BodyString) const
{
	ensureAlways(Body);

	TUnrealJsonSerializer JsonSerializer = TJsonStringWriter<TCondensedJsonPrintPolicy<wchar_t>>::Create(&BodyString);
	Body->BeamSerialize(JsonSerializer);
	JsonSerializer->Close();
}

UPostWindowsPurchaseTrackRequest* UPostWindowsPurchaseTrackRequest::MakePostWindowsPurchaseTrackRequest(double _PriceInLocalCurrency, FString _SkuName, FString _SkuProductId, FString _Store, TArray<UItemCreateRequestBody*> _ObtainItems, TArray<UCurrencyChange*> _ObtainCurrency, FString _PurchaseId, FString _IsoCurrencySymbol, UObject* Outer)
{
	UPostWindowsPurchaseTrackRequest* Req = NewObject<UPostWindowsPurchaseTrackRequest>(Outer);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	Req->Body = NewObject<UTrackPurchaseRequestBody>(Req);
	Req->Body->PriceInLocalCurrency = _PriceInLocalCurrency;
	Req->Body->SkuName = _SkuName;
	Req->Body->SkuProductId = _SkuProductId;
	Req->Body->Store = _Store;
	Req->Body->ObtainItems = _ObtainItems;
	Req->Body->ObtainCurrency = _ObtainCurrency;
	Req->Body->PurchaseId = _PurchaseId;
	Req->Body->IsoCurrencySymbol = _IsoCurrencySymbol;
	

	return Req;
}
