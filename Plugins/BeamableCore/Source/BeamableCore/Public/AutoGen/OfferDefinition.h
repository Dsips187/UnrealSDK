
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/Optionals/OptionalArrayOfItemCreateRequestBody.h"
#include "AutoGen/Optionals/OptionalCommerceLootRoll.h"
#include "AutoGen/Optionals/OptionalArrayOfCurrencyChange.h"
#include "AutoGen/Optionals/OptionalString.h"

#include "OfferDefinition.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UOfferDefinition : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Symbol", Category="Beam")
	FString Symbol;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Titles", Category="Beam")
	TArray<FString> Titles;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Images", Category="Beam")
	TArray<FString> Images;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Descriptions", Category="Beam")
	TArray<FString> Descriptions;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Obtain", Category="Beam")
	TArray<FString> Obtain;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Loot Roll", Category="Beam")
	FOptionalCommerceLootRoll LootRoll;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Metadata", Category="Beam")
	FOptionalString Metadata;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Obtain Items", Category="Beam")
	FOptionalArrayOfItemCreateRequestBody ObtainItems;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Obtain Currency", Category="Beam")
	FOptionalArrayOfCurrencyChange ObtainCurrency;

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};