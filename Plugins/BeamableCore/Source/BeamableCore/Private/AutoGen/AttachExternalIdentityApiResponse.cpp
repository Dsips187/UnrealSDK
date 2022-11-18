
#include "AutoGen/AttachExternalIdentityApiResponse.h"
#include "Serialization/BeamJsonUtils.h"



void UAttachExternalIdentityApiResponse::DeserializeRequestResponse(UObject* RequestData, FString ResponseContent)
{
	OuterOwner = RequestData;
	BeamDeserialize(ResponseContent);	
}

void UAttachExternalIdentityApiResponse ::BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const
{
	Serializer->WriteValue(TEXT("result"), Result);
	UBeamJsonUtils::SerializeOptional<FString>(TEXT("challenge_token"), &ChallengeToken, Serializer);
}

void UAttachExternalIdentityApiResponse::BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const
{
	Serializer->WriteValue(TEXT("result"), Result);
	UBeamJsonUtils::SerializeOptional<FString>(TEXT("challenge_token"), &ChallengeToken, Serializer);		
}

void UAttachExternalIdentityApiResponse ::BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag)
{
	Result = Bag->GetStringField(TEXT("result"));
	UBeamJsonUtils::DeserializeOptional<FString>("challenge_token", Bag, ChallengeToken, OuterOwner);
}