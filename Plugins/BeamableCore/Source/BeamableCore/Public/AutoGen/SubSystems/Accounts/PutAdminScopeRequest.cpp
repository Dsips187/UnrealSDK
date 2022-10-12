
#include "PutAdminScopeRequest.h"

void UPutAdminScopeRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("PUT");
}

void UPutAdminScopeRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/object/accounts/{objectId}/admin/scope");
	Route = Route.Replace(TEXT("{objectId}"), *FString::FromInt(ObjectId));
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UPutAdminScopeRequest::BuildBody(FString& BodyString) const
{
	ensureAlways(Body);

	TUnrealJsonSerializer JsonSerializer = TJsonStringWriter<TCondensedJsonPrintPolicy<wchar_t>>::Create(&BodyString);
	Body->BeamSerialize(JsonSerializer);
	JsonSerializer->Close();
}

UPutAdminScopeRequest* UPutAdminScopeRequest::MakePutAdminScopeRequest(int64 _ObjectId, FOptionalString _Cid, FOptionalString _Realm, FOptionalString _Role, UObject* Outer)
{
	UPutAdminScopeRequest* Req = NewObject<UPutAdminScopeRequest>(Outer);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	Req->ObjectId = _ObjectId;
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	Req->Body = NewObject<UUpdateRole>(Req);
	Req->Body->Cid = _Cid;
	Req->Body->Realm = _Realm;
	Req->Body->Role = _Role;
	

	return Req;
}
