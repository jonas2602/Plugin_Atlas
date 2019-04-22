// Fill out your copyright notice in the Description page of Project Settings.


#include "AtlasStorageEntry.h"
#include "AtlasWorldEntryWidget.h"

// Sets default values for this component's properties
UAtlasStorageEntry::UAtlasStorageEntry()
{
	// ...
	// EntryWidgetClass = UAtlasWorldEntryWidget::StaticClass();
}

void UAtlasStorageEntry::SetEntryTransform(FTransform InTransform) 
{ 
	if (InTransform.Equals(EntryTransform)) return;

	EntryTransform = InTransform; 
	OnTransformChanged.Broadcast(InTransform);
}

void UAtlasStorageEntry::SetReferenceActor(AActor* InActor)
{
	this->ReferenceActor = InActor;
}