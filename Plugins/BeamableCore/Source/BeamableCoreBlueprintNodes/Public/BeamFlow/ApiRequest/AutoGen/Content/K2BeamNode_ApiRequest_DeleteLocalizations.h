
#pragma once

#include "CoreMinimal.h"
#include "BeamFlow/ApiRequest/K2BeamNode_ApiRequest.h"

#include "K2BeamNode_ApiRequest_DeleteLocalizations.generated.h"

#define LOCTEXT_NAMESPACE "K2BeamNode_ApiRequest_DeleteLocalizations"

/**
* This is the code-gen'ed declaration for the Beam Flow's Endpoint: Delete /basic/content/localizations  of the Content Service. 
*/
UCLASS(meta=(BeamFlow))
class BEAMABLECOREBLUEPRINTNODES_API UK2BeamNode_ApiRequest_DeleteLocalizations : public UK2BeamNode_ApiRequest
{
	GENERATED_BODY()

public:
	virtual FName GetSelfFunctionName() const override;
	virtual FName GetRequestFunctionName() const override;
	virtual FName GetMakeFunctionName() const override;
	virtual FString GetServiceName() const override;
	virtual FString GetEndpointName() const override;
	virtual UClass* GetApiClass() const override;
	virtual UClass* GetRequestClass() const override;
	virtual UClass* GetResponseClass() const override;
	virtual FString GetRequestSuccessDelegateName() const override;
	virtual FString GetRequestErrorDelegateName() const override;
	virtual FString GetRequestCompleteDelegateName() const override;
};

#undef LOCTEXT_NAMESPACE