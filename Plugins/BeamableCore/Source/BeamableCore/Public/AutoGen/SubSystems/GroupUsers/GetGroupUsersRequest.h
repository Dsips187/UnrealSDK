
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"


#include "AutoGen/GroupUser.h"

#include "GetGroupUsersRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UGetGroupUsersRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Object Id", Category="Beam")
	int64 ObjectId;
	
	// Query Params
	

	// Body Params
	

	// Beam Base Request Declaration
	UGetGroupUsersRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|GroupUsers", DisplayName="Beam - Make GetGroupUsers",  meta=(DefaultToSelf="Outer", AdvancedDisplay="Outer"))
	static UGetGroupUsersRequest* Make(int64 _ObjectId, UObject* Outer);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetGroupUsersSuccess, FBeamRequestContext, Context, UGetGroupUsersRequest*, Request, UGroupUser*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetGroupUsersError, FBeamRequestContext, Context, UGetGroupUsersRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnGetGroupUsersComplete, FBeamRequestContext, Context, UGetGroupUsersRequest*, Request);

using FGetGroupUsersFullResponse = FBeamFullResponse<UGetGroupUsersRequest*, UGroupUser*>;
DECLARE_DELEGATE_OneParam(FOnGetGroupUsersFullResponse, FGetGroupUsersFullResponse);
