
#include "AutoGen/StatUpdateRequestBodyLibrary.h"

#include "CoreMinimal.h"


FString UStatUpdateRequestBodyLibrary::StatUpdateRequestBodyToJsonString(const UStatUpdateRequestBody* Serializable, const bool Pretty)
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

UStatUpdateRequestBody* UStatUpdateRequestBodyLibrary::Make(FOptionalBool bEmitAnalytics, FOptionalString ObjectId, FOptionalMapOfString Set, FOptionalMapOfString Add, UObject* Outer)
{
	auto Serializable = NewObject<UStatUpdateRequestBody>(Outer);
	Serializable->bEmitAnalytics = bEmitAnalytics;
	Serializable->ObjectId = ObjectId;
	Serializable->Set = Set;
	Serializable->Add = Add;
	
	return Serializable;
}

void UStatUpdateRequestBodyLibrary::Break(const UStatUpdateRequestBody* Serializable, FOptionalBool& bEmitAnalytics, FOptionalString& ObjectId, FOptionalMapOfString& Set, FOptionalMapOfString& Add)
{
	bEmitAnalytics = Serializable->bEmitAnalytics;
	ObjectId = Serializable->ObjectId;
	Set = Serializable->Set;
	Add = Serializable->Add;
		
}

