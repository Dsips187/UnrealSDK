#pragma once

#include "Subsystems/CLI/BeamCliCommand.h"
#include "BeamCliProjectPsCommand.generated.h"

class FMonitoredProcess;


USTRUCT()
struct FBeamCliProjectPsStreamData
{
	GENERATED_BODY()

	inline static FString StreamTypeName = FString(TEXT("stream"));

	UPROPERTY()
	FString cid;
	UPROPERTY()
	FString pid;
	UPROPERTY()
	FString prefix;
	UPROPERTY()
	FString service;
	UPROPERTY()
	bool isRunning = {};
	UPROPERTY()
	bool isContainer = {};
};


/**
 Description:
  List the running status of local services not running in docker

Usage:
  Beamable.Tools project ps [options]

Options:
  --dryrun                         Should any networking happen?
  --cid <cid>                      Cid to use; will default to whatever is in the file system
  --pid <pid>                      Pid to use; will default to whatever is in the file system
  --host <host>                    The host endpoint for beamable
  --refresh-token <refresh-token>  Refresh token to use for the requests
  --log <log>                      Extra logs gets printed out
  --dir <dir>                      Directory to use for configuration
  -?, -h, --help                   Show help and usage information



 */
UCLASS()
class UBeamCliProjectPsCommand : public UBeamCliCommand
{
	GENERATED_BODY()

public:
	TArray<FBeamCliProjectPsStreamData> Stream;
	TArray<int64> Timestamps;
	TFunction<void (const TArray<FBeamCliProjectPsStreamData>& StreamData, const TArray<int64>& Timestamps, const FBeamOperationHandle& Op)> OnStreamOutput;

	TFunction<void (const int& ResCode, const FBeamOperationHandle& Op)> OnCompleted;
	virtual TSharedPtr<FMonitoredProcess> RunImpl(const TArray<FString>& CommandParams, const FBeamOperationHandle& Op = {}) override;
};
