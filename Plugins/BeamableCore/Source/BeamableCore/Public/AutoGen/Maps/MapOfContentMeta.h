
#pragma once

#include "CoreMinimal.h"
#include "Serialization/BeamMap.h"
#include "AutoGen/ContentMeta.h"

#include "MapOfContentMeta.generated.h"

USTRUCT(BlueprintType, Category="Beam|Wrappers|Maps")
struct FMapOfContentMeta : public FBeamMap
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Beam")
	TMap<FString, UContentMeta*> Values;

	FMapOfContentMeta();

	FMapOfContentMeta(const TMap<FString, UContentMeta*>& Val);

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;

	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;

	virtual void BeamDeserializeElements(const TSharedPtr<FJsonObject>& Elements) override;
};