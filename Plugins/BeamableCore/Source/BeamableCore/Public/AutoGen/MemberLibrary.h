
#pragma once

#include "CoreMinimal.h"
#include "BeamableCore/Public/AutoGen/Member.h"

#include "MemberLibrary.generated.h"


UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UMemberLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category="Beam|Json", DisplayName="Beam - Member To JSON String")
	static FString MemberToJsonString(const UMember* Serializable, const bool Pretty);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Make Member", meta=(DefaultToSelf="Outer", AdvancedDisplay="bCanDemote, bCanKick, bCanPromote, Scores, Outer", NativeMakeFunc))
	static UMember* Make(FString Role, int64 GamerTag, FOptionalBool bCanDemote, FOptionalBool bCanKick, FOptionalBool bCanPromote, FOptionalArrayOfGroupScoreBinding Scores, UObject* Outer);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Break Member", meta=(NativeBreakFunc))
	static void Break(const UMember* Serializable, FString& Role, int64& GamerTag, FOptionalBool& bCanDemote, FOptionalBool& bCanKick, FOptionalBool& bCanPromote, FOptionalArrayOfGroupScoreBinding& Scores);
};