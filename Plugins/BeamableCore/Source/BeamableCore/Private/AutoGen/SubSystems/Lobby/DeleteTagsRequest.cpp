
#include "BeamableCore/Public/AutoGen/SubSystems/Lobby/DeleteTagsRequest.h"

void UDeleteTagsRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("DELETE");
}

void UDeleteTagsRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/api/lobbies/{id}/tags");
	Route = Route.Replace(TEXT("{id}"), *Id.ToString(EGuidFormats::DigitsLower));
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UDeleteTagsRequest::BuildBody(FString& BodyString) const
{
	ensureAlways(Body);

	TUnrealJsonSerializer JsonSerializer = TJsonStringWriter<TCondensedJsonPrintPolicy<wchar_t>>::Create(&BodyString);
	Body->BeamSerialize(JsonSerializer);
	JsonSerializer->Close();
}

UDeleteTagsRequest* UDeleteTagsRequest::Make(FGuid _Id, FOptionalString _PlayerId, FOptionalArrayOfString _Tags, UObject* RequestOwner)
{
	UDeleteTagsRequest* Req = NewObject<UDeleteTagsRequest>(RequestOwner);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	Req->Id = _Id;
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	Req->Body = NewObject<URemoveTags>(Req);
	Req->Body->PlayerId = _PlayerId;
	Req->Body->Tags = _Tags;
	

	return Req;
}
