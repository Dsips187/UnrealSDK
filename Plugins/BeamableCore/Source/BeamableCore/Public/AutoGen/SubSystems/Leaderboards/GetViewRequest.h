
#pragma once

#include "CoreMinimal.h"
#include "BeamCoreTypes.h"


#include "AutoGen/Optionals/OptionalInt32.h"
#include "AutoGen/Optionals/OptionalInt64.h"
#include "AutoGen/Optionals/OptionalBool.h"
#include "AutoGen/LeaderBoardViewResponse.h"

#include "GetViewRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UGetViewRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Object Id")
	FString ObjectId;
	
	// Query Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Max")
	FOptionalInt32 Max;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Focus")
	FOptionalInt64 Focus;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="B Friends")
	FOptionalBool bFriends;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="From")
	FOptionalInt32 From;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Outlier")
	FOptionalInt64 Outlier;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="B Guild")
	FOptionalBool bGuild;

	// Body Params
	

	// Beam Base Request Declaration
	UGetViewRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, meta=(DefaultToSelf="Outer", AdvancedDisplay="_Max,_Focus,_bFriends,_From,_Outlier,_bGuild,Outer"))
	static UGetViewRequest* MakeGetViewRequest(FString _ObjectId, FOptionalInt32 _Max, FOptionalInt64 _Focus, FOptionalBool _bFriends, FOptionalInt32 _From, FOptionalInt64 _Outlier, FOptionalBool _bGuild, UObject* Outer);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetViewSuccess, FBeamRequestContext, Context, UGetViewRequest*, Request, ULeaderBoardViewResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetViewError, FBeamRequestContext, Context, UGetViewRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnGetViewComplete, FBeamRequestContext, Context, UGetViewRequest*, Request);

using FGetViewFullResponse = FBeamFullResponse<UGetViewRequest*, ULeaderBoardViewResponse*>;
DECLARE_DELEGATE_OneParam(FOnGetViewFullResponse, FGetViewFullResponse);
