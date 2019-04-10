// Fill out your copyright notice in the Description page of Project Settings.

#include "AtlasWorldEntryWidget.h"
#include "AtlasWorldEntryComponent.h"
#include "AtlasStorageEntry.h"

bool UAtlasWorldEntryWidget::ConnectStorageEntry(UAtlasStorageEntry* StorageEntry)
{
	// Valid Storage Entry?
	if (!StorageEntry) return false;

	// Set References to WorldEntry
	this->StorageEntry = StorageEntry;

	// Bind Delegates + Initialize Values
	StorageEntry->OnTransformChanged.AddDynamic(this, &UAtlasWorldEntryWidget::OnStorageTransformChanged);
	StorageEntry->OnStateChanged.AddDynamic(this, &UAtlasWorldEntryWidget::OnStorageStateChanged);

	OnStorageTransformChanged(StorageEntry->GetEntryTransform());
	OnStorageStateChanged();


	return true;
}

void UAtlasWorldEntryWidget::OnStorageTransformChanged_Implementation(const FTransform& Transform)
{
	OnDesiredTransformChanged.Broadcast(this, Transform);
}

void UAtlasWorldEntryWidget::OnStorageStateChanged_Implementation()
{

}