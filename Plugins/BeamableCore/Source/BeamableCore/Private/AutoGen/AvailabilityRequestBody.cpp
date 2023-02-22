
#include "AutoGen/AvailabilityRequestBody.h"
#include "Serialization/BeamJsonUtils.h"




void UAvailabilityRequestBody::BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const
{
	Serializer->WriteValue(TEXT("type"), UGroupTypeLibrary::GroupTypeToSerializationName(Type));
	UBeamJsonUtils::SerializeOptional<bool>(TEXT("subGroup"), &bSubGroup, Serializer);
	UBeamJsonUtils::SerializeOptional<FString>(TEXT("name"), &Name, Serializer);
	UBeamJsonUtils::SerializeOptional<FString>(TEXT("tag"), &Tag, Serializer);
}

void UAvailabilityRequestBody::BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const
{
	Serializer->WriteValue(TEXT("type"), UGroupTypeLibrary::GroupTypeToSerializationName(Type));
	UBeamJsonUtils::SerializeOptional<bool>(TEXT("subGroup"), &bSubGroup, Serializer);
	UBeamJsonUtils::SerializeOptional<FString>(TEXT("name"), &Name, Serializer);
	UBeamJsonUtils::SerializeOptional<FString>(TEXT("tag"), &Tag, Serializer);		
}

void UAvailabilityRequestBody::BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag)
{
	Type = UGroupTypeLibrary::SerializationNameToGroupType(Bag->GetStringField(TEXT("type")));
	UBeamJsonUtils::DeserializeOptional<bool>("subGroup", Bag, bSubGroup, OuterOwner);
	UBeamJsonUtils::DeserializeOptional<FString>("name", Bag, Name, OuterOwner);
	UBeamJsonUtils::DeserializeOptional<FString>("tag", Bag, Tag, OuterOwner);
}



