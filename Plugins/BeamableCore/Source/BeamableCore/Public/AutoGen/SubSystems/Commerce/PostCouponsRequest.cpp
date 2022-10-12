
#include "PostCouponsRequest.h"

void UPostCouponsRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("POST");
}

void UPostCouponsRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/object/commerce/{objectId}/coupons");
	Route = Route.Replace(TEXT("{objectId}"), *FString::FromInt(ObjectId));
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UPostCouponsRequest::BuildBody(FString& BodyString) const
{
	ensureAlways(Body);

	TUnrealJsonSerializer JsonSerializer = TJsonStringWriter<TCondensedJsonPrintPolicy<wchar_t>>::Create(&BodyString);
	Body->BeamSerialize(JsonSerializer);
	JsonSerializer->Close();
}

UPostCouponsRequest* UPostCouponsRequest::MakePostCouponsRequest(int64 _ObjectId, FString _Listing, UObject* Outer)
{
	UPostCouponsRequest* Req = NewObject<UPostCouponsRequest>(Outer);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	Req->ObjectId = _ObjectId;
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	Req->Body = NewObject<UGiveCouponReq>(Req);
	Req->Body->Listing = _Listing;
	

	return Req;
}
