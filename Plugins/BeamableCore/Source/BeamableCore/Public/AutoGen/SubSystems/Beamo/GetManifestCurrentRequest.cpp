
#include "GetManifestCurrentRequest.h"

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
		QueryParams.Appendf(TEXT("%s=%s"), *TEXT("archived"), bArchived.Val ? *TEXT("true") : *TEXT("false"));
		bIsFirstQueryParam = false;
	}

	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UGetManifestCurrentRequest::BuildBody(FString& BodyString) const
{
	
}

UGetManifestCurrentRequest* UGetManifestCurrentRequest::MakeGetManifestCurrentRequest(FOptionalBool _bArchived, UObject* Outer)
{
	UGetManifestCurrentRequest* Req = NewObject<UGetManifestCurrentRequest>(Outer);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	Req->bArchived = _bArchived;
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	

	return Req;
}
