
#include "BeamableCore/Public/AutoGen/SubSystems/Lobby/PutLobbyRequest.h"

void UPutLobbyRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("PUT");
}

void UPutLobbyRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/api/lobbies/{id}");
	Route = Route.Replace(TEXT("{id}"), *Id.ToString(EGuidFormats::DigitsLower));
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UPutLobbyRequest::BuildBody(FString& BodyString) const
{
	ensureAlways(Body);

	TUnrealJsonSerializer JsonSerializer = TJsonStringWriter<TCondensedJsonPrintPolicy<wchar_t>>::Create(&BodyString);
	Body->BeamSerialize(JsonSerializer);
	JsonSerializer->Close();
}

UPutLobbyRequest* UPutLobbyRequest::Make(FGuid _Id, FOptionalArrayOfTag _Tags, UObject* RequestOwner)
{
	UPutLobbyRequest* Req = NewObject<UPutLobbyRequest>(RequestOwner);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	Req->Id = _Id;
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	Req->Body = NewObject<UJoinLobby>(Req);
	Req->Body->Tags = _Tags;
	

	return Req;
}