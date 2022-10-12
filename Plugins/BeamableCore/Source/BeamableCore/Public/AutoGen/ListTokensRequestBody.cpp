
#include "AutoGen/ListTokensRequestBody.h"
#include "Serialization/BeamJsonUtils.h"
#include "Misc/DefaultValueHelper.h"

void UListTokensRequestBody ::BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const
{
	Serializer->WriteValue(TEXT("pageSize"), PageSize);
	Serializer->WriteValue(TEXT("page"), Page);
	UBeamJsonUtils::SerializeOptional<int64>(TEXT("cid"), &Cid, Serializer);
	UBeamJsonUtils::SerializeOptional<FString>(TEXT("pid"), &Pid, Serializer);
	Serializer->WriteValue(TEXT("gamerTagOrAccountId"), GamerTagOrAccountId);
}

void UListTokensRequestBody::BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const
{
	Serializer->WriteValue(TEXT("pageSize"), PageSize);
	Serializer->WriteValue(TEXT("page"), Page);
	UBeamJsonUtils::SerializeOptional<int64>(TEXT("cid"), &Cid, Serializer);
	UBeamJsonUtils::SerializeOptional<FString>(TEXT("pid"), &Pid, Serializer);
	Serializer->WriteValue(TEXT("gamerTagOrAccountId"), GamerTagOrAccountId);		
}

void UListTokensRequestBody ::BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag)
{
	PageSize = Bag->GetIntegerField(TEXT("pageSize"));
	Page = Bag->GetIntegerField(TEXT("page"));
	UBeamJsonUtils::DeserializeOptional<int64>("cid", Bag, Cid, OuterOwner);
	UBeamJsonUtils::DeserializeOptional<FString>("pid", Bag, Pid, OuterOwner);
	FDefaultValueHelper::ParseInt64(Bag->GetStringField(TEXT("gamerTagOrAccountId")), GamerTagOrAccountId);
}