﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "UserSlots/BeamUserSlots.h"

#include "BeamCoreSettings.h"
#include "BeamLogging.h"
#include "JsonObjectConverter.h"

void UBeamUserSlots::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	Collection.InitializeDependency(UBeamEnvironment::StaticClass());
	UE_LOG(LogBeamUserSlots, Display, TEXT("Initializing UBeamUserSlots Subsystem!"));

	// Prepare data structures to hold all authenticated user data. 
	AuthenticatedUsers.Reserve(128);
	AuthenticatedUserMapping.Reserve(128);	
}

void UBeamUserSlots::Deinitialize()
{
	AuthenticatedUsers.Empty();
	AuthenticatedUserMapping.Empty();
}


FString UBeamUserSlots::GetSavedSlotAuthFilePath(FString NamespacedSlotId)
{
	return FPaths::ProjectSavedDir() / TEXT("Beamable") / TEXT("UserSlots") / NamespacedSlotId + TEXT("_Auth.json");
}

FString UBeamUserSlots::GetSavedSlotAccountFilePath(FString NamespacedSlotId)
{
	return FPaths::ProjectSavedDir() / TEXT("Beamable") / TEXT("UserSlots") / NamespacedSlotId + TEXT("_Account.json");
}

FString UBeamUserSlots::GetSlotDataSavedFilePath(FString SlotDataType, FUserSlot SlotId, const UObject* CallingContext)
{
	const auto NamespacedSlotId = GetNamespacedSlotId(SlotId, CallingContext);
	return FPaths::ProjectSavedDir() / TEXT("Beamable") / TEXT("UserSlots") / NamespacedSlotId + TEXT("_") + SlotDataType + TEXT(".json");
}

bool UBeamUserSlots::IsPIEContext(const UObject* CallingContext)
{
#if WITH_EDITOR
	if (!CallingContext) return false;

	const auto WorldContext = GEngine->GetWorldContextFromWorld(CallingContext->GetWorld());
	return WorldContext && WorldContext->WorldType == EWorldType::PIE;		
#else
	return false;
#endif
}

FString UBeamUserSlots::GetNamespacedSlotId(FUserSlot SlotId, const UObject* CallingContext)
{
#if WITH_EDITOR
	if (CallingContext)
	{
		const auto WorldContext = GEngine->GetWorldContextFromWorld(CallingContext->GetWorld());
		if (WorldContext && WorldContext->WorldType == EWorldType::PIE)
			return FString::Printf(TEXT("PIE_%d_%s"), WorldContext->PIEInstance, *SlotId.Name);
	}
#endif

	return SlotId.Name;
}

bool UBeamUserSlots::GetSlotIdFromNamespacedSlotId(const FString NamespacedSlotId, FUserSlot& OutUserSlot)
{
	// If we start with PIE, we'll have the following format: PIE_-1_UserSlotName
	if (int LastUnderscoreIdx = -1; NamespacedSlotId.StartsWith("PIE_") && NamespacedSlotId.FindLastChar('_', LastUnderscoreIdx))
	{
		// So we extract only the user slot name from it.
		OutUserSlot = NamespacedSlotId.RightChop(LastUnderscoreIdx + 1);
		return true;
	}

	OutUserSlot = NamespacedSlotId;
	return false;
}

bool UBeamUserSlots::IsSameSlot(FUserSlot SlotA, FUserSlot SlotB, const UObject* SlotAContext, const UObject* SlotBContext)
{
	const auto SlotANamespacedId = GetNamespacedSlotId(SlotA, SlotAContext);
	const auto SlotBNamespacedId = GetNamespacedSlotId(SlotB, SlotBContext);

	return SlotANamespacedId.Equals(SlotBNamespacedId);
}

bool UBeamUserSlots::GetUserDataAtSlot(FUserSlot SlotId, FBeamRealmUser& OutUserData, const UObject* CallingContext) const
{
	if (const FString NamespacedSlotId = GetNamespacedSlotId(SlotId, CallingContext); AuthenticatedUserMapping.Contains(NamespacedSlotId))
	{
		const auto idx = AuthenticatedUserMapping.FindChecked(NamespacedSlotId);
		OutUserData = AuthenticatedUsers[idx];

		UE_LOG(LogBeamUserSlots, Verbose, TEXT("Found User Data At Slot!\nUSER_SLOT=%s"), *NamespacedSlotId);
		return true;
	}

	OutUserData.GamerTag = -1;
	OutUserData.Email = TEXT("");
	OutUserData.AuthToken = FBeamAuthToken{TEXT(""), TEXT(""), 0};
	OutUserData.RealmHandle = FBeamRealmHandle{TEXT(""), TEXT("")};

	return false;
}

bool UBeamUserSlots::GetUserDataWithRefreshTokenAndPid(const FString& RefreshToken, const FString& Pid, FBeamRealmUser& OutUserData, FUserSlot& OutUserSlot) const
{
	for (const auto& UserMapping : AuthenticatedUserMapping)
	{
		OutUserData = AuthenticatedUsers[UserMapping.Value];
		if (OutUserData.AuthToken.RefreshToken == RefreshToken && OutUserData.RealmHandle.Pid == Pid)
		{
			const FString NamespacedSlotId = UserMapping.Key;
			GetSlotIdFromNamespacedSlotId(NamespacedSlotId, OutUserSlot);
			UE_LOG(LogBeamUserSlots, Verbose, TEXT("Found User Data with PID and RefreshToken At Slot!\nUSER_SLOT=%s"), *OutUserSlot.Name);
			return true;
		}
	}

	OutUserData.GamerTag = -1;
	OutUserData.Email = TEXT("");
	OutUserData.AuthToken = FBeamAuthToken{TEXT(""), TEXT(""), 0};
	OutUserData.RealmHandle = FBeamRealmHandle{TEXT(""), TEXT("")};

	OutUserSlot.Name = TEXT("");
	return false;
}

void UBeamUserSlots::SetAuthenticationDataAtSlot(FUserSlot SlotId, const FString& AccessToken, const FString& RefreshToken, const int64& ExpiresIn, const FString& Cid, const FString& Pid,
                                                 const UObject* CallingContext)
{
	const auto NamespacedSlotId = GetNamespacedSlotId(SlotId, CallingContext);

	const auto AuthenticatedUser = FBeamAuthToken{AccessToken, RefreshToken, ExpiresIn};
	const auto UserRealmData = FBeamRealmHandle{Cid, Pid};
	const auto RealmUser = FBeamRealmUser{-1, TEXT(""), UserRealmData, AuthenticatedUser};

	if (!AuthenticatedUserMapping.Contains(NamespacedSlotId))
	{
		AuthenticatedUsers.Add(RealmUser);
		AuthenticatedUserMapping.Add(NamespacedSlotId, AuthenticatedUsers.Num() - 1);

		UE_LOG(LogBeamUserSlots, Verbose, TEXT("Added User Data to slot!\nUSER_SLOT=%s"), *NamespacedSlotId);
	}
	else
	{
		const auto UserSlotIdx = AuthenticatedUserMapping.FindRef(NamespacedSlotId);
		auto& ExistingRealmUser = AuthenticatedUsers[UserSlotIdx];
		ExistingRealmUser.RealmHandle = UserRealmData;
		ExistingRealmUser.AuthToken = AuthenticatedUser;

		UE_LOG(LogBeamUserSlots, Verbose, TEXT("Updated User Data at slot!\nUSER_SLOT=%s"), *NamespacedSlotId);
	}
}

void UBeamUserSlots::SetGamerTagAtSlot(FUserSlot SlotId, const int64& GamerTag, const UObject* CallingContext)
{
	const auto NamespacedSlotId = GetNamespacedSlotId(SlotId, CallingContext);

	// This is here since you need to be authenticated to get the gamer tag anyways...
	ensureAlwaysMsgf(AuthenticatedUserMapping.Contains(NamespacedSlotId), TEXT("This must always be called after SetAuthenticationDataAtSlot."));

	const auto UserSlotIdx = AuthenticatedUserMapping.FindRef(NamespacedSlotId);
	auto& ExistingRealmUser = AuthenticatedUsers[UserSlotIdx];
	ExistingRealmUser.GamerTag = GamerTag;

	UE_LOG(LogBeamUserSlots, Verbose, TEXT("Updated GamerTag at slot!\nUSER_SLOT=%s, GAMERTAG=%lld"), *NamespacedSlotId, GamerTag);
}


void UBeamUserSlots::SetEmailAtSlot(FUserSlot SlotId, const FString& Email, const UObject* CallingContext)
{
	const auto NamespacedSlotId = GetNamespacedSlotId(SlotId, CallingContext);

	// This is here since you need to be authenticated to get the email anyways...
	ensureAlwaysMsgf(AuthenticatedUserMapping.Contains(NamespacedSlotId), TEXT("This must always be called after SetAuthenticationDataAtSlot."));

	const auto UserSlotIdx = AuthenticatedUserMapping.FindRef(NamespacedSlotId);
	auto& ExistingRealmUser = AuthenticatedUsers[UserSlotIdx];
	ExistingRealmUser.Email = Email;

	UE_LOG(LogBeamUserSlots, Verbose, TEXT("Updated Email at slot!\nUSER_SLOT=%s, EMAIL=%s"), *NamespacedSlotId, *Email);
}

void UBeamUserSlots::SetPIDAtSlot(FUserSlot SlotId, const FString& Pid, const UObject* CallingContext)
{
	const auto NamespacedSlotId = GetNamespacedSlotId(SlotId, CallingContext);

	// This is here since you need to be authenticated to get the email anyways...
	ensureAlwaysMsgf(AuthenticatedUserMapping.Contains(NamespacedSlotId), TEXT("This must always be called after SetAuthenticationDataAtSlot."));

	const auto UserSlotIdx = AuthenticatedUserMapping.FindRef(NamespacedSlotId);
	auto& ExistingRealmUser = AuthenticatedUsers[UserSlotIdx];
	ExistingRealmUser.RealmHandle.Pid = Pid;

	UE_LOG(LogBeamUserSlots, Verbose, TEXT("Updated PID at slot!\nUSER_SLOT=%s, PID=%s"), *NamespacedSlotId, *Pid);
}

void UBeamUserSlots::TriggerUserAuthenticatedIntoSlot(FUserSlot SlotId, const UObject* CallingContext)
{
	// Gets the auth'ed user
	FBeamRealmUser AuthenticatedUser;
	GetUserDataAtSlot(SlotId, AuthenticatedUser, CallingContext);

	// Broadcast events
	GlobalUserSlotAuthenticatedCodeHandler.Broadcast(SlotId, AuthenticatedUser, CallingContext);
	GlobalUserSlotAuthenticatedHandler.Broadcast(SlotId, AuthenticatedUser, CallingContext);
}


bool UBeamUserSlots::SaveSlot(FUserSlot SlotId, const UObject* CallingContext)
{
	// When we are running in PIE, we only save if we are configured to do so. Otherwise, we just act like we did. 
#if WITH_EDITOR
	if(IsPIEContext(CallingContext) && !GetDefault<UBeamCoreSettings>()->bPersistRuntimeSlotDataWhenInPIE)
		return true;
#endif
	
	const auto NamespacedSlotId = GetNamespacedSlotId(SlotId, CallingContext);

	FBeamRealmUser User;
	const auto bWasAuthenticated = GetUserDataAtSlot(SlotId, User, CallingContext);
	
#if !WITH_EDITOR
		ensureAlwaysMsgf(!User.RealmHandle.Pid.IsEmpty(), TEXT("Customer-Scoped Tokens are not allowed in builds! If should never be seeing this!"));
#endif

	// Save the User's Auth data to the slot.
	const auto SavedUserAuthDataPath = GetSavedSlotAuthFilePath(NamespacedSlotId);
	const auto AuthDataForSlot = FUserSlotAuthData{
		User.AuthToken.AccessToken,
		User.AuthToken.RefreshToken,
		User.AuthToken.ExpiresIn,
		User.RealmHandle.Cid,
		User.RealmHandle.Pid
	};
	FString JsonSerializedAuthData;
	ensureAlways(FJsonObjectConverter::UStructToJsonObjectString(AuthDataForSlot, JsonSerializedAuthData));

	if (FFileHelper::SaveStringToFile(*JsonSerializedAuthData, *SavedUserAuthDataPath))
	{
		UE_LOG(LogBeamUserSlots, Verbose, TEXT("Saved User Slot - Auth File!\nUSER_SLOT=%s\nFILE_PATH=%s\nFILE_CONTENTS=%s"), *NamespacedSlotId, *SavedUserAuthDataPath, *JsonSerializedAuthData);
	}
	else
	{
		UE_LOG(LogBeamUserSlots, Error, TEXT("Failed to create Saved User Slot - Auth File!\nUSER_SLOT=%s\nFILE_PATH=%s\nFILE_CONTENTS=%s"), *NamespacedSlotId, *SavedUserAuthDataPath,
		       *JsonSerializedAuthData);
	}

	// Save the User Account data to the slot.
	const auto SavedUserAccountDataPath = GetSavedSlotAccountFilePath(NamespacedSlotId);
	const auto AccountDataForSlot = FUserSlotAccountData{
		User.GamerTag,
		User.Email
	};
	FString JsonSerializedAccountData;
	ensureAlways(FJsonObjectConverter::UStructToJsonObjectString(AccountDataForSlot, JsonSerializedAccountData));

	if (FFileHelper::SaveStringToFile(*JsonSerializedAccountData, *SavedUserAccountDataPath))
	{
		UE_LOG(LogBeamUserSlots, Verbose, TEXT("Saved User Slot - Account File!\nUSER_SLOT=%s\nFILE_PATH=%s\nFILE_CONTENTS=%s"), *NamespacedSlotId, *SavedUserAccountDataPath,
		       *JsonSerializedAccountData);
	}
	else
	{
		UE_LOG(LogBeamUserSlots, Error, TEXT("Failed to create Saved User Slot - Account File!\nUSER_SLOT=%s\nFILE_PATH=%s\nFILE_CONTENTS=%s"), *NamespacedSlotId, *SavedUserAccountDataPath,
		       *JsonSerializedAccountData);
	}

	return bWasAuthenticated;
}


void UBeamUserSlots::ClearUserAtSlot(FUserSlot SlotId, const EUserSlotClearedReason& Reason, const bool& bShouldRemoveSavedData, const UObject* CallingContext)
{
	const auto NamespacedSlotId = GetNamespacedSlotId(SlotId, CallingContext);
	if (FBeamRealmUser ClearedUserData; GetUserDataAtSlot(SlotId, ClearedUserData, CallingContext))
	{
		// Clear serialized data
		if (bShouldRemoveSavedData)
		{
			// Save the User's Auth data to the slot.
			const auto SavedUserAuthDataPath = GetSavedSlotAuthFilePath(NamespacedSlotId);
			const auto AuthDataForSlot = FUserSlotAuthData{TEXT(""), TEXT(""), 0, TEXT(""),TEXT("")};
			FString JsonSerializedAuthData;
			ensureAlways(FJsonObjectConverter::UStructToJsonObjectString(AuthDataForSlot, JsonSerializedAuthData));

			if (FFileHelper::SaveStringToFile(*JsonSerializedAuthData, *SavedUserAuthDataPath))
			{
				UE_LOG(LogBeamUserSlots, Verbose, TEXT("Cleared User Slot - Auth File!\nUSER_SLOT=%s\nFILE_PATH=%s\nFILE_CONTENTS=%s"), *NamespacedSlotId, *SavedUserAuthDataPath,
				       *JsonSerializedAuthData);
			}
			else
			{
				UE_LOG(LogBeamUserSlots, Error, TEXT("Failed to clear User Slot - Auth File!\nUSER_SLOT=%s\nFILE_PATH=%s\nFILE_CONTENTS=%s"), *NamespacedSlotId, *SavedUserAuthDataPath,
				       *JsonSerializedAuthData);
			}

			// Save the User Account data to the slot.
			const auto SavedUserAccountDataPath = GetSavedSlotAccountFilePath(NamespacedSlotId);

			const auto AccountDataForSlot = FUserSlotAccountData{-1, TEXT("")};
			FString JsonSerializedAccountData;
			ensureAlways(FJsonObjectConverter::UStructToJsonObjectString(AccountDataForSlot, JsonSerializedAccountData));

			if (FFileHelper::SaveStringToFile(*JsonSerializedAccountData, *SavedUserAccountDataPath))
			{
				UE_LOG(LogBeamUserSlots, Verbose, TEXT("Cleared User Slot - Account File!\nUSER_SLOT=%s\nFILE_PATH=%s\nFILE_CONTENTS=%s"), *NamespacedSlotId, *SavedUserAccountDataPath,
				       *JsonSerializedAccountData);
			}
			else
			{
				UE_LOG(LogBeamUserSlots, Error, TEXT("Failed to clear User Slot - Account File!\nUSER_SLOT=%s\nFILE_PATH=%s\nFILE_CONTENTS=%s"), *NamespacedSlotId, *SavedUserAccountDataPath,
				       *JsonSerializedAccountData);
			}

			UE_LOG(LogBeamUserSlots, Verbose, TEXT("Cleared Saved User Slot!\nUSER_SLOT=%s"), *SlotId.Name);
		}

		// Remove Slot from list of loaded slots
		const auto LoadedAtIdx = AuthenticatedUserMapping.FindChecked(NamespacedSlotId);
		AuthenticatedUsers.RemoveAt(LoadedAtIdx);
		AuthenticatedUserMapping.Remove(NamespacedSlotId);

		// Broadcast events
		GlobalUserSlotClearedCodeHandler.Broadcast(Reason, SlotId, ClearedUserData, CallingContext);
		GlobalUserSlotClearedHandler.Broadcast(Reason, SlotId, ClearedUserData, CallingContext);

		UE_LOG(LogBeamUserSlots, Verbose, TEXT("Cleared Authenticated User at Slot!\nUSER_SLOT=%s"), *NamespacedSlotId);
	}
	else
	{
		UE_LOG(LogBeamUserSlots, Verbose, TEXT("No Authenticated User is loaded at Slot!\nUSER_SLOT=%s"), *NamespacedSlotId);
	}
}


bool UBeamUserSlots::TryLoadSavedUserAtSlot(FUserSlot SlotId, UObject* CallingContext)
{
	FString NamespacedSlotId = GetNamespacedSlotId(SlotId, CallingContext);

	FString SlotAuthFile;
	FString SlotAccountFile;
	const auto SavedAuthDataPath = GetSavedSlotAuthFilePath(NamespacedSlotId);
	const auto SavedAccountDataPath = GetSavedSlotAccountFilePath(NamespacedSlotId);

	bool bLoadedAuthFile = FFileHelper::LoadFileToString(SlotAuthFile, *SavedAuthDataPath);
	bool bLoadedAccountFile = FFileHelper::LoadFileToString(SlotAccountFile, *SavedAccountDataPath);

	// Both files must be there for us to be considered authenticated.
	// If they are not, we'll force the user to re-authenticate.
	if (bLoadedAuthFile && bLoadedAccountFile)
	{
		// We try to deserialize the user slot data
		FUserSlotAuthData SlotSerializedAuthData;
		const auto DidDeserializeAuthData = FJsonObjectConverter::JsonObjectStringToUStruct(SlotAuthFile, &SlotSerializedAuthData);
		ensureAlwaysMsgf(DidDeserializeAuthData, TEXT("Failed deserialization of %s_Auth.json file.\nPath=%s"), *NamespacedSlotId, *SavedAuthDataPath);

		// If the refresh token is there, we can do a quick authentication. 
		if (!SlotSerializedAuthData.RefreshToken.IsEmpty())
		{
			const auto AccessToken = SlotSerializedAuthData.AccessToken;
			const auto RefreshToken = SlotSerializedAuthData.RefreshToken;
			const auto ExpiresIn = SlotSerializedAuthData.ExpiresIn;
			const auto Cid = SlotSerializedAuthData.Cid;
			const auto Pid = SlotSerializedAuthData.Pid;
			
			// We only consider ourselves authenticated if the realm is the same as it was saved.
			// TODO: we might want to consider saving the auth data as a JSON Array of FUserSlotAuthData per slot and keeping auth data for each CID/PID... for now,
			// TODO: we'll just overwrite whenever a realm change happens.			
			const auto TargetRealm = GetDefault<UBeamCoreSettings>()->TargetRealm;
			if(SlotSerializedAuthData.Cid.Equals(TargetRealm.Cid) && SlotSerializedAuthData.Pid.Equals(TargetRealm.Pid))
			{
				// We try to deserialize the user slot data
				FUserSlotAccountData SlotSerializedAccountData;
				const auto DidDeserializeAccountData = FJsonObjectConverter::JsonObjectStringToUStruct(SlotAccountFile, &SlotSerializedAccountData);
				ensureAlwaysMsgf(DidDeserializeAccountData, TEXT("Failed deserialization of %s_Account.json file.\nPath=%s"), *NamespacedSlotId, *SavedAccountDataPath);

				SetAuthenticationDataAtSlot(SlotId, AccessToken, RefreshToken, ExpiresIn, Cid, Pid, CallingContext);
				SetGamerTagAtSlot(SlotId, SlotSerializedAccountData.GamerTag, CallingContext);
				SetEmailAtSlot(SlotId, SlotSerializedAccountData.Email, CallingContext);
				TriggerUserAuthenticatedIntoSlot(SlotId, CallingContext);

				UE_LOG(LogBeamUserSlots, Verbose, TEXT("Loaded user saved at slot!\nUSER_SLOT=%s, CID=%s, PID=%s"), *NamespacedSlotId, *Cid, *Pid);
				return true;
			}

			UE_LOG(LogBeamUserSlots, Warning, TEXT("Failed to load user saved at slot!\nUSER_SLOT=%s, CID=%s, PID=%s, TARGET_CID=%s, TARGET_PID=%s"), *NamespacedSlotId, *Cid, *Pid,
				*TargetRealm.Cid, *TargetRealm.Pid);
		}


		// If the refresh token ISN'T there OR if we are now attempting sign-in into a different realm, we fail the fast path for authentication of the user slot. 
		UE_LOG(LogBeamUserSlots, Verbose, TEXT("Invalid user saved at slot!\nUSER_SLOT=%s."), *NamespacedSlotId);
		return false;
	}
	
	UE_LOG(LogBeamUserSlots, Verbose, TEXT("No user saved at slot!\nUSER_SLOT=%s."), *NamespacedSlotId);
	return false;
}

template <typename T>
bool UBeamUserSlots::TryLoadSlotData(FString SlotDataTypeName, FUserSlot SlotId, T& OutSlotData, UObject* CallingContext) const
{
	const auto NamespacedSlotId = GetNamespacedSlotId(SlotId, CallingContext);
	const auto FilePath = GetSlotDataSavedFilePath(SlotDataTypeName, SlotId, CallingContext);
	FString SlotFile;
	if (FFileHelper::LoadFileToString(SlotFile, *FilePath))
	{
		const auto DidDeserializeAuthData = FJsonObjectConverter::JsonObjectStringToUStruct(SlotFile, &OutSlotData);
		ensureAlwaysMsgf(DidDeserializeAuthData, TEXT("Failed deserialization of %s_%s.json file.\nPath=%s"), *NamespacedSlotId, *FilePath);
		return true;
	}
	return false;
}

template <typename T>
bool UBeamUserSlots::SaveSlotData(FString SlotDataTypeName, FUserSlot SlotId, T SlotData, const UObject* CallingContext)
{
	const auto NamespacedSlotId = GetNamespacedSlotId(SlotId, CallingContext);

	FBeamRealmUser User;
	const auto bWasAuthenticated = GetUserDataAtSlot(SlotId, User, CallingContext);

#if !WITH_EDITOR
		ensureAlwaysMsgf(!Pid.IsEmpty(), TEXT("Customer-Scoped Tokens are not allowed in builds! If should never be seeing this!"))
#endif

	// Save the User's Auth data to the slot.
	const auto SavedSlotDataPath = GetSlotDataSavedFilePath(SlotDataTypeName, SlotId, CallingContext);
	FString JsonSerializedSlotData;
	ensureAlways(FJsonObjectConverter::UStructToJsonObjectString(SlotData, JsonSerializedSlotData));

	if (!bWasAuthenticated)
	{
		UE_LOG(LogBeamUserSlots, Warning,
		       TEXT("Failed to create Saved User Slot - %s File! Must be authenticated in a slot in order to save data with it.\nUSER_SLOT=%s\nFILE_PATH=%s\nFILE_CONTENTS=%s"),
		       *SlotDataTypeName, *NamespacedSlotId, *SavedSlotDataPath, *JsonSerializedSlotData)
		return false;
	}

	if (FFileHelper::SaveStringToFile(*JsonSerializedSlotData, *SavedSlotDataPath))
	{
		UE_LOG(LogBeamUserSlots, Verbose, TEXT("Saved User Slot - %s File!\nUSER_SLOT=%s\nFILE_PATH=%s\nFILE_CONTENTS=%s"),
		       *SlotDataTypeName, *NamespacedSlotId, *SavedSlotDataPath, *JsonSerializedSlotData);
	}
	else
	{
		UE_LOG(LogBeamUserSlots, Error, TEXT("Failed to create Saved User Slot - %s File!\nUSER_SLOT=%s\nFILE_PATH=%s\nFILE_CONTENTS=%s"),
		       *SlotDataTypeName, *NamespacedSlotId, *SavedSlotDataPath, *JsonSerializedSlotData);
	}

	return bWasAuthenticated;
}

// TODO: Declare all specializations here.
