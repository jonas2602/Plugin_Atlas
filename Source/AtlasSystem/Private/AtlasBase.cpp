// Fill out your copyright notice in the Description page of Project Settings.

#include "AtlasBase.h"
#include "AtlasStorage.h"
#include "AtlasBlueprintLibrary.h"
#include "AtlasWorldEntryWidget.h"
#include "AtlasWorldEntryInterface.h"
#include "AtlasStorageEntry.h"
#include "AtlasSystem.h"

void UAtlasBase::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	Storage = UAtlasBlueprintLibrary::GetAtlasStorage(this);
	if (!Storage)
	{
		UE_LOG(LogAtlas, Error, TEXT("No Atlas Entry Storage found"));
		return;
	}

	Storage->RegisterAtlas(this);
	Storage->OnStorageEntryAdded.AddDynamic(this, &UAtlasBase::AddEntry);
	Storage->OnStorageEntryRemoved.AddDynamic(this, &UAtlasBase::RemoveEntry);

	for (UAtlasStorageEntry* Entry : Storage->GetStorageEntries())
	{
		AddEntry(Entry);
	}
}

void UAtlasBase::AddEntry_Implementation(UAtlasStorageEntry* StorageEntry)
{
	// Valid Widget Class?
	TSubclassOf<UAtlasWorldEntryWidget> WidgetClass = StorageEntry->GetEntryWidgetClass();
	if (!WidgetClass) return;

	// Try create Widget Instance
	UAtlasWorldEntryWidget* EntryWidget = CreateWidget<UAtlasWorldEntryWidget>(this, WidgetClass);
	if (!EntryWidget) return;

	// Setup Widget in Atlas
	StorageEntryMap.Add(StorageEntry, EntryWidget);
	SetupEntry(EntryWidget);
	EntryWidget->OnDesiredTransformChanged.AddDynamic(this, &UAtlasBase::OnStorageTransformChanged);
	EntryWidget->ConnectStorageEntry(StorageEntry);
}

void UAtlasBase::RemoveEntry_Implementation(UAtlasStorageEntry* StorageEntry)
{
	// Storage Entry is registered?
	UAtlasWorldEntryWidget* EntryWidget = StorageEntryMap.FindAndRemoveChecked(StorageEntry);
	if (!EntryWidget) return;

	// Unbind Delegates
	EntryWidget->OnDesiredTransformChanged.RemoveDynamic(this, &UAtlasBase::OnStorageTransformChanged);

	// Destroy Widget
	EntryWidget->RemoveFromViewport();
}
