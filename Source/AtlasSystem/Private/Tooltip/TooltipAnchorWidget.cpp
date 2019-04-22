// Fill out your copyright notice in the Description page of Project Settings.


#include "TooltipAnchorWidget.h"
#include "SlateBlueprintLibrary.h"
#include "Blueprint/UserWidget.h"


FVector2D UTooltipAnchorWidget::GetPositionFromDirection_Implementation(const FVector2D& Direction) const
{
	const FGeometry& Geometry = AnchorWidget->GetCachedGeometry();

	// Get Center of Anchor Widget in Viewport Space
	FVector2D PixelPosition;
	FVector2D ViewportPosition;
	USlateBlueprintLibrary::LocalToViewport(GetWorld(), Geometry, Geometry.GetLocalSize() * 0.5, PixelPosition, ViewportPosition);

	// calculate Vector from center to requested corner
	float AnchorBoundsRadius = Geometry.GetAbsoluteSize().Size();
	FVector2D CenterOffset = Direction.GetSafeNormal() * AnchorBoundsRadius;

	return ViewportPosition + CenterOffset;
}