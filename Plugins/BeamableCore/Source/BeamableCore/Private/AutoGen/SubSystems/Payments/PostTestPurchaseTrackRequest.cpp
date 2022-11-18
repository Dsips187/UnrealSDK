
#include "AutoGen/SubSystems/Payments/PostTestPurchaseTrackRequest.h"

void UPostTestPurchaseTrackRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("POST");
}

void UPostTestPurchaseTrackRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/basic/payments/test/purchase/track");
	
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UPostTestPurchaseTrackRequest::BuildBody(FString& BodyString) const
{
	ensureAlways(Body);

	TUnrealJsonSerializer JsonSerializer = TJsonStringWriter<TCondensedJsonPrintPolicy<wchar_t>>::Create(&BodyString);
	Body->BeamSerialize(JsonSerializer);
	JsonSerializer->Close();
}

UPostTestPurchaseTrackRequest* UPostTestPurchaseTrackRequest::Make(double _PriceInLocalCurrency, FString _SkuName, FString _SkuProductId, FString _Store, FString _PurchaseId, FString _IsoCurrencySymbol, TArray<UItemCreateRequestBody*> _ObtainItems, TArray<UCurrencyChange*> _ObtainCurrency, UObject* RequestOwner)
{
	UPostTestPurchaseTrackRequest* Req = NewObject<UPostTestPurchaseTrackRequest>(RequestOwner);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	Req->Body = NewObject<UTrackPurchaseRequestBody>(Req);
	Req->Body->PriceInLocalCurrency = _PriceInLocalCurrency;
	Req->Body->SkuName = _SkuName;
	Req->Body->SkuProductId = _SkuProductId;
	Req->Body->Store = _Store;
	Req->Body->PurchaseId = _PurchaseId;
	Req->Body->IsoCurrencySymbol = _IsoCurrencySymbol;
	Req->Body->ObtainItems = _ObtainItems;
	Req->Body->ObtainCurrency = _ObtainCurrency;
	

	return Req;
}
