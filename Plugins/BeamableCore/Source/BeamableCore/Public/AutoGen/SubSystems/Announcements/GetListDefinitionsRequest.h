
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"

#include "AutoGen/ListDefinitionsResponse.h"

#include "GetListDefinitionsRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UGetListDefinitionsRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	

	// Body Params
	

	// Beam Base Request Declaration
	UGetListDefinitionsRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Announcements", DisplayName="Beam - Make GetListDefinitions",  meta=(DefaultToSelf="Outer", AdvancedDisplay="Outer"))
	static UGetListDefinitionsRequest* Make(UObject* Outer);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetListDefinitionsSuccess, FBeamRequestContext, Context, UGetListDefinitionsRequest*, Request, UListDefinitionsResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetListDefinitionsError, FBeamRequestContext, Context, UGetListDefinitionsRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnGetListDefinitionsComplete, FBeamRequestContext, Context, UGetListDefinitionsRequest*, Request);

using FGetListDefinitionsFullResponse = FBeamFullResponse<UGetListDefinitionsRequest*, UListDefinitionsResponse*>;
DECLARE_DELEGATE_OneParam(FOnGetListDefinitionsFullResponse, FGetListDefinitionsFullResponse);
