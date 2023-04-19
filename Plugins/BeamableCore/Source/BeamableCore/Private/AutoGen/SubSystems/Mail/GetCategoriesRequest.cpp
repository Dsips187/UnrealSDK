
#include "BeamableCore/Public/AutoGen/SubSystems/Mail/GetCategoriesRequest.h"

void UGetCategoriesRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("GET");
}

void UGetCategoriesRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/object/mail/{objectId}/categories");
	Route = Route.Replace(TEXT("{objectId}"), *FString::FromInt(ObjectId));
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UGetCategoriesRequest::BuildBody(FString& BodyString) const
{
	
}

UGetCategoriesRequest* UGetCategoriesRequest::Make(int64 _ObjectId, UObject* RequestOwner)
{
	UGetCategoriesRequest* Req = NewObject<UGetCategoriesRequest>(RequestOwner);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	Req->ObjectId = _ObjectId;
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	

	return Req;
}
