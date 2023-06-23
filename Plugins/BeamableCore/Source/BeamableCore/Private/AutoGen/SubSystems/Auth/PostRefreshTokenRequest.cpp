
#include "BeamableCore/Public/AutoGen/SubSystems/Auth/PostRefreshTokenRequest.h"

void UPostRefreshTokenRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("POST");
}

void UPostRefreshTokenRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/api/auth/refresh-token");
	
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UPostRefreshTokenRequest::BuildBody(FString& BodyString) const
{
	ensureAlways(Body);

	TUnrealJsonSerializer JsonSerializer = TJsonStringWriter<TCondensedJsonPrintPolicy<wchar_t>>::Create(&BodyString);
	Body->BeamSerialize(JsonSerializer);
	JsonSerializer->Close();
}

UPostRefreshTokenRequest* UPostRefreshTokenRequest::Make(FOptionalString _RefreshToken, FOptionalBeamCid _CustomerId, FOptionalBeamPid _RealmId, UObject* RequestOwner)
{
	UPostRefreshTokenRequest* Req = NewObject<UPostRefreshTokenRequest>(RequestOwner);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	Req->Body = NewObject<URefreshTokenAuthRequestBody>(Req);
	Req->Body->RefreshToken = _RefreshToken;
	Req->Body->CustomerId = _CustomerId;
	Req->Body->RealmId = _RealmId;
	

	return Req;
}
