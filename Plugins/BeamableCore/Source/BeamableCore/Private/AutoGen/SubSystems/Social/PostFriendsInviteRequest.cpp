
#include "AutoGen/SubSystems/Social/PostFriendsInviteRequest.h"

void UPostFriendsInviteRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("POST");
}

void UPostFriendsInviteRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/basic/social/friends/invite");
	
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UPostFriendsInviteRequest::BuildBody(FString& BodyString) const
{
	ensureAlways(Body);

	TUnrealJsonSerializer JsonSerializer = TJsonStringWriter<TCondensedJsonPrintPolicy<wchar_t>>::Create(&BodyString);
	Body->BeamSerialize(JsonSerializer);
	JsonSerializer->Close();
}

UPostFriendsInviteRequest* UPostFriendsInviteRequest::Make(int64 _GamerTag, UObject* RequestOwner)
{
	UPostFriendsInviteRequest* Req = NewObject<UPostFriendsInviteRequest>(RequestOwner);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	Req->Body = NewObject<USendFriendRequestBody>(Req);
	Req->Body->GamerTag = _GamerTag;
	

	return Req;
}
