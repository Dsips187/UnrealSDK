﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "BeamEnvironment.h"
#include "BeamBackend/BeamRealmHandle.h"
#include "BeamBackend/BeamRetryConfig.h"
#include "BeamCoreSettings.generated.h"

/**
 * 
 */
UCLASS(config=Engine, defaultconfig, meta=(DisplayName="Beamable Core"))
class BEAMABLECORE_API UBeamCoreSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UBeamCoreSettings();

	/* Soft path will be converted to content reference before use */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "General", AdvancedDisplay)
	TSoftObjectPtr<UBeamEnvironmentData> BeamableEnvironment;

	/**
	* @brief A RealmHandle struct defining the CustomerID and RealmID (CID, PID) that this build will target.
	* All authentication and non-authenticated requests are made against this realm.
	*
	* In the editor environment, this is the realm where you are currently pointed at.
	* You can use the realm swap drop-down to change this from a list of available realms after you've signed in.
	* This CAN NEVER BE EMPTY if you are signed into Beamable.
	*
	* When you create an account or sign into a customer for the first time in this project, we default you to that customer's Dev realm if this is ever empty.
	*/
	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category="Request/Response")
	FBeamRealmHandle TargetRealm;

	/**
	 * @brief Whether or not we should run the global error handlers even if there was a handler provided at the callsite.
	 */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Request/Response")
	bool AlwaysRunGlobalErrorHandlers = true;

	/**
	 * @brief Whether or not we should log after running the Success callback --- by default we always log them if you provide no callback at the callsite.
	 */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Request/Response")
	bool AlwaysLogSuccessResponses = true;

	/**
	 * @brief Whether or not we should log after running the Error callback --- by default we always log them if you provide no callback at the callsite.
	 */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Request/Response")
	bool AlwaysLogErrorResponses = true;

	/**
	 * @brief Whether or not we should log after running the Complete callback --- by default we always log them if you provide no callback at the callsite.
	 */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Request/Response")
	bool AlwaysLogCompletedResponses = true;

	/**
	 * @brief The configuration for retrying requests.
	 * Setting the Max Attempt as -1 will make it an "infinite retry" though we don't recommend doing this from a design perspective.
	 * Setting more retry attempts than falloff values will default to the last possible falloff value after the attempts exceed the array length.
	 */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Request/Response")
	FBeamRetryConfig FallbackRetryConfiguration{{}, {}, 10, {.5f, 1, 2, 4, 8}, 5};

	/**
	 * @brief These are the expected user slots for your game. TODO User slots not registered here will not be allowed to be authenticated into.
	 */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "User Slots")
	TArray<FString> RuntimeUserSlots{"Player0"};

	/**
	 * @brief These are the expected user slots for your editor environment. By default, you get logged into the "MainEditorDeveloper" UserSlot.
	 * User slots not registered here will not be allowed to be authenticated into outside of EditorUtilityWidget/EditorUtilityBlueprints.
	 * Are only valid slots if they contain the word "Developer" in them.
	 */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="User Slots")
	TArray<FString> DeveloperUserSlots{"MainEditorDeveloper"};
	
	/**
	 * @brief Whether or not we should persist the Auth data for Runtime User Slots when we are in PIE.
	 */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="User Slots")
	bool bPersistRuntimeSlotDataWhenInPIE = false;
};
