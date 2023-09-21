// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class SentryPlaygroundEditorTarget : TargetRules
{
	public SentryPlaygroundEditorTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "SentryPlayground" } );

		bOverrideBuildEnvironment = true;

		if (Target.Version.MajorVersion == 5 && Target.Version.MinorVersion < 2)
		{
			bUsePCHFiles = false;
			bUseUnityBuild = false;
		}
	}
}
