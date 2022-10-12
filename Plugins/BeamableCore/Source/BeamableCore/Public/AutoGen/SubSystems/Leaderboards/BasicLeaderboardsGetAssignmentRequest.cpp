
#include "BasicLeaderboardsGetAssignmentRequest.h"

void UBasicLeaderboardsGetAssignmentRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("GET");
}

void UBasicLeaderboardsGetAssignmentRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/basic/leaderboards/assignment");
	
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	bIsFirstQueryParam ? QueryParams.Append(TEXT("?")) : QueryParams.Append(TEXT("&"));
	QueryParams.Appendf(TEXT("%s=%s"), *TEXT("boardId"), *BoardId);
	bIsFirstQueryParam = false;
	
	if(bJoinBoard.IsSet){
		bIsFirstQueryParam ? QueryParams.Append(TEXT("?")) : QueryParams.Append(TEXT("&"));
		QueryParams.Appendf(TEXT("%s=%s"), *TEXT("joinBoard"), bJoinBoard.Val ? *TEXT("true") : *TEXT("false"));
		bIsFirstQueryParam = false;
	}

	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UBasicLeaderboardsGetAssignmentRequest::BuildBody(FString& BodyString) const
{
	
}

UBasicLeaderboardsGetAssignmentRequest* UBasicLeaderboardsGetAssignmentRequest::MakeBasicLeaderboardsGetAssignmentRequest(FString _BoardId, FOptionalBool _bJoinBoard, UObject* Outer)
{
	UBasicLeaderboardsGetAssignmentRequest* Req = NewObject<UBasicLeaderboardsGetAssignmentRequest>(Outer);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	Req->BoardId = _BoardId;
	Req->bJoinBoard = _bJoinBoard;
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	

	return Req;
}
