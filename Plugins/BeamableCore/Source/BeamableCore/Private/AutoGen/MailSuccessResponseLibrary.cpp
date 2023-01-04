
#include "AutoGen/MailSuccessResponseLibrary.h"

#include "CoreMinimal.h"


FString UMailSuccessResponseLibrary::MailSuccessResponseToJsonString(const UMailSuccessResponse* Serializable, const bool Pretty)
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

UMailSuccessResponse* UMailSuccessResponseLibrary::Make(bool bResult, UObject* Outer)
{
	auto Serializable = NewObject<UMailSuccessResponse>(Outer);
	Serializable->bResult = bResult;
	
	return Serializable;
}

void UMailSuccessResponseLibrary::Break(const UMailSuccessResponse* Serializable, bool& bResult)
{
	bResult = Serializable->bResult;
		
}
