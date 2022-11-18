
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"

#include "AutoGen/ObjectRequests.h"
#include "AutoGen/URLSResponse.h"

#include "PostDataDownloadURLFromPortalRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UPostDataDownloadURLFromPortalRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	

	// Body Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="", Category="Beam")
	UObjectRequests* Body;

	// Beam Base Request Declaration
	UPostDataDownloadURLFromPortalRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Cloudsaving", DisplayName="Beam - Make PostDataDownloadURLFromPortal",  meta=(DefaultToSelf="RequestOwner", AdvancedDisplay="_PlayerId,_Request,RequestOwner"))
	static UPostDataDownloadURLFromPortalRequest* Make(FOptionalInt64 _PlayerId, FOptionalArrayOfObjectRequestBody _Request, UObject* RequestOwner);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostDataDownloadURLFromPortalSuccess, FBeamRequestContext, Context, UPostDataDownloadURLFromPortalRequest*, Request, UURLSResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPostDataDownloadURLFromPortalError, FBeamRequestContext, Context, UPostDataDownloadURLFromPortalRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnPostDataDownloadURLFromPortalComplete, FBeamRequestContext, Context, UPostDataDownloadURLFromPortalRequest*, Request);

using FPostDataDownloadURLFromPortalFullResponse = FBeamFullResponse<UPostDataDownloadURLFromPortalRequest*, UURLSResponse*>;
DECLARE_DELEGATE_OneParam(FOnPostDataDownloadURLFromPortalFullResponse, FPostDataDownloadURLFromPortalFullResponse);
