#include "BeamCliServicesDeployCommand.h"

#include "BeamLogging.h"
#include "Serialization/JsonSerializerMacros.h"

FString UBeamCliServicesDeployCommand::GetCommand()
{
	return FString(TEXT("services deploy"));
}
		
void UBeamCliServicesDeployCommand::HandleStreamReceived(FBeamOperationHandle Op, FString ReceivedStreamType, int64 Timestamp, TSharedRef<FJsonObject> DataJson, bool isServer)
{
	if(ReceivedStreamType.Equals(StreamType) && OnStreamOutput)
	{
		UBeamCliServicesDeployStreamData* Data = NewObject<UBeamCliServicesDeployStreamData>(this);
		Data->OuterOwner = this;
		Data->BeamDeserializeProperties(DataJson);

		Stream.Add(Data);
		Timestamps.Add(Timestamp);
		
		AsyncTask(ENamedThreads::GameThread, [this, Op]
		{
			OnStreamOutput(Stream, Timestamps, Op);
		});				
	}
if(ReceivedStreamType.Equals(StreamTypeRemoteProgress) && OnRemoteProgressStreamOutput)
	{
		UBeamCliServicesDeployRemoteProgressStreamData* Data = NewObject<UBeamCliServicesDeployRemoteProgressStreamData>(this);
		Data->OuterOwner = this;
		Data->BeamDeserializeProperties(DataJson);

		RemoteProgressStream.Add(Data);
		RemoteProgressTimestamps.Add(Timestamp);
		
		AsyncTask(ENamedThreads::GameThread, [this, Op]
		{
			OnRemoteProgressStreamOutput(RemoteProgressStream, RemoteProgressTimestamps, Op);
		});				
	}
if(ReceivedStreamType.Equals(StreamTypeLogs) && OnLogsStreamOutput)
	{
		UBeamCliServicesDeployLogsStreamData* Data = NewObject<UBeamCliServicesDeployLogsStreamData>(this);
		Data->OuterOwner = this;
		Data->BeamDeserializeProperties(DataJson);

		LogsStream.Add(Data);
		LogsTimestamps.Add(Timestamp);
		
		AsyncTask(ENamedThreads::GameThread, [this, Op]
		{
			OnLogsStreamOutput(LogsStream, LogsTimestamps, Op);
		});				
	}
}

void UBeamCliServicesDeployCommand::HandleStreamCompleted(FBeamOperationHandle Op, int ResultCode, bool isServer)
{
	if (OnCompleted)
	{
		AsyncTask(ENamedThreads::GameThread, [this, ResultCode, Op]
		{
			OnCompleted(ResultCode, Op);
		});
	}
}
