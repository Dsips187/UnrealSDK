
#include "BeamableCore/Public/AutoGen/SubSystems/Tournaments/PostTournamentsRequest.h"

void UPostTournamentsRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("POST");
}

void UPostTournamentsRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/basic/tournaments/");
	
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UPostTournamentsRequest::BuildBody(FString& BodyString) const
{
	ensureAlways(Body);

	TUnrealJsonSerializer JsonSerializer = TJsonStringWriter<TCondensedJsonPrintPolicy<wchar_t>>::Create(&BodyString);
	Body->BeamSerialize(JsonSerializer);
	JsonSerializer->Close();
}

UPostTournamentsRequest* UPostTournamentsRequest::Make(FString _TournamentId, UObject* RequestOwner)
{
	UPostTournamentsRequest* Req = NewObject<UPostTournamentsRequest>(RequestOwner);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	Req->Body = NewObject<UJoinRequestBody>(Req);
	Req->Body->TournamentId = _TournamentId;
	

	return Req;
}
