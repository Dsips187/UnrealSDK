
#include "BeamableCore/Public/AutoGen/SubSystems/Content/PutManifestRepeatRequest.h"

void UPutManifestRepeatRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("PUT");
}

void UPutManifestRepeatRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/basic/content/manifest/repeat");
	
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UPutManifestRepeatRequest::BuildBody(FString& BodyString) const
{
	ensureAlways(Body);

	TUnrealJsonSerializer JsonSerializer = TJsonStringWriter<TCondensedJsonPrintPolicy<wchar_t>>::Create(&BodyString);
	Body->BeamSerialize(JsonSerializer);
	JsonSerializer->Close();
}

UPutManifestRepeatRequest* UPutManifestRepeatRequest::Make(FString _Uid, UObject* RequestOwner)
{
	UPutManifestRepeatRequest* Req = NewObject<UPutManifestRepeatRequest>(RequestOwner);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	Req->Body = NewObject<URepeatManifestRequestBody>(Req);
	Req->Body->Uid = _Uid;
	

	return Req;
}
