﻿#pragma once

#include "Serialization/BeamJsonSerializable.h"
#include "UserSlots/UserSlot.h"
#include "BeamInventoryNotifications.generated.h"

class UBeamNotifications;

USTRUCT(BlueprintType)
struct BEAMABLECORE_API FInventoryRefreshNotificationMessage : public FBeamJsonSerializableUStruct
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Beam")
	TArray<FString> Scopes;

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};

DECLARE_DELEGATE_OneParam(FOnInventoryRefreshNotificationCode, FInventoryRefreshNotificationMessage);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnInventoryRefreshNotification, FInventoryRefreshNotificationMessage, Evt);

UCLASS(BlueprintType)
class BEAMABLECORE_API UBeamInventoryNotifications : public UEngineSubsystem
{
	GENERATED_BODY()

	static const inline FString CTX_KEY_Inventory_Refresh = TEXT("inventory.refresh");

	UPROPERTY()
	UBeamNotifications* Notifications;

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

public:
	UFUNCTION(BlueprintCallable, DisplayName="Subscribe - Inventory Refresh", Category="Beam")
	void SubscribeToInventoryRefresh(const FUserSlot& Slot, const FName& SocketName, const FOnInventoryRefreshNotification& Handler) const;

	FDelegateHandle CPP_SubscribeToInventoryRefresh(const FUserSlot& Slot, const FName& SocketName, const FOnInventoryRefreshNotificationCode& Handler) const;
};
