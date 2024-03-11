#pragma once

#include "Subsystems/CLI/BeamCliCommand.h"
#include "Serialization/BeamJsonUtils.h"

#include "BeamCliServicesSetLocalManifestCommand.generated.h"

class FMonitoredProcess;



/**
 Description:
  Set the entire state of the local manifest, overwriting any existing entries

Usage:
  Beamable.Tools services set-local-manifest [options]

Options:
  --services <services>                    Local http services paths
  --storage-paths <storage-paths>          Local storages paths
  --storage-names <storage-names>          Local storages names
  --disabled-services <disabled-services>  Names of the services that should be disabled on remote
  --dryrun                                 Should any networking happen?
  --cid <cid>                              Cid to use; will default to whatever is in the file system
  --pid <pid>                              Pid to use; will default to whatever is in the file system
  --host <host>                            The host endpoint for beamable
  --refresh-token <refresh-token>          Refresh token to use for the requests
  --log, --logs <log>                      Extra logs gets printed out
  --dir <dir>                              Directory to use for configuration
  --raw                                    Output raw JSON to standard out. This happens by default when the command is being piped
  --pretty                                 Output syntax highlighted box text. This happens by default when the command is not piped
  --dotnet-path <dotnet-path>              a custom location for dotnet
  -?, -h, --help                           Show help and usage information



 */
UCLASS()
class UBeamCliServicesSetLocalManifestCommand : public UBeamCliCommand
{
	GENERATED_BODY()

public:
		

	TFunction<void (const int& ResCode, const FBeamOperationHandle& Op)> OnCompleted;
	virtual TSharedPtr<FMonitoredProcess> RunImpl(const TArray<FString>& CommandParams, const FBeamOperationHandle& Op = {}) override;
};
