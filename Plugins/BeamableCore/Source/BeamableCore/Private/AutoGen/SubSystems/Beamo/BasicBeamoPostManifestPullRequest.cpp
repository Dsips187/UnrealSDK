
#include "BeamableCore/Public/AutoGen/SubSystems/Beamo/BasicBeamoPostManifestPullRequest.h"

void UBasicBeamoPostManifestPullRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("POST");
}

void UBasicBeamoPostManifestPullRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/basic/beamo/manifest/pull");
	
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UBasicBeamoPostManifestPullRequest::BuildBody(FString& BodyString) const
{
	ensureAlways(Body);

	TUnrealJsonSerializer JsonSerializer = TJsonStringWriter<TCondensedJsonPrintPolicy<wchar_t>>::Create(&BodyString);
	Body->BeamSerialize(JsonSerializer);
	JsonSerializer->Close();
}

UBasicBeamoPostManifestPullRequest* UBasicBeamoPostManifestPullRequest::Make(FString _SourceRealmPid, UObject* RequestOwner)
{
	UBasicBeamoPostManifestPullRequest* Req = NewObject<UBasicBeamoPostManifestPullRequest>(RequestOwner);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	Req->Body = NewObject<UPullBeamoManifestRequestBody>(Req);
	Req->Body->SourceRealmPid = _SourceRealmPid;
	

	return Req;
}
