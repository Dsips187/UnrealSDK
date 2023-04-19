
#include "BeamableCore/Public/AutoGen/SubSystems/Payments/PostCouponPurchaseCompleteRequest.h"

void UPostCouponPurchaseCompleteRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("POST");
}

void UPostCouponPurchaseCompleteRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/basic/payments/coupon/purchase/complete");
	
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UPostCouponPurchaseCompleteRequest::BuildBody(FString& BodyString) const
{
	ensureAlways(Body);

	TUnrealJsonSerializer JsonSerializer = TJsonStringWriter<TCondensedJsonPrintPolicy<wchar_t>>::Create(&BodyString);
	Body->BeamSerialize(JsonSerializer);
	JsonSerializer->Close();
}

UPostCouponPurchaseCompleteRequest* UPostCouponPurchaseCompleteRequest::Make(int64 _Txid, FString _Receipt, FString _PriceInLocalCurrency, FString _IsoCurrencySymbol, UObject* RequestOwner)
{
	UPostCouponPurchaseCompleteRequest* Req = NewObject<UPostCouponPurchaseCompleteRequest>(RequestOwner);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	Req->Body = NewObject<UCompletePurchaseRequestBody>(Req);
	Req->Body->Txid = _Txid;
	Req->Body->Receipt = _Receipt;
	Req->Body->PriceInLocalCurrency = _PriceInLocalCurrency;
	Req->Body->IsoCurrencySymbol = _IsoCurrencySymbol;
	

	return Req;
}
