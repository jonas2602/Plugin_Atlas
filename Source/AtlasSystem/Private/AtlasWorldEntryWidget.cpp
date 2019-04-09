// Fill out your copyright notice in the Description page of Project Settings.

#include "AtlasWorldEntryWidget.h"
#include "AtlasWorldEntryComponent.h"
#include "AtlasStorageEntry.h"

bool UAtlasWorldEntryWidget::ConnectWorldEntry(AActor* Actor)
{
	// Valid Actor?
	if (!Actor) return false;

	// Has Entry Component?
	UAtlasWorldEntryComponent* Component = Cast<UAtlasWorldEntryComponent>(Actor->GetComponentByClass(UAtlasWorldEntryComponent::StaticClass()));
	if (!Component)
	{
		return false;
	}

	// Set References to WorldEntry
	WorldEntryActor = Actor;
	WorldEntryComponent = Component;

	// Bind Delegates + Initialize Values
	WorldEntryComponent->OnWorldTransformChanged.AddDynamic(this, &UAtlasWorldEntryWidget::OnWorldTransformChanged);
	WorldEntryComponent->OnWorldEntryChanged.AddDynamic(this, &UAtlasWorldEntryWidget::OnWorldEntryChanged);
	
	OnWorldTransformChanged(WorldEntryComponent->GetComponentTransform());
	OnWorldEntryChanged();


	return true;
}

bool UAtlasWorldEntryWidget::ConnectEntry(UAtlasStorageEntry* StorageEntry)
{
	// Valid Storage Entry?
	if (!StorageEntry) return false;

	// Has Entry Component?
	/*UAtlasWorldEntryComponent* Component = Cast<UAtlasWorldEntryComponent>(Actor->GetComponentByClass(UAtlasWorldEntryComponent::StaticClass()));
	if (!Component)
	{
		return false;
	}*/

	// Set References to WorldEntry
	this->StorageEntry = StorageEntry;

	// Bind Delegates + Initialize Values
	StorageEntry->OnTransformChanged.AddDynamic(this, &UAtlasWorldEntryWidget::OnWorldTransformChanged);
	StorageEntry->OnStateChanged.AddDynamic(this, &UAtlasWorldEntryWidget::OnWorldEntryChanged);

	OnWorldTransformChanged(StorageEntry->GetEntryTransform());
	OnWorldEntryChanged();


	return true;
}

void UAtlasWorldEntryWidget::OnWorldTransformChanged_Implementation(const FTransform& Transform)
{

}

void UAtlasWorldEntryWidget::OnWorldEntryChanged_Implementation()
{

}