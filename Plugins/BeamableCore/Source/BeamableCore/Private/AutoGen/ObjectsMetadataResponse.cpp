
#include "AutoGen/ObjectsMetadataResponse.h"
#include "Serialization/BeamJsonUtils.h"



void UObjectsMetadataResponse::DeserializeRequestResponse(UObject* RequestData, FString ResponseContent)
{
	OuterOwner = RequestData;
	BeamDeserialize(ResponseContent);	
}

void UObjectsMetadataResponse::BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const
{
	UBeamJsonUtils::SerializeArray<UObjectMetadataResponse*>(TEXT("response"), Response, Serializer);
}

void UObjectsMetadataResponse::BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const
{
	UBeamJsonUtils::SerializeArray<UObjectMetadataResponse*>(TEXT("response"), Response, Serializer);		
}

void UObjectsMetadataResponse::BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag)
{
	UBeamJsonUtils::DeserializeArray<UObjectMetadataResponse*>(Bag->GetArrayField(TEXT("response")), Response, OuterOwner);
}



