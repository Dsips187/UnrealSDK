
#include "AutoGen/SubSystems/Beamo/PostManifestDeployRequest.h"

void UPostManifestDeployRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("POST");
}

void UPostManifestDeployRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/basic/beamo/manifest/deploy");
	
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UPostManifestDeployRequest::BuildBody(FString& BodyString) const
{
	
}

UPostManifestDeployRequest* UPostManifestDeployRequest::Make(UObject* RequestOwner)
{
	UPostManifestDeployRequest* Req = NewObject<UPostManifestDeployRequest>(RequestOwner);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	

	return Req;
}
