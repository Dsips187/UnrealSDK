
#include "BeamableCore/Public/AutoGen/InFlightMessageLibrary.h"

#include "CoreMinimal.h"


FString UInFlightMessageLibrary::InFlightMessageToJsonString(const UInFlightMessage* Serializable, const bool Pretty)
{
	FString Result = FString{};
	if(Pretty)
	{
		TUnrealPrettyJsonSerializer JsonSerializer = TJsonStringWriter<TPrettyJsonPrintPolicy<wchar_t>>::Create(&Result);
		Serializable->BeamSerialize(JsonSerializer);
		JsonSerializer->Close();
	}
	else
	{
		TUnrealJsonSerializer JsonSerializer = TJsonStringWriter<TCondensedJsonPrintPolicy<wchar_t>>::Create(&Result);
		Serializable->BeamSerialize(JsonSerializer);
		JsonSerializer->Close();			
	}
	return Result;
}	

UInFlightMessage* UInFlightMessageLibrary::Make(FString Method, FString Body, FString Path, FString Service, FString Id, FOptionalInt64 GamerTag, FOptionalString Shard, UObject* Outer)
{
	auto Serializable = NewObject<UInFlightMessage>(Outer);
	Serializable->Method = Method;
	Serializable->Body = Body;
	Serializable->Path = Path;
	Serializable->Service = Service;
	Serializable->Id = Id;
	Serializable->GamerTag = GamerTag;
	Serializable->Shard = Shard;
	
	return Serializable;
}

void UInFlightMessageLibrary::Break(const UInFlightMessage* Serializable, FString& Method, FString& Body, FString& Path, FString& Service, FString& Id, FOptionalInt64& GamerTag, FOptionalString& Shard)
{
	Method = Serializable->Method;
	Body = Serializable->Body;
	Path = Serializable->Path;
	Service = Serializable->Service;
	Id = Serializable->Id;
	GamerTag = Serializable->GamerTag;
	Shard = Serializable->Shard;
		
}

