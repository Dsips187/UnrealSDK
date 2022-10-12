
#include "GetLaunchMessageRequest.h"

void UGetLaunchMessageRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("GET");
}

void UGetLaunchMessageRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/basic/realms/launch-message");
	
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UGetLaunchMessageRequest::BuildBody(FString& BodyString) const
{
	
}

UGetLaunchMessageRequest* UGetLaunchMessageRequest::MakeGetLaunchMessageRequest(UObject* Outer)
{
	UGetLaunchMessageRequest* Req = NewObject<UGetLaunchMessageRequest>(Outer);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	

	return Req;
}
