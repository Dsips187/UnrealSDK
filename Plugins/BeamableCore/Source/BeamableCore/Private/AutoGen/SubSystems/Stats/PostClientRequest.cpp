
#include "BeamableCore/Public/AutoGen/SubSystems/Stats/PostClientRequest.h"

void UPostClientRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("POST");
}

void UPostClientRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/object/stats/{objectId}/client");
	Route = Route.Replace(TEXT("{objectId}"), *static_cast<FString>(ObjectId));
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UPostClientRequest::BuildBody(FString& BodyString) const
{
	ensureAlways(Body);

	TUnrealJsonSerializer JsonSerializer = TJsonStringWriter<TCondensedJsonPrintPolicy<wchar_t>>::Create(&BodyString);
	Body->BeamSerialize(JsonSerializer);
	JsonSerializer->Close();
}

UPostClientRequest* UPostClientRequest::Make(FBeamStatsType _ObjectId, FOptionalBool _bEmitAnalytics, FOptionalBeamStatsType Body_ObjectId, FOptionalMapOfString _Set, FOptionalMapOfString _Add, UObject* RequestOwner)
{
	UPostClientRequest* Req = NewObject<UPostClientRequest>(RequestOwner);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	Req->ObjectId = _ObjectId;
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	Req->Body = NewObject<UStatUpdateRequestBody>(Req);
	Req->Body->bEmitAnalytics = _bEmitAnalytics;
	Req->Body->ObjectId = Body_ObjectId;
	Req->Body->Set = _Set;
	Req->Body->Add = _Add;
	

	return Req;
}
