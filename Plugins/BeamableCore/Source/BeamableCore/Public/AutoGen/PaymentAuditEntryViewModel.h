
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "AutoGen/PaymentHistoryEntryViewModel.h"
#include "AutoGen/Optionals/OptionalString.h"
#include "AutoGen/Optionals/OptionalArrayOfItemCreateRequestBody.h"
#include "AutoGen/Optionals/OptionalInt64.h"
#include "AutoGen/Optionals/OptionalArrayOfCurrencyChange.h"
#include "AutoGen/EntitlementGenerator.h"
#include "AutoGen/PaymentDetailsEntryViewModel.h"

#include "PaymentAuditEntryViewModel.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UPaymentAuditEntryViewModel : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Providerid", Category="Beam")
	FString Providerid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Txid", Category="Beam")
	int64 Txid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Providername", Category="Beam")
	FString Providername;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Txstate", Category="Beam")
	FString Txstate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Details", Category="Beam")
	UPaymentDetailsEntryViewModel* Details;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Gt", Category="Beam")
	int64 Gt;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="History", Category="Beam")
	TArray<UPaymentHistoryEntryViewModel*> History;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Entitlements", Category="Beam")
	TArray<UEntitlementGenerator*> Entitlements;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Version", Category="Beam")
	FOptionalString Version;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Updated", Category="Beam")
	FOptionalInt64 Updated;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Replay Guard Value", Category="Beam")
	FOptionalString ReplayGuardValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Created", Category="Beam")
	FOptionalInt64 Created;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Obtain Items", Category="Beam")
	FOptionalArrayOfItemCreateRequestBody ObtainItems;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Obtain Currency", Category="Beam")
	FOptionalArrayOfCurrencyChange ObtainCurrency;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};