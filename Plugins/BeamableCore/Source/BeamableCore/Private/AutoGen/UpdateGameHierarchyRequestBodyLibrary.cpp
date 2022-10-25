
#include "AutoGen/UpdateGameHierarchyRequestBodyLibrary.h"

#include "CoreMinimal.h"


FString UUpdateGameHierarchyRequestBodyLibrary::UpdateGameHierarchyRequestBodyToJsonString(const UUpdateGameHierarchyRequestBody* Serializable, const bool Pretty)
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

UUpdateGameHierarchyRequestBody* UUpdateGameHierarchyRequestBodyLibrary::Make(FString RootPID, TArray<UProjectView*> Projects, UObject* Outer)
{
	auto Serializable = NewObject<UUpdateGameHierarchyRequestBody>(Outer);
	Serializable->RootPID = RootPID;
	Serializable->Projects = Projects;
	
	return Serializable;
}

void UUpdateGameHierarchyRequestBodyLibrary::Break(const UUpdateGameHierarchyRequestBody* Serializable, FString& RootPID, TArray<UProjectView*>& Projects)
{
	RootPID = Serializable->RootPID;
	Projects = Serializable->Projects;
		
}

