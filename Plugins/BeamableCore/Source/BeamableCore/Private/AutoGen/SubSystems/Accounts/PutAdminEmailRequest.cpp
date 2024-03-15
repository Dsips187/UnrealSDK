
#include "BeamableCore/Public/AutoGen/SubSystems/Accounts/PutAdminEmailRequest.h"

void UPutAdminEmailRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("PUT");
}

void UPutAdminEmailRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/object/accounts/{objectId}/admin/email");
	Route = Route.Replace(TEXT("{objectId}"), *static_cast<FString>(ObjectId));
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UPutAdminEmailRequest::BuildBody(FString& BodyString) const
{
	ensureAlways(Body);

	TUnrealJsonSerializer JsonSerializer = TJsonStringWriter<TCondensedJsonPrintPolicy<TCHAR>>::Create(&BodyString);
	Body->BeamSerialize(JsonSerializer);
	JsonSerializer->Close();
}

UPutAdminEmailRequest* UPutAdminEmailRequest::Make(FBeamAccountId _ObjectId, FString _NewEmail, FOptionalString _CodeType, UObject* RequestOwner, TMap<FString, FString> CustomHeaders)
{
	UPutAdminEmailRequest* Req = NewObject<UPutAdminEmailRequest>(RequestOwner);
	Req->CustomHeaders = TMap{CustomHeaders};

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	Req->ObjectId = _ObjectId;
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	Req->Body = NewObject<UEmailUpdateRequestBody>(Req);
	Req->Body->NewEmail = _NewEmail;
	Req->Body->CodeType = _CodeType;
	

	return Req;
}
