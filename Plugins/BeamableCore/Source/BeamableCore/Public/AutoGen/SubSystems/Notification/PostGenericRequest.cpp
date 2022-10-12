
#include "PostGenericRequest.h"

void UPostGenericRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("POST");
}

void UPostGenericRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/basic/notification/generic");
	
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UPostGenericRequest::BuildBody(FString& BodyString) const
{
	ensureAlways(Body);

	TUnrealJsonSerializer JsonSerializer = TJsonStringWriter<TCondensedJsonPrintPolicy<wchar_t>>::Create(&BodyString);
	Body->BeamSerialize(JsonSerializer);
	JsonSerializer->Close();
}

UPostGenericRequest* UPostGenericRequest::MakePostGenericRequest(UNotificationRequestData* _Payload, FOptionalString _CustomChannelSuffix, FOptionalInt64 _Dbid, FOptionalBool _bUseSignalWhenPossible, FOptionalArrayOfInt64 _Dbids, UObject* Outer)
{
	UPostGenericRequest* Req = NewObject<UPostGenericRequest>(Outer);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	Req->Body = NewObject<UNotificationRequestBody>(Req);
	// Assumes the object is constructed and have the new request take ownership of the memory for it
	Req->Body->Payload = _Payload;
	Req->Body->Payload->Rename(nullptr, Req);
	Req->Body->CustomChannelSuffix = _CustomChannelSuffix;
	Req->Body->Dbid = _Dbid;
	Req->Body->bUseSignalWhenPossible = _bUseSignalWhenPossible;
	Req->Body->Dbids = _Dbids;
	

	return Req;
}
