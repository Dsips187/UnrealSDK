﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BeamEditorSettings.h"
#include "WidgetBlueprint.h"
#include "BeamableEditorBlueprintLibrary.generated.h"

UCLASS()
class BEAMABLECOREEDITOR_API UBeamableEditorBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Beam|Editor")
	static void StartWidget(UWidgetBlueprint* Blueprint);

	UFUNCTION(BlueprintCallable, Category="Beam|Editor")
	static FString GetCidFromInt(int64 Cid);

	UFUNCTION(BlueprintCallable, Category="Beam|Editor")
	static void GetRealmsForProject(const FBeamCustomerProjectData& ProjectData, const FString ProjectName, TArray<FBeamProjectRealmData>& ProjectRealms);	

	UFUNCTION(BlueprintCallable, Category="Beam|Editor")
	static bool GetRunningPIEWorld(UWorld*& PIEWorld);
};
