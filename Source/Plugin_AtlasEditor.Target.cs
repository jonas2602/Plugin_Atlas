// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class Plugin_AtlasEditorTarget : TargetRules
{
	public Plugin_AtlasEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "Plugin_Atlas", "AtlasSystem" } );
	}
}
