// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NZP_UnrealTarget : TargetRules
{
	public NZP_UnrealTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		
		DefaultBuildSettings = BuildSettingsVersion.V4;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_3;
		
		ExtraModuleNames.Add("NZP_Unreal");
	}
}