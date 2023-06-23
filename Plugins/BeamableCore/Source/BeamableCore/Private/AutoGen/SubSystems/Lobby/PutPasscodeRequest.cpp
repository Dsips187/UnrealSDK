
#include "BeamableCore/Public/AutoGen/SubSystems/Lobby/PutPasscodeRequest.h"

void UPutPasscodeRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("PUT");
}

void UPutPasscodeRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/api/lobbies/passcode");
	
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UPutPasscodeRequest::BuildBody(FString& BodyString) const
{
	ensureAlways(Body);

	TUnrealJsonSerializer JsonSerializer = TJsonStringWriter<TCondensedJsonPrintPolicy<wchar_t>>::Create(&BodyString);
	Body->BeamSerialize(JsonSerializer);
	JsonSerializer->Close();
}

UPutPasscodeRequest* UPutPasscodeRequest::Make(FOptionalString _Passcode, FOptionalArrayOfTag _Tags, UObject* RequestOwner)
{
	UPutPasscodeRequest* Req = NewObject<UPutPasscodeRequest>(RequestOwner);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	Req->Body = NewObject<UJoinLobbyByPasscode>(Req);
	Req->Body->Passcode = _Passcode;
	Req->Body->Tags = _Tags;
	

	return Req;
}
