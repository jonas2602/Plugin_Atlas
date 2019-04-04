// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class Plugin_AtlasTarget : TargetRules
{
	public Plugin_AtlasTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "Plugin_Atlas", "AtlasSystem" } );
	}
}
