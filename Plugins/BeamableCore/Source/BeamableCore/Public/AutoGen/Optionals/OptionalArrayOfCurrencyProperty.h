
#pragma once

#include "CoreMinimal.h"
#include "Serialization/BeamOptional.h"
#include "AutoGen/CurrencyProperty.h"

#include "OptionalArrayOfCurrencyProperty.generated.h"

// Has Native Make/Break require static blueprint pure functions to present as nodes that
// don't require an execution pin connection. This is super relevant for Blueprint UX. 
USTRUCT(BlueprintType, meta=(HasNativeMake="BeamableCore.OptionalArrayOfCurrencyPropertyLibrary.MakeOptionalArrayOfCurrencyProperty"))
struct FOptionalArrayOfCurrencyProperty : public FBeamOptional
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	TArray<UCurrencyProperty*> Val;

	FOptionalArrayOfCurrencyProperty();

	explicit FOptionalArrayOfCurrencyProperty(TArray<UCurrencyProperty*> Val);

	virtual const void* GetAddr() const override;

	virtual void Set(const void* Data) override;
};