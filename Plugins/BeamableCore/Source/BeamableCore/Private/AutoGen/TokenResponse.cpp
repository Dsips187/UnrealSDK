
#include "AutoGen/TokenResponse.h"
#include "Serialization/BeamJsonUtils.h"
#include "Misc/DefaultValueHelper.h"


void UTokenResponse::DeserializeRequestResponse(UObject* RequestData, FString ResponseContent)
{
	OuterOwner = RequestData;
	BeamDeserialize(ResponseContent);	
}

void UTokenResponse::BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const
{
	Serializer->WriteValue(TEXT("expires_in"), ExpiresIn);
	Serializer->WriteValue(TEXT("token_type"), TokenType);
	UBeamJsonUtils::SerializeOptional<FString>(TEXT("access_token"), &AccessToken, Serializer);
	UBeamJsonUtils::SerializeOptional<FString>(TEXT("refresh_token"), &RefreshToken, Serializer);
	UBeamJsonUtils::SerializeOptional<FString>(TEXT("challenge_token"), &ChallengeToken, Serializer);
	UBeamJsonUtils::SerializeOptional<TArray<FString>, FString>(TEXT("scopes"), &Scopes, Serializer);
}

void UTokenResponse::BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const
{
	Serializer->WriteValue(TEXT("expires_in"), ExpiresIn);
	Serializer->WriteValue(TEXT("token_type"), TokenType);
	UBeamJsonUtils::SerializeOptional<FString>(TEXT("access_token"), &AccessToken, Serializer);
	UBeamJsonUtils::SerializeOptional<FString>(TEXT("refresh_token"), &RefreshToken, Serializer);
	UBeamJsonUtils::SerializeOptional<FString>(TEXT("challenge_token"), &ChallengeToken, Serializer);
	UBeamJsonUtils::SerializeOptional<TArray<FString>, FString>(TEXT("scopes"), &Scopes, Serializer);		
}

void UTokenResponse::BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag)
{
	FDefaultValueHelper::ParseInt64(Bag->GetStringField(TEXT("expires_in")), ExpiresIn);
	TokenType = Bag->GetStringField(TEXT("token_type"));
	UBeamJsonUtils::DeserializeOptional<FString>("access_token", Bag, AccessToken, OuterOwner);
	UBeamJsonUtils::DeserializeOptional<FString>("refresh_token", Bag, RefreshToken, OuterOwner);
	UBeamJsonUtils::DeserializeOptional<FString>("challenge_token", Bag, ChallengeToken, OuterOwner);
	UBeamJsonUtils::DeserializeOptional<TArray<FString>, FString>("scopes", Bag, Scopes, OuterOwner);
}



