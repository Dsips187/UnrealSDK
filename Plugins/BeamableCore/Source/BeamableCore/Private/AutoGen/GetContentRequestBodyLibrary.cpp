
#include "AutoGen/GetContentRequestBodyLibrary.h"

#include "CoreMinimal.h"


FString UGetContentRequestBodyLibrary::GetContentRequestBodyToJsonString(const UGetContentRequestBody* Serializable, const bool Pretty)
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

UGetContentRequestBody* UGetContentRequestBodyLibrary::Make(FBeamContentId ContentId, FString Version, UObject* Outer)
{
	auto Serializable = NewObject<UGetContentRequestBody>(Outer);
	Serializable->ContentId = ContentId;
	Serializable->Version = Version;
	
	return Serializable;
}

void UGetContentRequestBodyLibrary::Break(const UGetContentRequestBody* Serializable, FBeamContentId& ContentId, FString& Version)
{
	ContentId = Serializable->ContentId;
	Version = Serializable->Version;
		
}

