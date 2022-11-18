
#include "AutoGen/SubSystems/Groups/PutDonationsRequest.h"

void UPutDonationsRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("PUT");
}

void UPutDonationsRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/object/groups/{objectId}/donations");
	Route = Route.Replace(TEXT("{objectId}"), *FString::FromInt(ObjectId));
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UPutDonationsRequest::BuildBody(FString& BodyString) const
{
	ensureAlways(Body);

	TUnrealJsonSerializer JsonSerializer = TJsonStringWriter<TCondensedJsonPrintPolicy<wchar_t>>::Create(&BodyString);
	Body->BeamSerialize(JsonSerializer);
	JsonSerializer->Close();
}

UPutDonationsRequest* UPutDonationsRequest::Make(int64 _ObjectId, int64 _RecipientId, int64 _Amount, FOptionalBool _bAutoClaim, UObject* RequestOwner)
{
	UPutDonationsRequest* Req = NewObject<UPutDonationsRequest>(RequestOwner);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	Req->ObjectId = _ObjectId;
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	Req->Body = NewObject<UMakeDonationRequestBody>(Req);
	Req->Body->RecipientId = _RecipientId;
	Req->Body->Amount = _Amount;
	Req->Body->bAutoClaim = _bAutoClaim;
	

	return Req;
}
