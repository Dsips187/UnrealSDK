
#include "AutoGen/GetActiveOffersResponse.h"
#include "Serialization/BeamJsonUtils.h"


void UGetActiveOffersResponse ::BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const
{
	UBeamJsonUtils::SerializeArray<UPlayerStoreView*>(TEXT("stores"), Stores, Serializer);
}

void UGetActiveOffersResponse::BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const
{
	UBeamJsonUtils::SerializeArray<UPlayerStoreView*>(TEXT("stores"), Stores, Serializer);		
}

void UGetActiveOffersResponse ::BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag)
{
	UBeamJsonUtils::DeserializeArray<UPlayerStoreView*>(Bag->GetArrayField(TEXT("stores")), Stores, OuterOwner);
}