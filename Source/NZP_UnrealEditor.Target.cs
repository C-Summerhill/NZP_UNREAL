// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NZP_UnrealEditorTarget : TargetRules
{
	public NZP_UnrealEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_2;
		ExtraModuleNames.Add("NZP_Unreal");
	}
}