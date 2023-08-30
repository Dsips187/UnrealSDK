#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "BeamableCore/Public/AutoGen/Optionals/OptionalString.h"
#include "BeamableCore/Public/AutoGen/Optionals/OptionalBeamContentId.h"
#include "BeamableCore/Public/AutoGen/Optionals/OptionalInt32.h"

#include "UpdateLobby.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UUpdateLobby : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Name", Category="Beam")
	FOptionalString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Description", Category="Beam")
	FOptionalString Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Restriction", Category="Beam")
	FOptionalString Restriction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Match Type", Category="Beam")
	FOptionalBeamContentId MatchType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Max Players", Category="Beam")
	FOptionalInt32 MaxPlayers;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="New Host", Category="Beam")
	FOptionalString NewHost;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
	
};