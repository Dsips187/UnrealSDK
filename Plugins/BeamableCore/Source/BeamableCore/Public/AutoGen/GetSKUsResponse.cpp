
#include "AutoGen/GetSKUsResponse.h"
#include "Serialization/BeamJsonUtils.h"


void UGetSKUsResponse ::BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const
{
	UBeamJsonUtils::SerializeUObject<USKUDefinitions*>("skus", Skus, Serializer);
}

void UGetSKUsResponse::BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const
{
	UBeamJsonUtils::SerializeUObject<USKUDefinitions*>("skus", Skus, Serializer);		
}

void UGetSKUsResponse ::BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag)
{
	UBeamJsonUtils::DeserializeUObject<USKUDefinitions*>("skus", Bag, Skus, OuterOwner);
}