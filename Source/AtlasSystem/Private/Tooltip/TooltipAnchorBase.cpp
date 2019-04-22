// Fill out your copyright notice in the Description page of Project Settings.


#include "TooltipAnchorBase.h"
#include "AtlasSystem.h"

FVector2D UTooltipAnchorBase::GetPositionFromDirection_Implementation(const FVector2D& Direction) const
{
	UE_LOG(LogAtlas, Warning, TEXT("GetPositionFromDirection() not implemented"));
	return FVector2D::ZeroVector;
}