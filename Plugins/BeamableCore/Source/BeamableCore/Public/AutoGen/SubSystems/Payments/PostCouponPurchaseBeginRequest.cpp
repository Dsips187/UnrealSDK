
#include "PostCouponPurchaseBeginRequest.h"

void UPostCouponPurchaseBeginRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("POST");
}

void UPostCouponPurchaseBeginRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/basic/payments/coupon/purchase/begin");
	
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UPostCouponPurchaseBeginRequest::BuildBody(FString& BodyString) const
{
	ensureAlways(Body);

	TUnrealJsonSerializer JsonSerializer = TJsonStringWriter<TCondensedJsonPrintPolicy<wchar_t>>::Create(&BodyString);
	Body->BeamSerialize(JsonSerializer);
	JsonSerializer->Close();
}

UPostCouponPurchaseBeginRequest* UPostCouponPurchaseBeginRequest::MakePostCouponPurchaseBeginRequest(FString _PurchaseId, FOptionalString _Language, FOptionalString _Time, UObject* Outer)
{
	UPostCouponPurchaseBeginRequest* Req = NewObject<UPostCouponPurchaseBeginRequest>(Outer);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	Req->Body = NewObject<UBeginPurchaseRequestBody>(Req);
	Req->Body->PurchaseId = _PurchaseId;
	Req->Body->Language = _Language;
	Req->Body->Time = _Time;
	

	return Req;
}
