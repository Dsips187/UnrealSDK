
#include "AutoGen/SubSystems/Social/PostFriendsImportRequest.h"

void UPostFriendsImportRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("POST");
}

void UPostFriendsImportRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/basic/social/friends/import");
	
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UPostFriendsImportRequest::BuildBody(FString& BodyString) const
{
	ensureAlways(Body);

	TUnrealJsonSerializer JsonSerializer = TJsonStringWriter<TCondensedJsonPrintPolicy<wchar_t>>::Create(&BodyString);
	Body->BeamSerialize(JsonSerializer);
	JsonSerializer->Close();
}

UPostFriendsImportRequest* UPostFriendsImportRequest::Make(FString _Source, FString _Token, UObject* RequestOwner)
{
	UPostFriendsImportRequest* Req = NewObject<UPostFriendsImportRequest>(RequestOwner);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	Req->Body = NewObject<UImportFriendsRequestBody>(Req);
	Req->Body->Source = _Source;
	Req->Body->Token = _Token;
	

	return Req;
}
