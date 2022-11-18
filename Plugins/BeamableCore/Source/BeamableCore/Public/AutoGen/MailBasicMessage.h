
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/Optionals/OptionalString.h"
#include "AutoGen/Optionals/OptionalInt32.h"
#include "AutoGen/Optionals/OptionalPlayerReward.h"
#include "AutoGen/Optionals/OptionalMailRewards.h"
#include "AutoGen/Optionals/OptionalInt64.h"
#include "AutoGen/Attachment.h"

#include "MailBasicMessage.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UMailBasicMessage : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Receiver Gamer Tag", Category="Beam")
	int64 ReceiverGamerTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="State", Category="Beam")
	FString State;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Id", Category="Beam")
	int64 Id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Sender Gamer Tag", Category="Beam")
	int64 SenderGamerTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Sent", Category="Beam")
	int64 Sent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Category", Category="Beam")
	FString Category;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Attachments", Category="Beam")
	TArray<UAttachment*> Attachments;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Body", Category="Beam")
	FOptionalString Body;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Expires", Category="Beam")
	FOptionalInt32 Expires;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Player Rewards", Category="Beam")
	FOptionalPlayerReward PlayerRewards;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Subject", Category="Beam")
	FOptionalString Subject;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Rewards", Category="Beam")
	FOptionalMailRewards Rewards;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Body Ref", Category="Beam")
	FOptionalInt64 BodyRef;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Claimed Time Ms", Category="Beam")
	FOptionalInt64 ClaimedTimeMs;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};