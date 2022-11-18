
#include "AutoGen/SubSystems/Stats/GetClientRequest.h"

void UGetClientRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("GET");
}

void UGetClientRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/object/stats/{objectId}/client");
	Route = Route.Replace(TEXT("{objectId}"), *ObjectId);
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	if(Stats.IsSet){
		bIsFirstQueryParam ? QueryParams.Append(TEXT("?")) : QueryParams.Append(TEXT("&"));
		QueryParams.Appendf(TEXT("%s=%s"), TEXT("stats"), *Stats.Val);
		bIsFirstQueryParam = false;
	}

	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UGetClientRequest::BuildBody(FString& BodyString) const
{
	
}

UGetClientRequest* UGetClientRequest::Make(FString _ObjectId, FOptionalString _Stats, UObject* RequestOwner)
{
	UGetClientRequest* Req = NewObject<UGetClientRequest>(RequestOwner);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	Req->ObjectId = _ObjectId;
	Req->Stats = _Stats;
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	

	return Req;
}
