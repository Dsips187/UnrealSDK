
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"



#include "AutoGen/GetChampionsResponse.h"

#include "GetChampionsRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UGetChampionsRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Tournament Id", Category="Beam")
	FString TournamentId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Cycles", Category="Beam")
	int32 Cycles;

	// Body Params
	

	// Beam Base Request Declaration
	UGetChampionsRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Tournaments", DisplayName="Beam - Make GetChampions",  meta=(DefaultToSelf="Outer", AdvancedDisplay="Outer"))
	static UGetChampionsRequest* Make(FString _TournamentId, int32 _Cycles, UObject* Outer);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetChampionsSuccess, FBeamRequestContext, Context, UGetChampionsRequest*, Request, UGetChampionsResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetChampionsError, FBeamRequestContext, Context, UGetChampionsRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnGetChampionsComplete, FBeamRequestContext, Context, UGetChampionsRequest*, Request);

using FGetChampionsFullResponse = FBeamFullResponse<UGetChampionsRequest*, UGetChampionsResponse*>;
DECLARE_DELEGATE_OneParam(FOnGetChampionsFullResponse, FGetChampionsFullResponse);
