
#include "AutoGen/SubSystems/Tournaments/ObjectTournamentsGetTournamentsRequest.h"

void UObjectTournamentsGetTournamentsRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("GET");
}

void UObjectTournamentsGetTournamentsRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/object/tournaments/{objectId}/");
	Route = Route.Replace(TEXT("{objectId}"), *FString::FromInt(ObjectId));
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UObjectTournamentsGetTournamentsRequest::BuildBody(FString& BodyString) const
{
	
}

UObjectTournamentsGetTournamentsRequest* UObjectTournamentsGetTournamentsRequest::Make(int64 _ObjectId, UObject* RequestOwner)
{
	UObjectTournamentsGetTournamentsRequest* Req = NewObject<UObjectTournamentsGetTournamentsRequest>(RequestOwner);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	Req->ObjectId = _ObjectId;
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	

	return Req;
}