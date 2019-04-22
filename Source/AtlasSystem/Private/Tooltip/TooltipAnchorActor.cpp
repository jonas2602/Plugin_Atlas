// Fill out your copyright notice in the Description page of Project Settings.


#include "TooltipAnchorActor.h"

#include "WidgetLayoutLibrary.h"
#include "GameFramework/PlayerController.h"

FVector2D UTooltipAnchorActor::GetPositionFromDirection_Implementation(const FVector2D& Direction) const
{
	// Convert Viewport Direction to WorldDirection
	FVector WorldDirection = FVector(0, Direction.X, -Direction.Y);

	// Convert World Direction to Camera Space
	const FRotator& CameraRotation = OwningPlayer->PlayerCameraManager->GetCameraRotation();
	FVector CameraDirection = CameraRotation.RotateVector(WorldDirection);

	// Get Actor Origin + Extends
	FVector AnchorOrigin;
	FVector AnchorExtends;
	AnchorActor->GetActorBounds(false, AnchorOrigin, AnchorExtends);

	// Calculate Tooltip Position in WorldSpace
	FVector Offset = CameraDirection.GetSafeNormal() * AnchorExtends.Size();
	FVector WorldPosition = AnchorOrigin + Offset;

	// Transform World Position back to Viewport
	FVector2D ScreenPosition;
	UWidgetLayoutLibrary::ProjectWorldLocationToWidgetPosition(OwningPlayer, WorldPosition, ScreenPosition);

	return ScreenPosition;
}