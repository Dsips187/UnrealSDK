
#include "AutoGen/GetTotalCouponResponse.h"

#include "Misc/DefaultValueHelper.h"

void UGetTotalCouponResponse ::BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const
{
	Serializer->WriteValue(TEXT("count"), Count);
}

void UGetTotalCouponResponse::BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const
{
	Serializer->WriteValue(TEXT("count"), Count);		
}

void UGetTotalCouponResponse ::BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag)
{
	FDefaultValueHelper::ParseInt64(Bag->GetStringField(TEXT("count")), Count);
}