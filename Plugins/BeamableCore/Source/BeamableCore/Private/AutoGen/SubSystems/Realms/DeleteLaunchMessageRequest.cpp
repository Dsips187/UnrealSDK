
#include "AutoGen/SubSystems/Realms/DeleteLaunchMessageRequest.h"

void UDeleteLaunchMessageRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("DELETE");
}

void UDeleteLaunchMessageRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/basic/realms/launch-message");
	
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UDeleteLaunchMessageRequest::BuildBody(FString& BodyString) const
{
	ensureAlways(Body);

	TUnrealJsonSerializer JsonSerializer = TJsonStringWriter<TCondensedJsonPrintPolicy<wchar_t>>::Create(&BodyString);
	Body->BeamSerialize(JsonSerializer);
	JsonSerializer->Close();
}

UDeleteLaunchMessageRequest* UDeleteLaunchMessageRequest::Make(FString _File, UObject* RequestOwner)
{
	UDeleteLaunchMessageRequest* Req = NewObject<UDeleteLaunchMessageRequest>(RequestOwner);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	Req->Body = NewObject<URemoveLaunchMessageRequestBody>(Req);
	Req->Body->File = _File;
	

	return Req;
}