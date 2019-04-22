// Fill out your copyright notice in the Description page of Project Settings.


#include "TooltipFunctionLibrary.h"
#include "TooltipWidgetBase.h"
#include "TooltipAnchorActor.h"
#include "TooltipAnchorWidget.h"
#include "AtlasSystem.h"

#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

UTooltipWidgetBase* UTooltipFunctionLibrary::CreateTooltipForActor(TSubclassOf<UTooltipWidgetBase> WidgetClass, APlayerController* OwningPlayer, AActor* AnchorActor, ETooltipAlignment AlignmentType, ETooltipAnchor AnchorType)
{
	if (!WidgetClass)
	{
		UE_LOG(LogAtlas, Warning, TEXT("Widget Class not valid in CreateTooltipForActor()"));
		return nullptr;
	}

	// Create Widget
	UTooltipWidgetBase* TooltipWidget = CreateWidget<UTooltipWidgetBase>(OwningPlayer, WidgetClass);

	// Create Anchor
	UTooltipAnchorActor* Anchor = NewObject<UTooltipAnchorActor>(TooltipWidget);
	Anchor->SetOwningPlayer(OwningPlayer);
	Anchor->SetAnchorActor(AnchorActor);

	// Init Widget
	TooltipWidget->SetTooltipAnchor(Anchor);
	TooltipWidget->SetAlignmentType(AlignmentType);
	TooltipWidget->SetAnchorType(AnchorType);

	TooltipWidget->AddToViewport();
	return TooltipWidget;
}

UTooltipWidgetBase* UTooltipFunctionLibrary::CreateTooltipForWidget(TSubclassOf<UTooltipWidgetBase> WidgetClass, APlayerController* OwningPlayer, UUserWidget* AnchorWidget, ETooltipAlignment AlignmentType, ETooltipAnchor AnchorType)
{
	if (!WidgetClass)
	{
		UE_LOG(LogAtlas, Warning, TEXT("Widget Class not valid in CreateTooltipForWidget()"));
		return nullptr;
	}

	// Create Widget
	UTooltipWidgetBase* TooltipWidget = CreateWidget<UTooltipWidgetBase>(OwningPlayer, WidgetClass);

	// Create Anchor
	UTooltipAnchorWidget* Anchor = NewObject<UTooltipAnchorWidget>(TooltipWidget);
	Anchor->SetOwningPlayer(OwningPlayer);
	Anchor->SetAnchorWidget(AnchorWidget);

	// Init Widget
	TooltipWidget->SetTooltipAnchor(Anchor);
	TooltipWidget->SetAlignmentType(AlignmentType);
	TooltipWidget->SetAnchorType(AnchorType);

	TooltipWidget->AddToViewport();
	return TooltipWidget;
}

void UTooltipFunctionLibrary::DestroyTooltip(UTooltipWidgetBase* Tooltip)
{
	if (!Tooltip) return;

	Tooltip->RemoveFromParent();
}