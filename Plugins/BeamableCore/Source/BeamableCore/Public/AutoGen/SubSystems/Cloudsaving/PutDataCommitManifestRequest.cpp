
#include "PutDataCommitManifestRequest.h"

void UPutDataCommitManifestRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("PUT");
}

void UPutDataCommitManifestRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/basic/cloudsaving/data/commitManifest");
	
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UPutDataCommitManifestRequest::BuildBody(FString& BodyString) const
{
	ensureAlways(Body);

	TUnrealJsonSerializer JsonSerializer = TJsonStringWriter<TCondensedJsonPrintPolicy<wchar_t>>::Create(&BodyString);
	Body->BeamSerialize(JsonSerializer);
	JsonSerializer->Close();
}

UPutDataCommitManifestRequest* UPutDataCommitManifestRequest::MakePutDataCommitManifestRequest(TArray<UUploadRequestBody*> _Request, FOptionalInt64 _PlayerId, UObject* Outer)
{
	UPutDataCommitManifestRequest* Req = NewObject<UPutDataCommitManifestRequest>(Outer);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	Req->Body = NewObject<UUploadRequests>(Req);
	Req->Body->Request = _Request;
	Req->Body->PlayerId = _PlayerId;
	

	return Req;
}
