
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"

#include "BeamBackend/SemanticTypes/BeamAccountId.h"
#include "BeamableCore/Public/AutoGen/UpdateRole.h"
#include "BeamableCore/Public/AutoGen/EmptyResponse.h"

#include "ObjectAccountsPutRoleRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UObjectAccountsPutRoleRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Object Id", Category="Beam")
	FBeamAccountId ObjectId;
	
	// Query Params
	

	// Body Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="", Category="Beam")
	UUpdateRole* Body;

	// Beam Base Request Declaration
	UObjectAccountsPutRoleRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Accounts", DisplayName="Beam - Make ObjectAccountsPutRole",  meta=(DefaultToSelf="RequestOwner", AdvancedDisplay="_Cid,_Realm,_Role,RequestOwner"))
	static UObjectAccountsPutRoleRequest* Make(FBeamAccountId _ObjectId, FOptionalBeamCid _Cid, FOptionalBeamPid _Realm, FOptionalString _Role, UObject* RequestOwner);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnObjectAccountsPutRoleSuccess, FBeamRequestContext, Context, UObjectAccountsPutRoleRequest*, Request, UEmptyResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnObjectAccountsPutRoleError, FBeamRequestContext, Context, UObjectAccountsPutRoleRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnObjectAccountsPutRoleComplete, FBeamRequestContext, Context, UObjectAccountsPutRoleRequest*, Request);

using FObjectAccountsPutRoleFullResponse = FBeamFullResponse<UObjectAccountsPutRoleRequest*, UEmptyResponse*>;
DECLARE_DELEGATE_OneParam(FOnObjectAccountsPutRoleFullResponse, FObjectAccountsPutRoleFullResponse);
