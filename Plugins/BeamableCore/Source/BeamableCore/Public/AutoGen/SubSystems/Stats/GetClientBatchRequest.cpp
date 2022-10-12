
#include "GetClientBatchRequest.h"

void UGetClientBatchRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("GET");
}

void UGetClientBatchRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/basic/stats/client/batch");
	
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	bIsFirstQueryParam ? QueryParams.Append(TEXT("?")) : QueryParams.Append(TEXT("&"));
	QueryParams.Appendf(TEXT("%s=%s"), *TEXT("objectIds"), *ObjectIds);
	bIsFirstQueryParam = false;
	
	if(Stats.IsSet){
		bIsFirstQueryParam ? QueryParams.Append(TEXT("?")) : QueryParams.Append(TEXT("&"));
		QueryParams.Appendf(TEXT("%s=%s"), *TEXT("stats"), *Stats.Val);
		bIsFirstQueryParam = false;
	}

	if(Format.IsSet){
		bIsFirstQueryParam ? QueryParams.Append(TEXT("?")) : QueryParams.Append(TEXT("&"));
		QueryParams.Appendf(TEXT("%s=%s"), *TEXT("format"), *Format.Val);
		bIsFirstQueryParam = false;
	}

	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UGetClientBatchRequest::BuildBody(FString& BodyString) const
{
	
}

UGetClientBatchRequest* UGetClientBatchRequest::MakeGetClientBatchRequest(FString _ObjectIds, FOptionalString _Stats, FOptionalString _Format, UObject* Outer)
{
	UGetClientBatchRequest* Req = NewObject<UGetClientBatchRequest>(Outer);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	Req->ObjectIds = _ObjectIds;
	Req->Stats = _Stats;
	Req->Format = _Format;
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	

	return Req;
}
