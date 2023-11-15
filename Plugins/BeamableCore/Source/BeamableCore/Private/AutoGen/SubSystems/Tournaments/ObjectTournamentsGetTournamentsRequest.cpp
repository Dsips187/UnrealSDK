
#include "BeamableCore/Public/AutoGen/SubSystems/Tournaments/ObjectTournamentsGetTournamentsRequest.h"

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

UObjectTournamentsGetTournamentsRequest* UObjectTournamentsGetTournamentsRequest::Make(int64 _ObjectId, UObject* RequestOwner, TMap<FString, FString> CustomHeaders)
{
	UObjectTournamentsGetTournamentsRequest* Req = NewObject<UObjectTournamentsGetTournamentsRequest>(RequestOwner);
	Req->CustomHeaders = TMap{CustomHeaders};

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	Req->ObjectId = _ObjectId;
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	

	return Req;
}
