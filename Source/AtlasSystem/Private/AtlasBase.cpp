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
	Storage->OnEntryAdded.AddDynamic(this, &UAtlasBase::AddWorldEntry);
	Storage->OnEntryRemoved.AddDynamic(this, &UAtlasBase::RemoveWorldEntry);
	Storage->OnStorageEntryAdded.AddDynamic(this, &UAtlasBase::AddEntry);
	Storage->OnStorageEntryRemoved.AddDynamic(this, &UAtlasBase::RemoveEntry);

	for (AActor* WorldEntry : Storage->GetWorldEntries())
	{
		AddWorldEntry(WorldEntry);
	}

	for (UAtlasStorageEntry* Entry : Storage->GetStorageEntries())
	{
		AddEntry(Entry);
	}
}

//void UAtlasBase::AddWorldEntry(AActor* WorldEntry)
//{
//	TSubclassOf<UAtlasWorldEntryWidget> WidgetClass = IAtlasWorldEntryInterface::Execute_GetEntryWidgetClass(WorldEntry);
//	if (!WidgetClass)
//	{
//		UE_LOG(LogAtlas, Error, TEXT("Can't create EntryWidget of invalid class"));
//		return;
//	}
//
//	UAtlasWorldEntryWidget* EntryWidget = CreateWidget<UAtlasWorldEntryWidget>(GetOwningPlayer(), WidgetClass);
//	if (!EntryWidget)
//	{
//		return;
//	}
//
//	WorldEntryMap.Add(WorldEntry, EntryWidget);
//}
//
//void UAtlasBase::RemoveWorldEntry(AActor* WorldEntry)
//{
//
//}
