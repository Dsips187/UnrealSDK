
#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"
#include "BeamableCore/Public/AutoGen/Optionals/OptionalVariableReference.h"

#include "RouteParameter.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API URouteParameter : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Name", Category="Beam")
	FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Body", Category="Beam")
	FString Body;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Type Name", Category="Beam")
	FString TypeName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Variable Ref", Category="Beam")
	FOptionalVariableReference VariableRef;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
	
};