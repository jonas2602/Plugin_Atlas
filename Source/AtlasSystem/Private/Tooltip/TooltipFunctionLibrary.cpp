// Fill out your copyright notice in the Description page of Project Settings.


#include "TooltipFunctionLibrary.h"
#include "TooltipWidgetBase.h"
#include "BorderedTooltipWidget.h"
#include "TooltipAnchorActor.h"
#include "TooltipAnchorWidget.h"
#include "AtlasSystem.h"

#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

UTooltipWidgetBase* UTooltipFunctionLibrary::CreateTooltipForActor(UUserWidget* TooltipContent, APlayerController* OwningPlayer, AActor* AnchorActor, TSubclassOf<UTooltipWidgetBase> TooltipClass, ETooltipAlignment AlignmentType, ETooltipAnchor AnchorType)
{
	if (!TooltipContent)
	{
		UE_LOG(LogAtlas, Warning, TEXT("Tooltip Content not valid in CreateTooltipForActor()"));
		return nullptr;
	}

	if (!TooltipClass) 
	{
		TooltipClass = UBorderedTooltipWidget::StaticClass();
	}

	// Create Widget
	UTooltipWidgetBase* TooltipWidget = CreateWidget<UTooltipWidgetBase>(OwningPlayer, TooltipClass);

	// Create Anchor
	UTooltipAnchorActor* Anchor = NewObject<UTooltipAnchorActor>(TooltipWidget);
	Anchor->SetOwningPlayer(OwningPlayer);
	Anchor->SetAnchorActor(AnchorActor);

	// Init Widget
	TooltipWidget->SetTooltipContent(TooltipContent);
	TooltipWidget->SetTooltipAnchor(Anchor);
	TooltipWidget->SetAlignmentType(AlignmentType);
	TooltipWidget->SetAnchorType(AnchorType);

	TooltipWidget->AddToViewport();
	return TooltipWidget;
}

UTooltipWidgetBase* UTooltipFunctionLibrary::CreateTooltipForWidget(UUserWidget* TooltipContent, APlayerController* OwningPlayer, UUserWidget* AnchorWidget, TSubclassOf<UTooltipWidgetBase> TooltipClass, ETooltipAlignment AlignmentType, ETooltipAnchor AnchorType)
{
	if (!TooltipContent)
	{
		UE_LOG(LogAtlas, Warning, TEXT("Tooltip Content not valid in CreateTooltipForWidget()"));
		return nullptr;
	}

	if (!TooltipClass)
	{
		TooltipClass = UBorderedTooltipWidget::StaticClass();
	}

	// Create Widget
	UTooltipWidgetBase* TooltipWidget = CreateWidget<UTooltipWidgetBase>(OwningPlayer, TooltipClass);

	// Create Anchor
	UTooltipAnchorWidget* Anchor = NewObject<UTooltipAnchorWidget>(TooltipWidget);
	Anchor->SetOwningPlayer(OwningPlayer);
	Anchor->SetAnchorWidget(AnchorWidget);

	// Init Widget
	TooltipWidget->SetTooltipContent(TooltipContent);
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