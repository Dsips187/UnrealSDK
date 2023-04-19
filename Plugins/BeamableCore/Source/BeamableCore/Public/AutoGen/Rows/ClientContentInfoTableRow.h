
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "BeamableCore/Public/AutoGen/Enums/ContentType.h"





#include "ClientContentInfoTableRow.generated.h"

USTRUCT(BlueprintType)
struct FClientContentInfoTableRow : public FTableRowBase
{
	GENERATED_BODY()

	const static FString KeyField;
	const static TArray<FString> HeaderFields;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Type", Category="Beam")
	EContentType Type;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="ContentId", Category="Beam")
	FString ContentId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Version", Category="Beam")
	FString Version;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Uri", Category="Beam")
	FString Uri;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Tags", Category="Beam")
	TArray<FString> Tags;		
};