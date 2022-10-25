
#include "AutoGen/GroupMembershipRequestBodyLibrary.h"

#include "CoreMinimal.h"


FString UGroupMembershipRequestBodyLibrary::GroupMembershipRequestBodyToJsonString(const UGroupMembershipRequestBody* Serializable, const bool Pretty)
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

UGroupMembershipRequestBody* UGroupMembershipRequestBodyLibrary::Make(EGroupType Type, int64 Group, FOptionalInt64 Successor, FOptionalInt64 Score, FOptionalInt64 SubGroup, UObject* Outer)
{
	auto Serializable = NewObject<UGroupMembershipRequestBody>(Outer);
	Serializable->Type = Type;
	Serializable->Group = Group;
	Serializable->Successor = Successor;
	Serializable->Score = Score;
	Serializable->SubGroup = SubGroup;
	
	return Serializable;
}

void UGroupMembershipRequestBodyLibrary::Break(const UGroupMembershipRequestBody* Serializable, EGroupType& Type, int64& Group, FOptionalInt64& Successor, FOptionalInt64& Score, FOptionalInt64& SubGroup)
{
	Type = Serializable->Type;
	Group = Serializable->Group;
	Successor = Serializable->Successor;
	Score = Serializable->Score;
	SubGroup = Serializable->SubGroup;
		
}

