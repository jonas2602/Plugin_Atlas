// Fill out your copyright notice in the Description page of Project Settings.

#include "AtlasWorldEntryComponent.h"
#include "AtlasSystem.h"

void UAtlasWorldEntryComponent::OnUpdateTransform(EUpdateTransformFlags UpdateTransformFlags, ETeleportType Teleport)
{
	Super::OnUpdateTransform(UpdateTransformFlags, Teleport);

	OnWorldTransformChanged.Broadcast(GetComponentTransform());
}

void UAtlasWorldEntryComponent::UpdateEntryWidget()
{
	OnWorldEntryChanged.Broadcast();
}