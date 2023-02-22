﻿#pragma once

#include "CoreMinimal.h"

class BEAMABLECOREEDITOR_API FBeamableCoreEditorModule : public IModuleInterface
{
public:
    
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

private:
    TSharedPtr<class FUICommandList> PluginCommands;
    FDelegateHandle LocalContentManifestDataTableHandler;

    void HandleAssetOpenedInEditor(UObject* Object, IAssetEditorInstance* AssetEditorInstance);

    static void AddBeamableButtons(FToolBarBuilder& Builder);
    void OpenMainBeamableWindow() const;
};
