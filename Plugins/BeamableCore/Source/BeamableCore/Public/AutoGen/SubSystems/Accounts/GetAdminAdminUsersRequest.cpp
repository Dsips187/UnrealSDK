
#include "GetAdminAdminUsersRequest.h"

void UGetAdminAdminUsersRequest::BuildVerb(FString& VerbString) const
{
	VerbString = TEXT("GET");
}

void UGetAdminAdminUsersRequest::BuildRoute(FString& RouteString) const
{
	FString Route = TEXT("/basic/accounts/admin/admin-users");
	
	
	FString QueryParams = TEXT("");
	QueryParams.Reserve(1024);
	bool bIsFirstQueryParam = true;
	
	RouteString.Appendf(TEXT("%s%s"), *Route, *QueryParams);		
}

void UGetAdminAdminUsersRequest::BuildBody(FString& BodyString) const
{
	
}

UGetAdminAdminUsersRequest* UGetAdminAdminUsersRequest::MakeGetAdminAdminUsersRequest(UObject* Outer)
{
	UGetAdminAdminUsersRequest* Req = NewObject<UGetAdminAdminUsersRequest>(Outer);

	// Pass in Path and Query Parameters (Blank if no path parameters exist)
	
	
	// Makes a body and fill up with parameters (Blank if no body parameters exist)
	

	return Req;
}
