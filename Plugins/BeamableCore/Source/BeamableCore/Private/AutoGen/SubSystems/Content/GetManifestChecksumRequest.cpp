
#include "AutoGen/SubSystems/Content/GetManifestChecksumRequest.h"

void UGetManifestChecksumRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("GET");
}

void UGetManifestChecksumRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/basic/content/manifest/checksum");
	
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	if(Id.IsSet){
		bIsFirstQueryParam ? QueryParams.Append(TEXT("?")) : QueryParams.Append(TEXT("&"));
		QueryParams.Appendf(TEXT("%s=%s"), TEXT("id"), *static_cast<FString>(Id.Val));
		bIsFirstQueryParam = false;
	}

	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UGetManifestChecksumRequest::BuildBody(FString& BodyString) const
{
	
}

UGetManifestChecksumRequest* UGetManifestChecksumRequest::Make(FOptionalBeamContentManifestId _Id, UObject* RequestOwner)
{
	UGetManifestChecksumRequest* Req = NewObject<UGetManifestChecksumRequest>(RequestOwner);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	Req->Id = _Id;
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	

	return Req;
}
