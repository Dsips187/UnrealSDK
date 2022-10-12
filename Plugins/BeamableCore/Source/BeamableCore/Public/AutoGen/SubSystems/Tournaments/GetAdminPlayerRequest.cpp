
#include "GetAdminPlayerRequest.h"

void UGetAdminPlayerRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("GET");
}

void UGetAdminPlayerRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/basic/tournaments/admin/player");
	
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	bIsFirstQueryParam ? QueryParams.Append(TEXT("?")) : QueryParams.Append(TEXT("&"));
	QueryParams.Appendf(TEXT("%s=%s"), *TEXT("playerId"), *FString::FromInt(PlayerId));
	bIsFirstQueryParam = false;
	
	if(TournamentId.IsSet){
		bIsFirstQueryParam ? QueryParams.Append(TEXT("?")) : QueryParams.Append(TEXT("&"));
		QueryParams.Appendf(TEXT("%s=%s"), *TEXT("tournamentId"), *TournamentId.Val);
		bIsFirstQueryParam = false;
	}

	if(ContentId.IsSet){
		bIsFirstQueryParam ? QueryParams.Append(TEXT("?")) : QueryParams.Append(TEXT("&"));
		QueryParams.Appendf(TEXT("%s=%s"), *TEXT("contentId"), *ContentId.Val);
		bIsFirstQueryParam = false;
	}

	if(bHasUnclaimedRewards.IsSet){
		bIsFirstQueryParam ? QueryParams.Append(TEXT("?")) : QueryParams.Append(TEXT("&"));
		QueryParams.Appendf(TEXT("%s=%s"), *TEXT("hasUnclaimedRewards"), bHasUnclaimedRewards.Val ? *TEXT("true") : *TEXT("false"));
		bIsFirstQueryParam = false;
	}

	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UGetAdminPlayerRequest::BuildBody(FString& BodyString) const
{
	
}

UGetAdminPlayerRequest* UGetAdminPlayerRequest::MakeGetAdminPlayerRequest(int64 _PlayerId, FOptionalString _TournamentId, FOptionalString _ContentId, FOptionalBool _bHasUnclaimedRewards, UObject* Outer)
{
	UGetAdminPlayerRequest* Req = NewObject<UGetAdminPlayerRequest>(Outer);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	Req->PlayerId = _PlayerId;
	Req->TournamentId = _TournamentId;
	Req->ContentId = _ContentId;
	Req->bHasUnclaimedRewards = _bHasUnclaimedRewards;
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	

	return Req;
}
