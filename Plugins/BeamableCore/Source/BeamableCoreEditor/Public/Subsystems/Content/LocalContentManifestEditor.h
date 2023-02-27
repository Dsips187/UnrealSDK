﻿#pragma once

#include "CoreMinimal.h"

#include "DataTableEditorUtils.h"
#include "BeamBackend/SemanticTypes/BeamContentId.h"
#include "BeamBackend/SemanticTypes/BeamContentManifestId.h"
#include "Content/BeamContentObject.h"
#include "Content/LocalContentManifestRow.h"
#include "Dialog/SCustomDialog.h"

#include "LocalContentManifestEditor.generated.h"

#define LOCTEXT_NAMESPACE "ULocalContentManifestEditorState"


class SNameComboBox;
class UBeamEditorContent;

UCLASS()
class ULocalContentManifestEditorState : public UObject, public FDataTableEditorUtils::FDataTableEditorManager::ListenerType
{
	GENERATED_BODY()

public:
	ULocalContentManifestEditorState() = default;

	FAssetEditorToolkit* Editor;

	UPROPERTY()
	UBeamEditorContent* EditorContentSystem;

	UPROPERTY()
	FBeamContentManifestId ManifestId;
	TSharedPtr<SNameComboBox> SelectedTypeComboBox;
	int SelectedTypeIdx = 0;

	UPROPERTY()
	UDataTable* EditingTable;
	TArray<TSharedPtr<FName>> EditingTableContentNames;
	TSharedPtr<SNameComboBox> SelectedContentComboBox;
	int SelectedContentIdx = 0;

	UPROPERTY()
	FBeamContentId EditingObjectId = FBeamContentId{};

	UPROPERTY()
	UBeamContentObject* EditingObject;
	TSharedPtr<SWindow> EditingWindow;
	TSharedPtr<IDetailsView> EditingObjectDetailsPanel;
	FDelegateHandle EditingObjectOnPropertyChangeHandle;

	TSharedPtr<SWindow> PublishingWindow;

	void PrepareEditingUI();

	void AddDataTableToolbarExtension(FToolBarBuilder& Builder);

	/** Implementation of FDataTableEditorManager::ListenerType --- needed to respond to selection and table data modifications */
	virtual void PreChange(const UDataTable* Changed, FDataTableEditorUtils::EDataTableChangeInfo ChangedType) override;
	virtual void PostChange(const UDataTable* Changed, FDataTableEditorUtils::EDataTableChangeInfo ChangedType) override;

	virtual void SelectionChange(const UDataTable* DataTable, FName RowName) override;
	void RebuildContentNamesForTable();

private:
	void AddContentButtonClicked();
	void EditContentButtonClicked();
	void PublishButtonClicked();

	UFUNCTION()
	void OnPublishEvent(const TArray<FUserSlot>& UserSlots, FBeamOperationEvent OperationEvent) const;
};

#undef LOCTEXT_NAMESPACE