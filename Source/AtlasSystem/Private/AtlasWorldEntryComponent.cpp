// Fill out your copyright notice in the Description page of Project Settings.

#include "AtlasWorldEntryComponent.h"
#include "AtlasWorldEntryWidget.h"
#include "AtlasStorageEntry.h"
#include "AtlasSystem.h"
#include "AtlasBlueprintLibrary.h"
#include "AtlasStorage.h"


UAtlasWorldEntryComponent::UAtlasWorldEntryComponent()
{
	//StorageTemplate = NewObject<UAtlasStorageEntry>();
}

// Called when the game starts
void UAtlasWorldEntryComponent::BeginPlay()
{
	Super::BeginPlay();

	if (!StorageTemplate)
	{
		UE_LOG(LogAtlas, Warning, TEXT("Storage Template not setup on %s"), *GetOwner()->GetName());
		return;
	}

	// Initialize StorageEntry
	StorageTemplate->SetEntryTransform(GetComponentTransform());

	// Register Entry in AtlasStorage
	AAtlasStorage* Storage = UAtlasBlueprintLibrary::GetAtlasStorage(GetWorld());
	StorageTemplate->SetReferenceActor(GetOwner());
	Storage->RegisterEntry(StorageTemplate);

	// Create Widget in WorldSpace
	CreateWorldEntry();
}

void UAtlasWorldEntryComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	// Remove Entry from AtlasStorage
	AAtlasStorage* Storage = UAtlasBlueprintLibrary::GetAtlasStorage(GetWorld());
	Storage->UnregisterEntry(StorageTemplate);

	Super::EndPlay(EndPlayReason);
}

void UAtlasWorldEntryComponent::CreateWorldEntry_Implementation()
{
	// Valid Widget Class?
	TSubclassOf<UAtlasWorldEntryWidget> WidgetClass = StorageTemplate->GetEntryWidgetClass();
	if (!WidgetClass) return;

	// Try create Widget Instance
	UAtlasWorldEntryWidget* EntryWidget = CreateWidget<UAtlasWorldEntryWidget>(GetWorld(), WidgetClass);
	if (!EntryWidget) return;

	// Setup Widget in World
	SetWidget(EntryWidget);
	EntryWidget->ConnectStorageEntry(StorageTemplate);
}

void UAtlasWorldEntryComponent::OnUpdateTransform(EUpdateTransformFlags UpdateTransformFlags, ETeleportType Teleport)
{
	Super::OnUpdateTransform(UpdateTransformFlags, Teleport);

	if (StorageTemplate)
	{
		StorageTemplate->SetEntryTransform(GetComponentTransform());
	}
}