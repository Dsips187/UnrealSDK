
#include "ObjectGroupsGetGroupsRequest.h"

void UObjectGroupsGetGroupsRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("GET");
}

void UObjectGroupsGetGroupsRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/object/groups/{objectId}/");
	Route = Route.Replace(TEXT("{objectId}"), *FString::FromInt(ObjectId));
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UObjectGroupsGetGroupsRequest::BuildBody(FString& BodyString) const
{
	
}

UObjectGroupsGetGroupsRequest* UObjectGroupsGetGroupsRequest::MakeObjectGroupsGetGroupsRequest(int64 _ObjectId, UObject* Outer)
{
	UObjectGroupsGetGroupsRequest* Req = NewObject<UObjectGroupsGetGroupsRequest>(Outer);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	Req->ObjectId = _ObjectId;
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	

	return Req;
}
