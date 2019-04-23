// Fill out your copyright notice in the Description page of Project Settings.


#include "TooltipWidgetBase.h"
#include "WidgetLayoutLibrary.h"
#include "TooltipAnchorBase.h"
#include "AtlasSystem.h"

#include "Engine/World.h"
#include "TimerManager.h"

void UTooltipWidgetBase::NativeConstruct()
{
	Super::NativeConstruct();

	// Init Tooltip Position with delay of at least one frame because 
	// GetDesiredSize() only returns a valid size if the Widget was completly mounted in slate viewport
	FTimerHandle Timer;
	GetWorld()->GetTimerManager().SetTimer(Timer, this, &UTooltipWidgetBase::InitTooltip, 0.05f, false);

	// Keep the tooltip hidden for the meantime, because it would appear in the upper left corner otherwise
	SetVisibility(ESlateVisibility::Hidden);
}

void UTooltipWidgetBase::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (!TooltipAnchor)
	{
		UE_LOG(LogAtlas, Error, TEXT("Tooltip Anchor invalid. This should never happen!!!"));
		return;
	}

	UpdateGeometry();
}

void UTooltipWidgetBase::InitTooltip()
{
	SetVisibility(ESlateVisibility::HitTestInvisible);
	UpdateGeometry();
}

void UTooltipWidgetBase::UpdateGeometry()
{
	// Convert Enum to Vector2D
	FVector2D TargetDirection = AlignmentToDirection(AlignmentType);

	// Calculate position, alignment assuming that it will fit into the viewport
	FVector2D TargetPosition = PositionFromDirection(TargetDirection);
	FVector2D TargetAlignment = AlignmentFromDirection(TargetDirection);

	// Check offset in viewport and adjust if required
	FVector2D Offset = CalculateViewportOffset(TargetPosition, TargetAlignment, TargetDirection);
	FVector2D AdjustedDirection;
	if (AdjustDirectionByOffset(TargetDirection, Offset, AdjustedDirection))
	{
		// recalculate Position/Alignment with new Direction
		TargetPosition = PositionFromDirection(AdjustedDirection);
		TargetAlignment = AlignmentFromDirection(AdjustedDirection);

		// Clip to viewport if still overlapping
		TargetPosition = ClipToViewport(TargetPosition, TargetAlignment, AdjustedDirection);
	}

	// Finally change Widget properties
	SetPositionInViewport(TargetPosition, false);
	SetAlignmentInViewport(TargetAlignment);
}

void UTooltipWidgetBase::SetTooltipContent_Implementation(UUserWidget* Content)
{
	UE_LOG(LogAtlas, Error, TEXT("SetTooltipContent() not implemented on %s"), *GetName());
}

FVector2D UTooltipWidgetBase::AlignmentToDirection(ETooltipAlignment AlignmentType) const
{
	switch (AlignmentType) {
		case ETooltipAlignment::UpperRight:	return FVector2D(1.0, -1.0);
		case ETooltipAlignment::UpperLeft:	return FVector2D(-1.0, -1.0);
		case ETooltipAlignment::LowerRight: return FVector2D(1.0, 1.0);
		case ETooltipAlignment::LowerLeft:	return FVector2D(-1.0, 1.0);
		default: {
			UE_LOG(LogAtlas, Error, TEXT("Unexpected Tooltip Alignment Type"));
			return FVector2D::ZeroVector;
		}
	}
}

FVector2D UTooltipWidgetBase::PositionFromDirection(const FVector2D& Direction) const
{
	switch (AnchorType) {
		case ETooltipAnchor::Cursor:
		{
			FVector2D MousePosition = UWidgetLayoutLibrary::GetMousePositionOnViewport(GetWorld());
			float NewY = MousePosition.Y + CursorHalfHeight + Direction.Y * CursorHalfHeight;

			return FVector2D(MousePosition.X, NewY);
		}
		case ETooltipAnchor::Entry:
		{
			return TooltipAnchor->GetPositionFromDirection(Direction);
		}
		default: {
			UE_LOG(LogAtlas, Error, TEXT("Unexpected Tooltip Anchor Type"));
			return FVector2D::ZeroVector;
		}
	}
}

FVector2D UTooltipWidgetBase::AlignmentFromDirection(const FVector2D& Direction) const
{
	return Direction.ClampAxes(-1.0, 0.0) * -1.0;
}

FVector2D UTooltipWidgetBase::CalculateViewportOffset(const FVector2D& Position, const FVector2D& Alignment, const FVector2D& PriorityDirection) const
{
	FVector2D BoundsMin = Position - GetDesiredSize() * Alignment;
	FVector2D BoundsMax = Position + (FVector2D::UnitVector - Alignment) * GetDesiredSize();

	FVector2D OffsetNegative = FVector2D(FMath::Min(0.0f, BoundsMin.X), FMath::Min(0.0f, BoundsMin.Y));

	FVector2D ViewportSize = UWidgetLayoutLibrary::GetViewportSize(GetWorld()) / UWidgetLayoutLibrary::GetViewportScale(GetWorld());
	FVector2D OffsetPositive = FVector2D(FMath::Max(0.0f, (BoundsMax - ViewportSize).X), FMath::Max(0.0f, (BoundsMax - ViewportSize).Y));

	float OffsetX = PriorityDirection.X > 0.0
		? (OffsetPositive.X != 0.0 ? OffsetPositive.X : OffsetNegative.X)
		: (OffsetNegative.X != 0.0 ? OffsetNegative.X : OffsetPositive.X);

	float OffsetY = PriorityDirection.Y > 0.0
		? (OffsetPositive.Y != 0.0 ? OffsetPositive.Y : OffsetNegative.Y)
		: (OffsetNegative.Y != 0.0 ? OffsetNegative.Y : OffsetPositive.Y);

	return FVector2D(OffsetX, OffsetY);
}

bool UTooltipWidgetBase::AdjustDirectionByOffset(const FVector2D& TargetDirection, const FVector2D& Offset, FVector2D& OutDirection) const
{
	OutDirection = TargetDirection;
	bool bChanged = false;

	// Has Offset on X-Axis along the target direction?
	if (FMath::Sign(TargetDirection.X) == FMath::Sign(Offset.X) && Offset.X != 0.0)
	{
		// Flip X-Direction
		OutDirection.X = -TargetDirection.X;
		bChanged = true;
	}

	// Has Offset on Y-Axis along the target direction?
	if (FMath::Sign(TargetDirection.Y) == FMath::Sign(Offset.Y) && Offset.Y != 0.0)
	{
		// Flip Y-Direction
		OutDirection.Y = -TargetDirection.Y;
		bChanged = true;
	}

	return bChanged;
}

FVector2D UTooltipWidgetBase::ClipToViewport(const FVector2D& Position, const FVector2D& Alignment, const FVector2D& Direction) const
{
	FVector2D Offset = CalculateViewportOffset(Position, Alignment, Direction);
	return Position - Offset;
}