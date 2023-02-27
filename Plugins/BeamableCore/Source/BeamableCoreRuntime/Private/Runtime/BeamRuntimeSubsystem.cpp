﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "Runtime/BeamRuntimeSubsystem.h"

#include "BeamLogging.h"

void UBeamRuntimeSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	Runtime = Cast<UBeamRuntime>(Collection.InitializeDependency(UBeamRuntime::StaticClass()));
}

void UBeamRuntimeSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

FBeamOperationHandle UBeamRuntimeSubsystem::InitializeWhenUnrealReady()
{
	UE_LOG(LogBeamRuntime, Verbose, TEXT("Runtime Subsystem %s - Initializing after GameInstance is ready"), *GetName())

	// By default, just return an empty completed operation
	const auto Handle = Runtime->RequestTrackerSystem->BeginOperation({}, GetName(), {});
	Runtime->RequestTrackerSystem->TriggerOperationSuccess(Handle, {});
	return Handle;
}

FBeamOperationHandle UBeamRuntimeSubsystem::OnUserSignedIn(const FUserSlot& UserSlot, const FBeamRealmUser& BeamRealmUser)
{
	UE_LOG(LogBeamRuntime, Verbose, TEXT("Runtime Subsystem %s - On User Signed In from Slot %s"), *GetName(), *UserSlot.Name)

	// By default, just return an empty completed operation
	const auto Handle = Runtime->RequestTrackerSystem->BeginOperation({}, GetName(), {});
	Runtime->RequestTrackerSystem->TriggerOperationSuccess(Handle, {});
	return Handle;
}

void UBeamRuntimeSubsystem::OnPostUserSignedIn_Implementation(const FUserSlot& UserSlot, const FBeamRealmUser& BeamRealmUser)
{
	UE_LOG(LogBeamRuntime, Verbose, TEXT("Runtime Subsystem %s - On Post User Signed In"), *GetName())
}

FBeamOperationHandle UBeamRuntimeSubsystem::OnUserSignedOut(const FUserSlot& UserSlot, const EUserSlotClearedReason Reason, const FBeamRealmUser& BeamRealmUser)
{
	UE_LOG(LogBeamRuntime, Verbose, TEXT("Runtime Subsystem %s - On User Signed Out from Slot %s and Reason %s"), *GetName(), *UserSlot.Name,
	       *StaticEnum<EUserSlotClearedReason>()->GetValueAsString(Reason))

	// By default, just return an empty completed operation
	const auto Handle = Runtime->RequestTrackerSystem->BeginOperation({}, GetName(), {});
	Runtime->RequestTrackerSystem->TriggerOperationSuccess(Handle, {});
	return Handle;
}

void UBeamRuntimeSubsystem::OnPostUserSignedOut_Implementation(const FUserSlot& UserSlot, const EUserSlotClearedReason Reason, const FBeamRealmUser& BeamRealmUser)
{
	UE_LOG(LogBeamRuntime, Verbose, TEXT("Runtime Subsystem %s - On Post User Signed Out"), *GetName())
}

void UBeamRuntimeSubsystem::OnBeamableReady_Implementation()
{
	bIsInitialized = true;
}
