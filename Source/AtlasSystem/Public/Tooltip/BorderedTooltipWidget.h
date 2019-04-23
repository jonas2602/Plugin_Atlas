// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tooltip/TooltipWidgetBase.h"
#include "BorderedTooltipWidget.generated.h"

/**
 * 
 */

class UBorder;

UCLASS(BlueprintType, Blueprintable)
class ATLASSYSTEM_API UBorderedTooltipWidget : public UTooltipWidgetBase
{
	GENERATED_BODY()

public:
	// UUserWidget interface
	virtual TSharedRef<SWidget> RebuildWidget() override;
	// End of UUserWidget interface

public:
	virtual void SetTooltipContent_Implementation(UUserWidget* Content) override;

protected:
	UBorder* TooltipBorder;
	UUserWidget* TooltipContent;
};
