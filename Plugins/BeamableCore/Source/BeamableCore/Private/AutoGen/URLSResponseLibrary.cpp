
#include "BeamableCore/Public/AutoGen/URLSResponseLibrary.h"

#include "CoreMinimal.h"


FString UURLSResponseLibrary::URLSResponseToJsonString(const UURLSResponse* Serializable, const bool Pretty)
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

UURLSResponse* UURLSResponseLibrary::Make(TArray<UURLResponse*> Response, UObject* Outer)
{
	auto Serializable = NewObject<UURLSResponse>(Outer);
	Serializable->Response = Response;
	
	return Serializable;
}

void UURLSResponseLibrary::Break(const UURLSResponse* Serializable, TArray<UURLResponse*>& Response)
{
	Response = Serializable->Response;
		
}

