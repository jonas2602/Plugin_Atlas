// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TooltipTypes.h"
#include "TooltipFunctionLibrary.generated.h"

/**
 * 
 */

class UTooltipWidgetBase;

UCLASS()
class ATLASSYSTEM_API UTooltipFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "AlignmentType, AnchorType, TooltipClass"), Category = "Tooltip")
	static UTooltipWidgetBase* CreateTooltipForActor(UUserWidget* TooltipContent, APlayerController* OwningPlayer, AActor* AnchorActor, TSubclassOf<UTooltipWidgetBase> TooltipClass, ETooltipAlignment AlignmentType = ETooltipAlignment::UpperRight, ETooltipAnchor AnchorType = ETooltipAnchor::Cursor);

	UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "AlignmentType, AnchorType"), Category = "Tooltip")
	static UTooltipWidgetBase* CreateTooltipForWidget(UUserWidget* TooltipContent, APlayerController* OwningPlayer, UUserWidget* AnchorWidget, TSubclassOf<UTooltipWidgetBase> TooltipClass, ETooltipAlignment AlignmentType = ETooltipAlignment::UpperRight, ETooltipAnchor AnchorType = ETooltipAnchor::Cursor);
	
	UFUNCTION(BlueprintCallable, Category = "Tooltip")
	static void DestroyTooltip(UTooltipWidgetBase* Tooltip);
};
