
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/Price.h"
#include "AutoGen/Optionals/OptionalString.h"
#include "AutoGen/ItemCreateRequestBody.h"
#include "AutoGen/CurrencyChange.h"

#include "PlayerOfferView.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UPlayerOfferView : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Coupons", Category="Beam")
	int32 Coupons;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Price", Category="Beam")
	UPrice* Price;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Symbol", Category="Beam")
	FString Symbol;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Titles", Category="Beam")
	TArray<FString> Titles;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Obtain Items", Category="Beam")
	TArray<UItemCreateRequestBody*> ObtainItems;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Obtain Currency", Category="Beam")
	TArray<UCurrencyChange*> ObtainCurrency;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Images", Category="Beam")
	TArray<FString> Images;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Descriptions", Category="Beam")
	TArray<FString> Descriptions;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Obtain", Category="Beam")
	TArray<FString> Obtain;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Button Text", Category="Beam")
	FOptionalString ButtonText;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};