﻿#include "BeamableCoreEditor.h"

#include "BeamableCoreEditorCommands.h"
#include "BeamEditorSettings.h"
#include "BeamableCoreGraphWidgetFactory.h"
#include "BeamableCoreStyle.h"
#include "BeamableEditorBlueprintLibrary.h"
#include "LevelEditor.h"
#include "PropertyType/RequestTypeCustomization.h"
#include "Subsystems/BeamEditor.h"

#define LOCTEXT_NAMESPACE "FBeamableCoreEditorModule"

void FBeamableCoreEditorModule::StartupModule()
{
	// create your factories and shared pointer to them.
	TSharedPtr<FBeamableCorePinFactory> PinFactory = MakeShareable(new FBeamableCorePinFactory());
	TSharedPtr<FBeamableCoreGraphNodeFactory> NodeFactory = MakeShareable(new FBeamableCoreGraphNodeFactory());

	// and now register them.
	FEdGraphUtilities::RegisterVisualPinFactory(PinFactory);
	FEdGraphUtilities::RegisterVisualNodeFactory(NodeFactory);

	FBeamableCoreEditorCommands::Register();

	PluginCommands = MakeShareable(new FUICommandList);
	PluginCommands->MapAction(
		FBeamableCoreEditorCommands::Get().OpenBeamableWindowCommand,
		FExecuteAction::CreateRaw(this, &FBeamableCoreEditorModule::OpenMainBeamableWindow)
	);

	auto& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	const TSharedPtr<FExtender> NewToolbarExtender = MakeShareable<FExtender>(new FExtender());
	NewToolbarExtender->AddToolBarExtension("ProjectSettings", EExtensionHook::Before,
	                                        PluginCommands, FToolBarExtensionDelegate::CreateStatic(&FBeamableCoreEditorModule::AddBeamableButtons));

	LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(NewToolbarExtender);

	// Set up PropertyCustomizations
	{
		FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
		// to register our custom property
		PropertyModule.RegisterCustomPropertyTypeLayout(
			// This is the name of the Struct this tells the property editor which is the struct property our customization will applied on.
			FRequestType::StaticStruct()->GetFName(),
			// this is where our MakeInstance() method is useful
			FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FRequestTypeCustomization::MakeInstance));

		PropertyModule.NotifyCustomizationModuleChanged();
	}
}

void FBeamableCoreEditorModule::ShutdownModule()
{
	FBeamableCoreEditorCommands::Unregister();

	// Clean up PropertyCustomizations
	if (FModuleManager::Get().IsModuleLoaded("PropertyEditor"))
	{
		// unregister properties when the module is shutdown
		FPropertyEditorModule& PropertyModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
		PropertyModule.UnregisterCustomPropertyTypeLayout(FRequestType::StaticStruct()->GetFName());

		
		PropertyModule.NotifyCustomizationModuleChanged();
	}
}

void FBeamableCoreEditorModule::AddBeamableButtons(FToolBarBuilder& Builder)
{
	Builder.AddToolBarButton(FBeamableCoreEditorCommands::Get().OpenBeamableWindowCommand);
}

void FBeamableCoreEditorModule::OpenMainBeamableWindow() const
{
	UBeamableEditorBlueprintLibrary::StartWidget(GetDefault<UBeamEditorSettings>()->BeamableMainWindow.Get());
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FBeamableCoreEditorModule, BeamableCoreEditor)
