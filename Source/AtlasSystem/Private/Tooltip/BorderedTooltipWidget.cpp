// Fill out your copyright notice in the Description page of Project Settings.


#include "BorderedTooltipWidget.h"
#include "Border.h"
#include "BorderSlot.h"
#include "WidgetTree.h"

TSharedRef<SWidget> UBorderedTooltipWidget::RebuildWidget()
{
	// Create Root Border if not already created
	TooltipBorder = Cast<UBorder>(GetRootWidget());
	if (!TooltipBorder)
	{
		TooltipBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("RootWidget"));
		TooltipBorder->SetPadding(FMargin());

		WidgetTree->RootWidget = TooltipBorder;
	}

	// Fill Border with Tooltip Content
	TooltipBorder->AddChild(TooltipContent);

	// ...
	TSharedRef<SWidget> Widget = Super::RebuildWidget();
	return Widget;
}

void UBorderedTooltipWidget::SetTooltipContent_Implementation(UUserWidget* Content)
{
	TooltipContent = Content;

	// In case Border already exists fill it directly
	if (TooltipBorder)
	{
		TooltipBorder->AddChild(Content);
	}
}
