
#include "BeamableCore/Public/AutoGen/RealmConfigurationLibrary.h"

#include "CoreMinimal.h"


FString URealmConfigurationLibrary::RealmConfigurationToJsonString(const URealmConfiguration* Serializable, const bool Pretty)
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

URealmConfiguration* URealmConfigurationLibrary::Make(UWebSocketConfiguration* WebsocketConfig, FString MicroserviceURI, FString PortalURI, FString StorageBrowserURI, FString Environment, UObject* Outer)
{
	auto Serializable = NewObject<URealmConfiguration>(Outer);
	Serializable->WebsocketConfig = WebsocketConfig;
	Serializable->MicroserviceURI = MicroserviceURI;
	Serializable->PortalURI = PortalURI;
	Serializable->StorageBrowserURI = StorageBrowserURI;
	Serializable->Environment = Environment;
	
	return Serializable;
}

void URealmConfigurationLibrary::Break(const URealmConfiguration* Serializable, UWebSocketConfiguration*& WebsocketConfig, FString& MicroserviceURI, FString& PortalURI, FString& StorageBrowserURI, FString& Environment)
{
	WebsocketConfig = Serializable->WebsocketConfig;
	MicroserviceURI = Serializable->MicroserviceURI;
	PortalURI = Serializable->PortalURI;
	StorageBrowserURI = Serializable->StorageBrowserURI;
	Environment = Serializable->Environment;
		
}

