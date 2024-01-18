
#include "BeamableCore/Public/AutoGen/SubSystems/Notification/BasicNotificationPostServerRequest.h"

void UBasicNotificationPostServerRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("POST");
}

void UBasicNotificationPostServerRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/basic/notification/server");
	
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UBasicNotificationPostServerRequest::BuildBody(FString& BodyString) const
{
	ensureAlways(Body);

	TUnrealJsonSerializer JsonSerializer = TJsonStringWriter<TCondensedJsonPrintPolicy<TCHAR>>::Create(&BodyString);
	Body->BeamSerialize(JsonSerializer);
	JsonSerializer->Close();
}

UBasicNotificationPostServerRequest* UBasicNotificationPostServerRequest::Make(FString _Event, bool _bToAll, FOptionalString _Payload, UObject* RequestOwner, TMap<FString, FString> CustomHeaders)
{
	UBasicNotificationPostServerRequest* Req = NewObject<UBasicNotificationPostServerRequest>(RequestOwner);
	Req->CustomHeaders = TMap{CustomHeaders};

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	Req->Body = NewObject<UServerEvent>(Req);
	Req->Body->Event = _Event;
	Req->Body->bToAll = _bToAll;
	Req->Body->Payload = _Payload;
	

	return Req;
}
