// Fill out your copyright notice in the Description page of Project Settings.

#include "AtlasWorldEntryWidget.h"
#include "AtlasWorldEntryComponent.h"

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

void UAtlasWorldEntryWidget::OnWorldTransformChanged_Implementation(const FTransform& Transform)
{

}

void UAtlasWorldEntryWidget::OnWorldEntryChanged_Implementation()
{

}