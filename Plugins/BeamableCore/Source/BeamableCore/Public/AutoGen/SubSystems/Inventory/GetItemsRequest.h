
#pragma once

#include "CoreMinimal.h"
#include "BeamCoreTypes.h"

#include "AutoGen/ItemContentResponse.h"

#include "GetItemsRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UGetItemsRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	

	// Body Params
	

	// Beam Base Request Declaration
	UGetItemsRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, meta=(DefaultToSelf="Outer", AdvancedDisplay="Outer"))
	static UGetItemsRequest* MakeGetItemsRequest(UObject* Outer);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetItemsSuccess, FBeamRequestContext, Context, UGetItemsRequest*, Request, UItemContentResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetItemsError, FBeamRequestContext, Context, UGetItemsRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnGetItemsComplete, FBeamRequestContext, Context, UGetItemsRequest*, Request);

using FGetItemsFullResponse = FBeamFullResponse<UGetItemsRequest*, UItemContentResponse*>;
DECLARE_DELEGATE_OneParam(FOnGetItemsFullResponse, FGetItemsFullResponse);
