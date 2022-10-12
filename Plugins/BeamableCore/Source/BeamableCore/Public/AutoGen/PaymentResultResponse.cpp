
#include "AutoGen/PaymentResultResponse.h"



void UPaymentResultResponse ::BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const
{
	Serializer->WriteValue(TEXT("result"), Result);
}

void UPaymentResultResponse::BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const
{
	Serializer->WriteValue(TEXT("result"), Result);		
}

void UPaymentResultResponse ::BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag)
{
	Result = Bag->GetStringField(TEXT("result"));
}