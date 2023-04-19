
#include "BeamableCore/Public/AutoGen/SubSystems/Inventory/PutProxyReloadRequest.h"

void UPutProxyReloadRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("PUT");
}

void UPutProxyReloadRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/object/inventory/{objectId}/proxy/reload");
	Route = Route.Replace(TEXT("{objectId}"), *static_cast<FString>(ObjectId));
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UPutProxyReloadRequest::BuildBody(FString& BodyString) const
{
	
}

UPutProxyReloadRequest* UPutProxyReloadRequest::Make(FBeamGamerTag _ObjectId, UObject* RequestOwner)
{
	UPutProxyReloadRequest* Req = NewObject<UPutProxyReloadRequest>(RequestOwner);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	Req->ObjectId = _ObjectId;
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	

	return Req;
}
