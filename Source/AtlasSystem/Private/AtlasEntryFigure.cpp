// Fill out your copyright notice in the Description page of Project Settings.


#include "AtlasEntryFigure.h"
#include "AtlasStorageEntry.h"

// Sets default values
AAtlasEntryFigure::AAtlasEntryFigure()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

bool AAtlasEntryFigure::ConnectStorageEntry(UAtlasStorageEntry* StorageEntry)
{
	// Valid Storage Entry?
	if (!StorageEntry) return false;

	// Set References to WorldEntry
	this->StorageEntry = StorageEntry;

	// Bind Delegates + Initialize Values
	StorageEntry->OnTransformChanged.AddDynamic(this, &AAtlasEntryFigure::OnStorageTransformChanged);
	StorageEntry->OnStateChanged.AddDynamic(this, &AAtlasEntryFigure::OnStorageStateChanged);

	OnStorageTransformChanged(StorageEntry->GetEntryTransform());
	OnStorageStateChanged();


	return true;
}

void AAtlasEntryFigure::OnStorageTransformChanged_Implementation(const FTransform& Transform)
{
	OnDesiredTransformChanged.Broadcast(this, Transform);
}

void AAtlasEntryFigure::OnStorageStateChanged_Implementation()
{

}
