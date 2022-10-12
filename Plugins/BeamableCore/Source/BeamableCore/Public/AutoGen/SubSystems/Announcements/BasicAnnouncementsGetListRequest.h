
#pragma once

#include "CoreMinimal.h"
#include "BeamCoreTypes.h"

#include "AutoGen/AnnouncementContentResponse.h"

#include "BasicAnnouncementsGetListRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UBasicAnnouncementsGetListRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	

	// Body Params
	

	// Beam Base Request Declaration
	UBasicAnnouncementsGetListRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, meta=(DefaultToSelf="Outer", AdvancedDisplay="Outer"))
	static UBasicAnnouncementsGetListRequest* MakeBasicAnnouncementsGetListRequest(UObject* Outer);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnBasicAnnouncementsGetListSuccess, FBeamRequestContext, Context, UBasicAnnouncementsGetListRequest*, Request, UAnnouncementContentResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnBasicAnnouncementsGetListError, FBeamRequestContext, Context, UBasicAnnouncementsGetListRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnBasicAnnouncementsGetListComplete, FBeamRequestContext, Context, UBasicAnnouncementsGetListRequest*, Request);

using FBasicAnnouncementsGetListFullResponse = FBeamFullResponse<UBasicAnnouncementsGetListRequest*, UAnnouncementContentResponse*>;
DECLARE_DELEGATE_OneParam(FOnBasicAnnouncementsGetListFullResponse, FBasicAnnouncementsGetListFullResponse);
