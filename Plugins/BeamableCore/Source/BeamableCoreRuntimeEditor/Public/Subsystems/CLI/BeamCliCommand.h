#pragma once

#include "CoreMinimal.h"
#include "BeamCli.h"
#include "Misc/MonitoredProcess.h"
#include "RequestTracker/BeamOperationHandle.h"
#include "Async/Async.h"
#include "HttpModule.h"
#include "BeamCliCommand.generated.h"

class FMonitoredProcess;
class UBeamEditor;
class UBeamRequestTracker;

struct FCliRequest
{
	FString commandLine;
};

UCLASS(Abstract)
class UBeamCliCommand : public UObject
{
	GENERATED_BODY()

protected:
	TSharedPtr<FMonitoredProcess> CmdProcess;
	FHttpRequestPtr CmdRequest;

public:
	UBeamCliCommand() = default;

	const static FString PathToLocalCli;	

	/**
	 *  Appends global options we want to pass to every command.
	 */
	static FString PrepareParams(FString Params);

	/**
	 * Runs a command asynchronously. The command runs in a separate thread --- the callbacks configured in the command, however, are always run on the GameThread.	  
	 */
	virtual void Run(const TArray<FString>& CommandParams, const FBeamOperationHandle& Op = {});;

	/**
	 * Runs a command in a separate thread but blocks the calling thread until it is done.
	 * The command runs in a separate thread --- the callbacks configured in the command, however, are always run on the GameThread.	  
	 */
	virtual void RunSync(const TArray<FString>& CommandParams, const FBeamOperationHandle& Op = {});

	/**
	 * Runs the command as an HTTP request to the long running CLI process running in server mode that we start at the UBeamCli setup.
	 * The command runs as an HTTP request and its callbacks are guaranteed to run on the GameThread.	  
	 */
	virtual void RunServer(const FString Uri, const TArray<FString>& CommandParams, const FBeamOperationHandle& Op = {});

	/**
	 * For Run and RunSync, this prepares the CmdProcess to be run. 
	 */
	virtual void PrepareCommandProcess(const TArray<FString>& CommandParams, const FBeamOperationHandle& Op = {});

	/**
	 * Helper function to parse out the StdOut of the CmdProcess Run/RunSync and extract the JSON responses from it.  
	 */
	bool ConsumeMessageFromOutput(FString& StdOutCopy, FString& OutMessageJson);

	/**
	 * Whether or not a command has been started and is finished. Returns false for commands that have never been started.
	 */
	bool IsDone() const;


	/** START -  Auto Generated Function Overrides */

	/**
	 * Generated via Beam CLI for every cmd subclass. Returns the command name ("version", "project ps", etc...).
	 */
	virtual FString GetCommand();

	/**
	 * Generated via Beam CLI for every cmd subclass. Parses any received JSON and invokes the cmd subclass' appropriate  
	 */
	virtual void HandleStreamReceived(FBeamOperationHandle Op, FString ReceivedStreamType, int64 Timestamp, TSharedRef<FJsonObject> DataJson, bool isServer);
	virtual void HandleStreamCompleted(FBeamOperationHandle Op, int ResultCode, bool isServer);

	/** END -  Auto Generated Function Overrides */

	bool bIsReceivingMessage;
	FString MessageBuffer;

protected:
	UPROPERTY()
	UBeamRequestTracker* RequestTracker;
	UPROPERTY()
	UBeamEditor* Editor;
	UPROPERTY()
	UBeamCli* Cli;
};
