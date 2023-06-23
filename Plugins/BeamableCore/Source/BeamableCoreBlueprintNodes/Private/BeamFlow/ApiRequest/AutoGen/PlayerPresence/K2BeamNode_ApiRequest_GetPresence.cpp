

#include "BeamableCoreBlueprintNodes/Public/BeamFlow/ApiRequest/AutoGen/PlayerPresence/K2BeamNode_ApiRequest_GetPresence.h"

#include "BeamK2.h"

#include "BeamableCore/Public/AutoGen/SubSystems/BeamPlayerPresenceApi.h"
#include "BeamableCore/Public/AutoGen/SubSystems/PlayerPresence/GetPresenceRequest.h"
#include "BeamableCore/Public/AutoGen/OnlineStatus.h"

#define LOCTEXT_NAMESPACE "K2BeamNode_ApiRequest_GetPresence"

using namespace BeamK2;

FName UK2BeamNode_ApiRequest_GetPresence::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UBeamPlayerPresenceApi, GetSelf);
}

FName UK2BeamNode_ApiRequest_GetPresence::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UBeamPlayerPresenceApi, GetPresence);
}

FName UK2BeamNode_ApiRequest_GetPresence::GetMakeFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UGetPresenceRequest, Make);
}

FString UK2BeamNode_ApiRequest_GetPresence::GetServiceName() const
{
	return TEXT("PlayerPresence");
}

FString UK2BeamNode_ApiRequest_GetPresence::GetEndpointName() const
{
	return TEXT("GetPresence");
}

UClass* UK2BeamNode_ApiRequest_GetPresence::GetApiClass() const
{
	return UBeamPlayerPresenceApi::StaticClass();
}

UClass* UK2BeamNode_ApiRequest_GetPresence::GetRequestClass() const
{
	return UGetPresenceRequest::StaticClass();
}

UClass* UK2BeamNode_ApiRequest_GetPresence::GetResponseClass() const
{
	return UOnlineStatus::StaticClass();
}

FString UK2BeamNode_ApiRequest_GetPresence::GetRequestSuccessDelegateName() const
{
	return TEXT("OnGetPresenceSuccess");
}

FString UK2BeamNode_ApiRequest_GetPresence::GetRequestErrorDelegateName() const
{
	return TEXT("OnGetPresenceError");
}

FString UK2BeamNode_ApiRequest_GetPresence::GetRequestCompleteDelegateName() const
{
	return TEXT("OnGetPresenceComplete");
}

#undef LOCTEXT_NAMESPACE
