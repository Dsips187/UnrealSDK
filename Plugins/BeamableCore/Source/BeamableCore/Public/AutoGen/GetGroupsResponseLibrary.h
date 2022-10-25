
#pragma once

#include "CoreMinimal.h"
#include "AutoGen/GetGroupsResponse.h"

#include "GetGroupsResponseLibrary.generated.h"


UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UGetGroupsResponseLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category="Beam|Json", DisplayName="Beam - GetGroupsResponse To JSON String")
	static FString GetGroupsResponseToJsonString(const UGetGroupsResponse* Serializable, const bool Pretty);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Make GetGroupsResponse", meta=(DefaultToSelf="Outer", AdvancedDisplay="Focus, Outer", NativeMakeFunc))
	static UGetGroupsResponse* Make(TArray<UTournamentGroupEntry*> Entries, FOptionalTournamentGroupEntry Focus, UObject* Outer);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Break GetGroupsResponse", meta=(NativeBreakFunc))
	static void Break(const UGetGroupsResponse* Serializable, TArray<UTournamentGroupEntry*>& Entries, FOptionalTournamentGroupEntry& Focus);
};