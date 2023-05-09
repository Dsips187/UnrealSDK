#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"


#include "RealmRolesReport.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API URealmRolesReport : public UObject, public FBeamJsonSerializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Realm Name", Category="Beam")
	FString RealmName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Realm Display Name", Category="Beam")
	FString RealmDisplayName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="Roles", Category="Beam")
	TArray<FString> Roles;

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
	
};