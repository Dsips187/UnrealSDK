
#include "BeamableCore/Public/AutoGen/SubSystems/Payments/PostTestPurchaseVerifyRequest.h"

void UPostTestPurchaseVerifyRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("POST");
}

void UPostTestPurchaseVerifyRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/basic/payments/test/purchase/verify");
	
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UPostTestPurchaseVerifyRequest::BuildBody(FString& BodyString) const
{
	ensureAlways(Body);

	TUnrealJsonSerializer JsonSerializer = TJsonStringWriter<TCondensedJsonPrintPolicy<wchar_t>>::Create(&BodyString);
	Body->BeamSerialize(JsonSerializer);
	JsonSerializer->Close();
}

UPostTestPurchaseVerifyRequest* UPostTestPurchaseVerifyRequest::Make(FString _Receipt, UObject* RequestOwner)
{
	UPostTestPurchaseVerifyRequest* Req = NewObject<UPostTestPurchaseVerifyRequest>(RequestOwner);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	Req->Body = NewObject<UVerifyPurchaseRequestBody>(Req);
	Req->Body->Receipt = _Receipt;
	

	return Req;
}
