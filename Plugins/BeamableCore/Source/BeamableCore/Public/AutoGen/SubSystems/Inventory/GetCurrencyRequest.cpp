
#include "GetCurrencyRequest.h"

void UGetCurrencyRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("GET");
}

void UGetCurrencyRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/basic/inventory/currency");
	
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UGetCurrencyRequest::BuildBody(FString& BodyString) const
{
	
}

UGetCurrencyRequest* UGetCurrencyRequest::MakeGetCurrencyRequest(UObject* Outer)
{
	UGetCurrencyRequest* Req = NewObject<UGetCurrencyRequest>(Outer);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	

	return Req;
}
