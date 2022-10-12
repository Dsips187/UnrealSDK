
#include "GetStandingsRequest.h"

void UGetStandingsRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("GET");
}

void UGetStandingsRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/basic/tournaments/standings");
	
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	bIsFirstQueryParam ? QueryParams.Append(TEXT("?")) : QueryParams.Append(TEXT("&"));
	QueryParams.Appendf(TEXT("%s=%s"), *TEXT("tournamentId"), *TournamentId);
	bIsFirstQueryParam = false;
	
	if(Max.IsSet){
		bIsFirstQueryParam ? QueryParams.Append(TEXT("?")) : QueryParams.Append(TEXT("&"));
		QueryParams.Appendf(TEXT("%s=%s"), *TEXT("max"), *FString::FromInt(Max.Val));
		bIsFirstQueryParam = false;
	}

	if(Focus.IsSet){
		bIsFirstQueryParam ? QueryParams.Append(TEXT("?")) : QueryParams.Append(TEXT("&"));
		QueryParams.Appendf(TEXT("%s=%s"), *TEXT("focus"), *FString::FromInt(Focus.Val));
		bIsFirstQueryParam = false;
	}

	if(Cycle.IsSet){
		bIsFirstQueryParam ? QueryParams.Append(TEXT("?")) : QueryParams.Append(TEXT("&"));
		QueryParams.Appendf(TEXT("%s=%s"), *TEXT("cycle"), *FString::FromInt(Cycle.Val));
		bIsFirstQueryParam = false;
	}

	if(From.IsSet){
		bIsFirstQueryParam ? QueryParams.Append(TEXT("?")) : QueryParams.Append(TEXT("&"));
		QueryParams.Appendf(TEXT("%s=%s"), *TEXT("from"), *FString::FromInt(From.Val));
		bIsFirstQueryParam = false;
	}

	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UGetStandingsRequest::BuildBody(FString& BodyString) const
{
	
}

UGetStandingsRequest* UGetStandingsRequest::MakeGetStandingsRequest(FString _TournamentId, FOptionalInt32 _Max, FOptionalInt64 _Focus, FOptionalInt32 _Cycle, FOptionalInt32 _From, UObject* Outer)
{
	UGetStandingsRequest* Req = NewObject<UGetStandingsRequest>(Outer);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	Req->TournamentId = _TournamentId;
	Req->Max = _Max;
	Req->Focus = _Focus;
	Req->Cycle = _Cycle;
	Req->From = _From;
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	

	return Req;
}
