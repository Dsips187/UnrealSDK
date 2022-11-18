
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseRequestInterface.h"
#include "BeamBackend/BeamRequestContext.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "BeamBackend/BeamFullResponse.h"


#include "AutoGen/Optionals/OptionalInt32.h"
#include "AutoGen/Optionals/OptionalInt64.h"
#include "AutoGen/GetStandingsResponse.h"

#include "GetGlobalRequest.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UGetGlobalRequest : public UObject, public IBeamBaseRequestInterface
{
	GENERATED_BODY()
	
public:

	// Path Params
	
	
	// Query Params
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Tournament Id", Category="Beam")
	FString TournamentId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Max", Category="Beam")
	FOptionalInt32 Max;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Focus", Category="Beam")
	FOptionalInt64 Focus;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Cycle", Category="Beam")
	FOptionalInt32 Cycle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="From", Category="Beam")
	FOptionalInt32 From;

	// Body Params
	

	// Beam Base Request Declaration
	UGetGlobalRequest() = default;

	virtual void BuildVerb(FString& VerbString) const override;
	virtual void BuildRoute(FString& RouteString) const override;
	virtual void BuildBody(FString& BodyString) const override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category="Beam|Backend|Tournaments", DisplayName="Beam - Make GetGlobal",  meta=(DefaultToSelf="RequestOwner", AdvancedDisplay="_Max,_Focus,_Cycle,_From,RequestOwner"))
	static UGetGlobalRequest* Make(FString _TournamentId, FOptionalInt32 _Max, FOptionalInt64 _Focus, FOptionalInt32 _Cycle, FOptionalInt32 _From, UObject* RequestOwner);
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetGlobalSuccess, FBeamRequestContext, Context, UGetGlobalRequest*, Request, UGetStandingsResponse*, Response);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGetGlobalError, FBeamRequestContext, Context, UGetGlobalRequest*, Request, FBeamErrorResponse, Error);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnGetGlobalComplete, FBeamRequestContext, Context, UGetGlobalRequest*, Request);

using FGetGlobalFullResponse = FBeamFullResponse<UGetGlobalRequest*, UGetStandingsResponse*>;
DECLARE_DELEGATE_OneParam(FOnGetGlobalFullResponse, FGetGlobalFullResponse);
