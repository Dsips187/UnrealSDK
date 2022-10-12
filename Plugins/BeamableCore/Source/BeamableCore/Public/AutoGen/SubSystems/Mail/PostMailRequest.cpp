
#include "PostMailRequest.h"

void UPostMailRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("POST");
}

void UPostMailRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/object/mail/{objectId}/");
	Route = Route.Replace(TEXT("{objectId}"), *FString::FromInt(ObjectId));
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UPostMailRequest::BuildBody(FString& BodyString) const
{
	ensureAlways(Body);

	TUnrealJsonSerializer JsonSerializer = TJsonStringWriter<TCondensedJsonPrintPolicy<wchar_t>>::Create(&BodyString);
	Body->BeamSerialize(JsonSerializer);
	JsonSerializer->Close();
}

UPostMailRequest* UPostMailRequest::MakePostMailRequest(int64 _ObjectId, FOptionalString _Body, FOptionalString _Expires, FOptionalPlayerReward _PlayerRewards, FOptionalString _Subject, FOptionalMailRewards _Rewards, FOptionalInt64 _Id, int64 _SenderGamerTag, FString _Category, FOptionalInt64 _BodyRef, FOptionalArrayOfAttachmentRequestBody _Attachments, UObject* Outer)
{
	UPostMailRequest* Req = NewObject<UPostMailRequest>(Outer);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	Req->ObjectId = _ObjectId;
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	Req->Body = NewObject<USendMailObjectRequestBody>(Req);
	Req->Body->Body = _Body;
	Req->Body->Expires = _Expires;
	Req->Body->PlayerRewards = _PlayerRewards;
	Req->Body->Subject = _Subject;
	Req->Body->Rewards = _Rewards;
	Req->Body->Id = _Id;
	Req->Body->SenderGamerTag = _SenderGamerTag;
	Req->Body->Category = _Category;
	Req->Body->BodyRef = _BodyRef;
	Req->Body->Attachments = _Attachments;
	

	return Req;
}
