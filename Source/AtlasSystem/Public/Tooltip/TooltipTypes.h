// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TooltipTypes.generated.h"

UENUM(BlueprintType)
enum class ETooltipAlignment : uint8
{
	UpperRight,
	UpperLeft,
	LowerRight,
	LowerLeft,
};

UENUM(BlueprintType)
enum class ETooltipAnchor : uint8
{
	Cursor, // Tooltip Clipped to the Cursor, can move along the Y-Axis of the Cursor
	Entry,	// Tooltip Sticks to the Corners of the given Entry
};


/**
 * 
 */
//UCLASS()
//class ATLASSYSTEM_API UTooltipTypes : public UObject
//{
//	GENERATED_BODY()
//	
//};
