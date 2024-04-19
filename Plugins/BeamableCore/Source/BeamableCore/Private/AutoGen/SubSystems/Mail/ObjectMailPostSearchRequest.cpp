
#include "BeamableCore/Public/AutoGen/SubSystems/Mail/ObjectMailPostSearchRequest.h"

void UObjectMailPostSearchRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("POST");
}

void UObjectMailPostSearchRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/object/mail/{objectId}/search");
	Route = Route.Replace(TEXT("{objectId}"), *FString::Printf(TEXT("%lld"), ObjectId));
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UObjectMailPostSearchRequest::BuildBody(FString& BodyString) const
{
	ensureAlways(Body);

	TUnrealJsonSerializer JsonSerializer = TJsonStringWriter<TCondensedJsonPrintPolicy<TCHAR>>::Create(&BodyString);
	Body->BeamSerialize(JsonSerializer);
	JsonSerializer->Close();
}

UObjectMailPostSearchRequest* UObjectMailPostSearchRequest::Make(int64 _ObjectId, TArray<UMailSearchClause*> _Clauses, UObject* RequestOwner, TMap<FString, FString> CustomHeaders)
{
	UObjectMailPostSearchRequest* Req = NewObject<UObjectMailPostSearchRequest>(RequestOwner);
	Req->CustomHeaders = TMap{CustomHeaders};

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	Req->ObjectId = _ObjectId;
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	Req->Body = NewObject<UMailSearchRequestBody>(Req);
	Req->Body->Clauses = _Clauses;
	

	return Req;
}
