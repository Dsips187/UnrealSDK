
#include "AutoGen/MakeFriendshipRequestBodyLibrary.h"

#include "CoreMinimal.h"


FString UMakeFriendshipRequestBodyLibrary::MakeFriendshipRequestBodyToJsonString(const UMakeFriendshipRequestBody* Serializable, const bool Pretty)
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

UMakeFriendshipRequestBody* UMakeFriendshipRequestBodyLibrary::Make(int64 GamerTag, UObject* Outer)
{
	auto Serializable = NewObject<UMakeFriendshipRequestBody>(Outer);
	Serializable->GamerTag = GamerTag;
	
	return Serializable;
}

void UMakeFriendshipRequestBodyLibrary::Break(const UMakeFriendshipRequestBody* Serializable, int64& GamerTag)
{
	GamerTag = Serializable->GamerTag;
		
}
