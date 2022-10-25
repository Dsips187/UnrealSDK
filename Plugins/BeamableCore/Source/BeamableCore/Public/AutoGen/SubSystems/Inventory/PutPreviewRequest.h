
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"


#include "AutoGen/InventoryUpdateRequestBody.h"
#include "AutoGen/PreviewVipBonusResponse.h"

#include "PutPreviewRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UPutPreviewRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Object Id", Category="Beam")
	int64 ObjectId;
	
	// Query Params
	

	// Body Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="", Category="Beam")
	UInventoryUpdateRequestBody* Body;

	// Beam Base Request Declaration
	UPutPreviewRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Inventory", DisplayName="Beam - Make PutPreview",  meta=(DefaultToSelf="Outer", AdvancedDisplay="_bApplyVipBonus,_Transaction,_UpdateItems,_NewItems,_DeleteItems,_Currencies,_CurrencyProperties,Outer"))
	static UPutPreviewRequest* Make(int64 _ObjectId, bool _bEmpty, TArray<FString> _CurrencyContentIds, TArray<FString> _ItemContentIds, FOptionalBool _bApplyVipBonus, FOptionalString _Transaction, FOptionalArrayOfItemUpdateRequestBody _UpdateItems, FOptionalArrayOfItemCreateRequestBody _NewItems, FOptionalArrayOfItemDeleteRequestBody _DeleteItems, FOptionalMapOfInt64 _Currencies, FOptionalMapOfArrayOfCurrencyProperty _CurrencyProperties, UObject* Outer);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPutPreviewSuccess, FBeamRequestContext, Context, UPutPreviewRequest*, Request, UPreviewVipBonusResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPutPreviewError, FBeamRequestContext, Context, UPutPreviewRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnPutPreviewComplete, FBeamRequestContext, Context, UPutPreviewRequest*, Request);

using FPutPreviewFullResponse = FBeamFullResponse<UPutPreviewRequest*, UPreviewVipBonusResponse*>;
DECLARE_DELEGATE_OneParam(FOnPutPreviewFullResponse, FPutPreviewFullResponse);
