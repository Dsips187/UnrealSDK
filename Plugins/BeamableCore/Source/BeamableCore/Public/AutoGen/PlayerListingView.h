
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/ClientDataEntry.h"
#include "AutoGen/Optionals/OptionalInt32.h"
#include "AutoGen/PlayerOfferView.h"
#include "AutoGen/Optionals/OptionalInt64.h"

#include "PlayerListingView.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UPlayerListingView : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="B Active", Category="Beam")
	bool bActive;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="B Query After Purchase", Category="Beam")
	bool bQueryAfterPurchase;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Symbol", Category="Beam")
	FString Symbol;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Seconds Active", Category="Beam")
	int64 SecondsActive;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Offer", Category="Beam")
	UPlayerOfferView* Offer;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Client Data List", Category="Beam")
	TArray<UClientDataEntry*> ClientDataList;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Client Data", Category="Beam")
	TMap<FString, FString> ClientData;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Cooldown", Category="Beam")
	FOptionalInt32 Cooldown;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Purchases Remain", Category="Beam")
	FOptionalInt32 PurchasesRemain;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Seconds Remain", Category="Beam")
	FOptionalInt64 SecondsRemain;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};