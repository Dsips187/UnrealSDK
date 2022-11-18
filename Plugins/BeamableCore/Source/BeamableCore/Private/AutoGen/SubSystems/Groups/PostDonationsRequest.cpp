
#include "AutoGen/SubSystems/Groups/PostDonationsRequest.h"

void UPostDonationsRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("POST");
}

void UPostDonationsRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/object/groups/{objectId}/donations");
	Route = Route.Replace(TEXT("{objectId}"), *FString::FromInt(ObjectId));
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UPostDonationsRequest::BuildBody(FString& BodyString) const
{
	ensureAlways(Body);

	TUnrealJsonSerializer JsonSerializer = TJsonStringWriter<TCondensedJsonPrintPolicy<wchar_t>>::Create(&BodyString);
	Body->BeamSerialize(JsonSerializer);
	JsonSerializer->Close();
}

UPostDonationsRequest* UPostDonationsRequest::Make(int64 _ObjectId, FString _CurrencyId, int64 _Amount, FOptionalString _Config, UObject* RequestOwner)
{
	UPostDonationsRequest* Req = NewObject<UPostDonationsRequest>(RequestOwner);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	Req->ObjectId = _ObjectId;
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	Req->Body = NewObject<UCreateDonationRequestBody>(Req);
	Req->Body->CurrencyId = _CurrencyId;
	Req->Body->Amount = _Amount;
	Req->Body->Config = _Config;
	

	return Req;
}
