
#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseResponseBodyInterface.h"
#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/TournamentEntry.h"
#include "AutoGen/Optionals/OptionalTournamentEntry.h"

#include "GetStandingsResponse.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UGetStandingsResponse : public UObject, public FBeamJsonSerializable, public IBeamBaseResponseBodyInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Entries", Category="Beam")
	TArray<UTournamentEntry*> Entries;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Me", Category="Beam")
	FOptionalTournamentEntry Me;

	virtual void DeserializeRequestResponse(UObject* RequestData, FString ResponseContent) override;

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};