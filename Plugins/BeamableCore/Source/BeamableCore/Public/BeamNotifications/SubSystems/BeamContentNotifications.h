﻿#pragma once

#include "BeamBackend/SemanticTypes/BeamContentManifestId.h"
#include "Serialization/BeamJsonSerializable.h"
#include "UserSlots/UserSlot.h"
#include "BeamContentNotifications.generated.h"


class UBeamNotifications;

USTRUCT(BlueprintType)
struct BEAMABLECORE_API FContentRefreshManifest : public FBeamJsonSerializable
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Beam")
	FBeamContentManifestId Id;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Beam")
	FString Checksum;
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Beam")
	int64 Created;	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};

USTRUCT(BlueprintType)
struct BEAMABLECORE_API FContentRefreshNotificationMessage : public FBeamJsonSerializable
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Beam")
	TArray<FString> Scopes;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Beam")
	int32 Delay;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Beam")
	FContentRefreshManifest Manifest;
	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
};

DECLARE_DELEGATE_OneParam(FOnContentRefreshNotificationCode, FContentRefreshNotificationMessage);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnContentRefreshNotification, FContentRefreshNotificationMessage, Evt);

UCLASS(BlueprintType)
class BEAMABLECORE_API UBeamContentNotifications : public UEngineSubsystem
{
	GENERATED_BODY()

	static const inline FString CTX_KEY_Content_Refresh = TEXT("content.refresh");

	UPROPERTY()
	UBeamNotifications* Notifications;

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

public:	
	UFUNCTION(BlueprintCallable, DisplayName="Subscribe - Content Refresh", Category="Beam")
	void SubscribeToContentRefresh(const FUserSlot& Slot, const FName& SocketName, const FOnContentRefreshNotification& Handler) const;

	void CPP_SubscribeToContentRefresh(const FUserSlot& Slot, const FName& SocketName, const FOnContentRefreshNotificationCode& Handler) const;
};
