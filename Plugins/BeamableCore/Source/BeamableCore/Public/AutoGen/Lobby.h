#pragma once

#include "CoreMinimal.h"
#include "BeamBackend/BeamBaseResponseBodyInterface.h"
#include "Serialization/BeamJsonSerializable.h"
#include "BeamableCore/Public/AutoGen/Optionals/OptionalString.h"
#include "BeamableCore/Public/AutoGen/Optionals/OptionalMatchType.h"
#include "BeamableCore/Public/AutoGen/Optionals/OptionalArrayOfLobbyPlayer.h"
#include "BeamableCore/Public/AutoGen/Optionals/OptionalInt32.h"

#include "Lobby.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API ULobby : public UObject, public FBeamJsonSerializable, public IBeamBaseResponseBodyInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Lobby Id", Category="Beam")
	FOptionalString LobbyId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Match Type", Category="Beam")
	FOptionalMatchType MatchType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Created", Category="Beam")
	FOptionalString Created;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Name", Category="Beam")
	FOptionalString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Description", Category="Beam")
	FOptionalString Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Host", Category="Beam")
	FOptionalString Host;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Passcode", Category="Beam")
	FOptionalString Passcode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Restriction", Category="Beam")
	FOptionalString Restriction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Max Players", Category="Beam")
	FOptionalInt32 MaxPlayers;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Players", Category="Beam")
	FOptionalArrayOfLobbyPlayer Players;

	virtual void DeserializeRequestResponse(UObject* RequestData, FString ResponseContent) override;

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
	
};