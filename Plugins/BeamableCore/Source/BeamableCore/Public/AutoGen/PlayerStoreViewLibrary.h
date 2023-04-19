
#pragma once

#include "CoreMinimal.h"
#include "BeamableCore/Public/AutoGen/PlayerStoreView.h"

#include "PlayerStoreViewLibrary.generated.h"


UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UPlayerStoreViewLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category="Beam|Json", DisplayName="Beam - PlayerStoreView To JSON String")
	static FString PlayerStoreViewToJsonString(const UPlayerStoreView* Serializable, const bool Pretty);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Make PlayerStoreView", meta=(DefaultToSelf="Outer", AdvancedDisplay="NextDeltaSeconds, Title, SecondsRemain, Outer", NativeMakeFunc))
	static UPlayerStoreView* Make(FString Symbol, TArray<UPlayerListingView*> Listings, FOptionalInt64 NextDeltaSeconds, FOptionalString Title, FOptionalInt64 SecondsRemain, UObject* Outer);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Break PlayerStoreView", meta=(NativeBreakFunc))
	static void Break(const UPlayerStoreView* Serializable, FString& Symbol, TArray<UPlayerListingView*>& Listings, FOptionalInt64& NextDeltaSeconds, FOptionalString& Title, FOptionalInt64& SecondsRemain);
};