
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseResponseBodyInterface.h"
#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/MatchMakingRanking.h"
#include "AutoGen/MatchMakingWindowResp.h"

#include "MatchMakingMatchesPvpResponse.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UMatchMakingMatchesPvpResponse : public UObject, public FBeamJsonSerializable, public IBeamBaseResponseBodyInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Result", Category="Beam")
	FString Result;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Total Entries", Category="Beam")
	int32 TotalEntries;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Player Rank", Category="Beam")
	UMatchMakingRanking* PlayerRank;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Windows", Category="Beam")
	TArray<UMatchMakingWindowResp*> Windows;

	virtual void DeserializeRequestResponse(UObject* RequestData, FString ResponseContent) override;

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};