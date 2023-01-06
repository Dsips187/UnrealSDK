
#include "AutoGen/Project.h"
#include "Serialization/BeamJsonUtils.h"




void UProject ::BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const
{
	Serializer->WriteValue(TEXT("archived"), bArchived);
	Serializer->WriteValue(TEXT("root"), bRoot);
	Serializer->WriteValue(TEXT("secret"), Secret);
	UBeamJsonUtils::SerializeSemanticType<FString>(TEXT("name"), &Name, Serializer);
	Serializer->WriteValue(TEXT("plan"), Plan);
	UBeamJsonUtils::SerializeMap<FString>(TEXT("customCharts"), CustomCharts, Serializer);
	UBeamJsonUtils::SerializeOptional<bool>(TEXT("sharded"), &bSharded, Serializer);
	UBeamJsonUtils::SerializeOptional<bool>(TEXT("sigval"), &bSigval, Serializer);
	UBeamJsonUtils::SerializeOptional<FString>(TEXT("displayName"), &DisplayName, Serializer);
	UBeamJsonUtils::SerializeOptional<FString>(TEXT("parent"), &Parent, Serializer);
	UBeamJsonUtils::SerializeOptional<FString>(TEXT("status"), &Status, Serializer);
	UBeamJsonUtils::SerializeOptional<int64>(TEXT("created"), &Created, Serializer);
	UBeamJsonUtils::SerializeOptional<TArray<FString>, FString>(TEXT("children"), &Children, Serializer);
	UBeamJsonUtils::SerializeOptional<TMap<FString, FString>, FString>(TEXT("config"), &Config, Serializer);
}

void UProject::BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const
{
	Serializer->WriteValue(TEXT("archived"), bArchived);
	Serializer->WriteValue(TEXT("root"), bRoot);
	Serializer->WriteValue(TEXT("secret"), Secret);
	UBeamJsonUtils::SerializeSemanticType<FString>(TEXT("name"), &Name, Serializer);
	Serializer->WriteValue(TEXT("plan"), Plan);
	UBeamJsonUtils::SerializeMap<FString>(TEXT("customCharts"), CustomCharts, Serializer);
	UBeamJsonUtils::SerializeOptional<bool>(TEXT("sharded"), &bSharded, Serializer);
	UBeamJsonUtils::SerializeOptional<bool>(TEXT("sigval"), &bSigval, Serializer);
	UBeamJsonUtils::SerializeOptional<FString>(TEXT("displayName"), &DisplayName, Serializer);
	UBeamJsonUtils::SerializeOptional<FString>(TEXT("parent"), &Parent, Serializer);
	UBeamJsonUtils::SerializeOptional<FString>(TEXT("status"), &Status, Serializer);
	UBeamJsonUtils::SerializeOptional<int64>(TEXT("created"), &Created, Serializer);
	UBeamJsonUtils::SerializeOptional<TArray<FString>, FString>(TEXT("children"), &Children, Serializer);
	UBeamJsonUtils::SerializeOptional<TMap<FString, FString>, FString>(TEXT("config"), &Config, Serializer);		
}

void UProject ::BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag)
{
	bArchived = Bag->GetBoolField(TEXT("archived"));
	bRoot = Bag->GetBoolField(TEXT("root"));
	Secret = Bag->GetStringField(TEXT("secret"));
	UBeamJsonUtils::DeserializeSemanticType<FString>(Bag->TryGetField(TEXT("name")), Name, OuterOwner);
	Plan = Bag->GetStringField(TEXT("plan"));
	UBeamJsonUtils::DeserializeMap<FString>(Bag->GetObjectField(TEXT("customCharts")), CustomCharts, OuterOwner);
	UBeamJsonUtils::DeserializeOptional<bool>("sharded", Bag, bSharded, OuterOwner);
	UBeamJsonUtils::DeserializeOptional<bool>("sigval", Bag, bSigval, OuterOwner);
	UBeamJsonUtils::DeserializeOptional<FString>("displayName", Bag, DisplayName, OuterOwner);
	UBeamJsonUtils::DeserializeOptional<FString>("parent", Bag, Parent, OuterOwner);
	UBeamJsonUtils::DeserializeOptional<FString>("status", Bag, Status, OuterOwner);
	UBeamJsonUtils::DeserializeOptional<int64>("created", Bag, Created, OuterOwner);
	UBeamJsonUtils::DeserializeOptional<TArray<FString>, FString>("children", Bag, Children, OuterOwner);
	UBeamJsonUtils::DeserializeOptional<TMap<FString, FString>, FString>("config", Bag, Config, OuterOwner);
}