
#include "AutoGen/SubSystems/Beamo/GetManifestCurrentRequest.h"

void UGetManifestCurrentRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("GET");
}

void UGetManifestCurrentRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/basic/beamo/manifest/current");
	
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	if(bArchived.IsSet){
		bIsFirstQueryParam ? QueryParams.Append(TEXT("?")) : QueryParams.Append(TEXT("&"));
		QueryParams.Appendf(TEXT("%s=%s"), TEXT("archived"), bArchived.Val ? TEXT("true") : TEXT("false"));
		bIsFirstQueryParam = false;
	}

	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UGetManifestCurrentRequest::BuildBody(FString& BodyString) const
{
	
}

UGetManifestCurrentRequest* UGetManifestCurrentRequest::Make(FOptionalBool _bArchived, UObject* RequestOwner)
{
	UGetManifestCurrentRequest* Req = NewObject<UGetManifestCurrentRequest>(RequestOwner);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	Req->bArchived = _bArchived;
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	

	return Req;
}
