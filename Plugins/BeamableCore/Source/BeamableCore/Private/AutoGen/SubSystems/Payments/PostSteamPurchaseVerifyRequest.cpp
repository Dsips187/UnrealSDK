
#include "AutoGen/SubSystems/Payments/PostSteamPurchaseVerifyRequest.h"

void UPostSteamPurchaseVerifyRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("POST");
}

void UPostSteamPurchaseVerifyRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/basic/payments/steam/purchase/verify");
	
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UPostSteamPurchaseVerifyRequest::BuildBody(FString& BodyString) const
{
	ensureAlways(Body);

	TUnrealJsonSerializer JsonSerializer = TJsonStringWriter<TCondensedJsonPrintPolicy<wchar_t>>::Create(&BodyString);
	Body->BeamSerialize(JsonSerializer);
	JsonSerializer->Close();
}

UPostSteamPurchaseVerifyRequest* UPostSteamPurchaseVerifyRequest::Make(FString _Receipt, UObject* RequestOwner)
{
	UPostSteamPurchaseVerifyRequest* Req = NewObject<UPostSteamPurchaseVerifyRequest>(RequestOwner);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	Req->Body = NewObject<UVerifyPurchaseRequestBody>(Req);
	Req->Body->Receipt = _Receipt;
	

	return Req;
}
