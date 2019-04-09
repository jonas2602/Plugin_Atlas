// Fill out your copyright notice in the Description page of Project Settings.

#include "AtlasWorldEntryComponent.h"
#include "AtlasStorageEntry.h"
#include "AtlasSystem.h"


UAtlasWorldEntryComponent::UAtlasWorldEntryComponent()
{
	//StorageTemplate = NewObject<UAtlasStorageEntry>();
}

void UAtlasWorldEntryComponent::OnUpdateTransform(EUpdateTransformFlags UpdateTransformFlags, ETeleportType Teleport)
{
	Super::OnUpdateTransform(UpdateTransformFlags, Teleport);

	OnWorldTransformChanged.Broadcast(GetComponentTransform());

	if (StorageTemplate)
	{
		StorageTemplate->SetEntryTransform(GetComponentTransform());
	}
}

void UAtlasWorldEntryComponent::UpdateEntryWidget()
{
	OnWorldEntryChanged.Broadcast();
}