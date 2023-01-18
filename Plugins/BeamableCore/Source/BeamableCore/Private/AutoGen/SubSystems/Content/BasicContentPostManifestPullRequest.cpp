
#include "AutoGen/SubSystems/Content/BasicContentPostManifestPullRequest.h"

void UBasicContentPostManifestPullRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("POST");
}

void UBasicContentPostManifestPullRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/basic/content/manifest/pull");
	
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UBasicContentPostManifestPullRequest::BuildBody(FString& BodyString) const
{
	ensureAlways(Body);

	TUnrealJsonSerializer JsonSerializer = TJsonStringWriter<TCondensedJsonPrintPolicy<wchar_t>>::Create(&BodyString);
	Body->BeamSerialize(JsonSerializer);
	JsonSerializer->Close();
}

UBasicContentPostManifestPullRequest* UBasicContentPostManifestPullRequest::Make(FBeamPid _SourceRealmPid, FOptionalBeamContentManifestId _Id, UObject* RequestOwner)
{
	UBasicContentPostManifestPullRequest* Req = NewObject<UBasicContentPostManifestPullRequest>(RequestOwner);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	Req->Body = NewObject<UPullManifestRequestBody>(Req);
	Req->Body->SourceRealmPid = _SourceRealmPid;
	Req->Body->Id = _Id;
	

	return Req;
}
