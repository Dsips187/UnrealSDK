#pragma once

#include "Subsystems/CLI/BeamCliCommand.h"
#include "Serialization/BeamJsonUtils.h"

#include "BeamCliProjectGenerateClientCommand.generated.h"

class FMonitoredProcess;



/**
 Description:
  Generate a C# client file based on a built C# microservice dll directory

Usage:
  Beamable.Tools project generate-client <source> [options]

Arguments:
  <source>  The .dll filepath for the built microservice

Options:
  --output-dir <output-dir>        Directory to write the output client at
  --output-links                   When true, generate the source client files to all associated projects [default: True]
  --dryrun                         Should any networking happen?
  --cid <cid>                      Cid to use; will default to whatever is in the file system
  --pid <pid>                      Pid to use; will default to whatever is in the file system
  --host <host>                    The host endpoint for beamable
  --refresh-token <refresh-token>  Refresh token to use for the requests
  --log, --logs <log>              Extra logs gets printed out
  --dir <dir>                      Directory to use for configuration
  --raw                            Output raw JSON to standard out. This happens by default when the command is being piped
  --pretty                         Output syntax highlighted box text. This happens by default when the command is not piped
  --dotnet-path <dotnet-path>      a custom location for dotnet
  -?, -h, --help                   Show help and usage information




 */
UCLASS()
class UBeamCliProjectGenerateClientCommand : public UBeamCliCommand
{
	GENERATED_BODY()

public:
		

	TFunction<void (const int& ResCode, const FBeamOperationHandle& Op)> OnCompleted;
	virtual TSharedPtr<FMonitoredProcess> RunImpl(const TArray<FString>& CommandParams, const FBeamOperationHandle& Op = {}) override;
};
