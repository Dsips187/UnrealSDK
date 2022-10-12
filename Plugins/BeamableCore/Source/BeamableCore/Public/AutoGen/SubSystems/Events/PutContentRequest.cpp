
#include "PutContentRequest.h"

void UPutContentRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("PUT");
}

void UPutContentRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/object/events/{objectId}/content");
	Route = Route.Replace(TEXT("{objectId}"), *FString::FromInt(ObjectId));
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UPutContentRequest::BuildBody(FString& BodyString) const
{
	ensureAlways(Body);

	TUnrealJsonSerializer JsonSerializer = TJsonStringWriter<TCondensedJsonPrintPolicy<wchar_t>>::Create(&BodyString);
	Body->BeamSerialize(JsonSerializer);
	JsonSerializer->Close();
}

UPutContentRequest* UPutContentRequest::MakePutContentRequest(int64 _ObjectId, UEvent* _Event, FString _Origin, FOptionalString _RootEventId, FOptionalString _OriginType, UObject* Outer)
{
	UPutContentRequest* Req = NewObject<UPutContentRequest>(Outer);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	Req->ObjectId = _ObjectId;
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	Req->Body = NewObject<USetContentRequestBody>(Req);
	// Assumes the object is constructed and have the new request take ownership of the memory for it
	Req->Body->Event = _Event;
	Req->Body->Event->Rename(nullptr, Req);
	Req->Body->Origin = _Origin;
	Req->Body->RootEventId = _RootEventId;
	Req->Body->OriginType = _OriginType;
	

	return Req;
}
