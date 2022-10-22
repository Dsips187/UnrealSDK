﻿#pragma once

#include "BeamBackend/BeamBackend.h"
class UBeamBackendTestCallbacks;

BEGIN_DEFINE_SPEC(FBeamBackendSpec, "BeamableUnreal.BeamBackend", EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	UBeamBackend* BeamBackendSystem;	

	UBeamBackendTestCallbacks* Callbacks;

	FBeamConnectivity StatusAtTestRunStart;
	TArray<FDelegateHandle> RegisteredDelegatesDuringConnectivityTests;
END_DEFINE_SPEC(FBeamBackendSpec)
