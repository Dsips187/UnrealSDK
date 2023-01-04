﻿using UnrealBuildTool;

public class BeamableCoreEditor : ModuleRules
{
	public BeamableCoreEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"Engine",
				"CoreUObject",
				"BeamableCore",
				"UnrealEd",
				"SlateCore",
				"Slate",
				"EditorStyle",
				"Kismet",
				"KismetCompiler",
				"BeamableCoreBlueprintNodes",
				"Projects", // Required to use IPluginManager in order to configure new Slate styles
				"ToolMenus",
				"ToolMenusEditor", 
				"UMGEditor",
				"DeveloperSettings",
				"EditorSubsystem",
	
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"BlueprintGraph",
				"GraphEditor",
				"LevelEditor",
				"PropertyEditor",
				"UMGEditor", 
				"Blutility",
			}
		);
	}
}