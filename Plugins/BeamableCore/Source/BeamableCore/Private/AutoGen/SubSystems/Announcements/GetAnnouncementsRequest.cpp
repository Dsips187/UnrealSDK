
#include "AutoGen/SubSystems/Announcements/GetAnnouncementsRequest.h"

void UGetAnnouncementsRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("GET");
}

void UGetAnnouncementsRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/object/announcements/{objectId}/");
	Route = Route.Replace(TEXT("{objectId}"), *FString::FromInt(ObjectId));
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	if(bIncludeDeleted.IsSet){
		bIsFirstQueryParam ? QueryParams.Append(TEXT("?")) : QueryParams.Append(TEXT("&"));
		QueryParams.Appendf(TEXT("%s=%s"), TEXT("include_deleted"), bIncludeDeleted.Val ? TEXT("true") : TEXT("false"));
		bIsFirstQueryParam = false;
	}

	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UGetAnnouncementsRequest::BuildBody(FString& BodyString) const
{
	
}

UGetAnnouncementsRequest* UGetAnnouncementsRequest::Make(int64 _ObjectId, FOptionalBool _bIncludeDeleted, UObject* RequestOwner)
{
	UGetAnnouncementsRequest* Req = NewObject<UGetAnnouncementsRequest>(RequestOwner);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	Req->ObjectId = _ObjectId;
	Req->bIncludeDeleted = _bIncludeDeleted;
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	

	return Req;
}
