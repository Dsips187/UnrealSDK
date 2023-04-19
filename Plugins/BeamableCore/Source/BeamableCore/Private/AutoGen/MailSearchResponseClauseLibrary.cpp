
#include "BeamableCore/Public/AutoGen/MailSearchResponseClauseLibrary.h"

#include "CoreMinimal.h"


FString UMailSearchResponseClauseLibrary::MailSearchResponseClauseToJsonString(const UMailSearchResponseClause* Serializable, const bool Pretty)
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

UMailSearchResponseClause* UMailSearchResponseClauseLibrary::Make(FString Name, int64 Count, FOptionalArrayOfMailObjectMessage Content, UObject* Outer)
{
	auto Serializable = NewObject<UMailSearchResponseClause>(Outer);
	Serializable->Name = Name;
	Serializable->Count = Count;
	Serializable->Content = Content;
	
	return Serializable;
}

void UMailSearchResponseClauseLibrary::Break(const UMailSearchResponseClause* Serializable, FString& Name, int64& Count, FOptionalArrayOfMailObjectMessage& Content)
{
	Name = Serializable->Name;
	Count = Serializable->Count;
	Content = Serializable->Content;
		
}

