
#include "DeleteEntriesRequest.h"

void UDeleteEntriesRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("DELETE");
}

void UDeleteEntriesRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/object/leaderboards/{objectId}/entries");
	Route = Route.Replace(TEXT("{objectId}"), *ObjectId);
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UDeleteEntriesRequest::BuildBody(FString& BodyString) const
{
	
}

UDeleteEntriesRequest* UDeleteEntriesRequest::MakeDeleteEntriesRequest(FString _ObjectId, UObject* Outer)
{
	UDeleteEntriesRequest* Req = NewObject<UDeleteEntriesRequest>(Outer);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	Req->ObjectId = _ObjectId;
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	

	return Req;
}
