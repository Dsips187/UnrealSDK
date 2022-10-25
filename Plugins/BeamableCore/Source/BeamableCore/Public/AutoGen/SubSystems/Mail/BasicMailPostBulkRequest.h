
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"

#include "AutoGen/BulkSendMailRequestBody.h"
#include "AutoGen/MailSuccessResponse.h"

#include "BasicMailPostBulkRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UBasicMailPostBulkRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	

	// Body Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="", Category="Beam")
	UBulkSendMailRequestBody* Body;

	// Beam Base Request Declaration
	UBasicMailPostBulkRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Mail", DisplayName="Beam - Make BasicMailPostBulk",  meta=(DefaultToSelf="Outer", AdvancedDisplay="Outer"))
	static UBasicMailPostBulkRequest* Make(TArray<USendMailRequestBody*> _SendMailRequests, UObject* Outer);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnBasicMailPostBulkSuccess, FBeamRequestContext, Context, UBasicMailPostBulkRequest*, Request, UMailSuccessResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnBasicMailPostBulkError, FBeamRequestContext, Context, UBasicMailPostBulkRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnBasicMailPostBulkComplete, FBeamRequestContext, Context, UBasicMailPostBulkRequest*, Request);

using FBasicMailPostBulkFullResponse = FBeamFullResponse<UBasicMailPostBulkRequest*, UMailSuccessResponse*>;
DECLARE_DELEGATE_OneParam(FOnBasicMailPostBulkFullResponse, FBasicMailPostBulkFullResponse);
