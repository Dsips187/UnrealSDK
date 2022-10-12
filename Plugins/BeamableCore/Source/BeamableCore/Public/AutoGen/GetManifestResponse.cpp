
#include "AutoGen/GetManifestResponse.h"
#include "Serialization/BeamJsonUtils.h"


void UGetManifestResponse ::BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const
{
	UBeamJsonUtils::SerializeUObject<UManifestView*>("manifest", Manifest, Serializer);
}

void UGetManifestResponse::BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const
{
	UBeamJsonUtils::SerializeUObject<UManifestView*>("manifest", Manifest, Serializer);		
}

void UGetManifestResponse ::BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag)
{
	UBeamJsonUtils::DeserializeUObject<UManifestView*>("manifest", Bag, Manifest, OuterOwner);
}