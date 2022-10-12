
#include "ObjectLeaderboardsGetAssignmentRequest.h"

void UObjectLeaderboardsGetAssignmentRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("GET");
}

void UObjectLeaderboardsGetAssignmentRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/object/leaderboards/{objectId}/assignment");
	Route = Route.Replace(TEXT("{objectId}"), *ObjectId);
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UObjectLeaderboardsGetAssignmentRequest::BuildBody(FString& BodyString) const
{
	
}

UObjectLeaderboardsGetAssignmentRequest* UObjectLeaderboardsGetAssignmentRequest::MakeObjectLeaderboardsGetAssignmentRequest(FString _ObjectId, UObject* Outer)
{
	UObjectLeaderboardsGetAssignmentRequest* Req = NewObject<UObjectLeaderboardsGetAssignmentRequest>(Outer);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	Req->ObjectId = _ObjectId;
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	

	return Req;
}
