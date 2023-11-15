
#include "BeamableCore/Public/AutoGen/SubSystems/Lobby/GetLobbiesRequest.h"

void UGetLobbiesRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("GET");
}

void UGetLobbiesRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/api/lobbies");
	
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	if(Skip.IsSet){
		bIsFirstQueryParam ? QueryParams.Append(TEXT("?")) : QueryParams.Append(TEXT("&"));
		QueryParams.Appendf(TEXT("%s=%s"), TEXT("Skip"), *FString::FromInt(Skip.Val));
		bIsFirstQueryParam = false;
	}

	if(Limit.IsSet){
		bIsFirstQueryParam ? QueryParams.Append(TEXT("?")) : QueryParams.Append(TEXT("&"));
		QueryParams.Appendf(TEXT("%s=%s"), TEXT("Limit"), *FString::FromInt(Limit.Val));
		bIsFirstQueryParam = false;
	}

	if(MatchType.IsSet){
		bIsFirstQueryParam ? QueryParams.Append(TEXT("?")) : QueryParams.Append(TEXT("&"));
		QueryParams.Appendf(TEXT("%s=%s"), TEXT("MatchType"), *static_cast<FString>(MatchType.Val));
		bIsFirstQueryParam = false;
	}

	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UGetLobbiesRequest::BuildBody(FString& BodyString) const
{
	
}

UGetLobbiesRequest* UGetLobbiesRequest::Make(FOptionalInt32 _Skip, FOptionalInt32 _Limit, FOptionalBeamContentId _MatchType, UObject* RequestOwner, TMap<FString, FString> CustomHeaders)
{
	UGetLobbiesRequest* Req = NewObject<UGetLobbiesRequest>(RequestOwner);
	Req->CustomHeaders = TMap{CustomHeaders};

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	Req->Skip = _Skip;
	Req->Limit = _Limit;
	Req->MatchType = _MatchType;
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	

	return Req;
}
