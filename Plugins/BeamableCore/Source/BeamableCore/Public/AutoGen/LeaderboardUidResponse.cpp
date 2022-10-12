
#include "AutoGen/LeaderboardUidResponse.h"

#include "Misc/DefaultValueHelper.h"

void ULeaderboardUidResponse ::BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const
{
	Serializer->WriteValue(TEXT("id"), Id);
}

void ULeaderboardUidResponse::BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const
{
	Serializer->WriteValue(TEXT("id"), Id);		
}

void ULeaderboardUidResponse ::BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag)
{
	FDefaultValueHelper::ParseInt64(Bag->GetStringField(TEXT("id")), Id);
}