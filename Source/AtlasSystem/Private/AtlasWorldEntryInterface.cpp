// Fill out your copyright notice in the Description page of Project Settings.

#include "AtlasWorldEntryInterface.h"
#include "AtlasSystem.h"
#include "GameFramework/PlayerController.h"
#include "AtlasWorldEntryWidget.h"

// Add default functionality here for any IAtlasWorldEntryInterface functions that are not pure virtual.

UAtlasWorldEntryComponent* IAtlasWorldEntryInterface::GetWorldEntryComponent_Implementation() const
{
	UE_LOG(LogAtlas, Error, TEXT("GetWorldEntryComponent not implemented"));
	return nullptr;
}

UAtlasWorldEntryWidget* IAtlasWorldEntryInterface::GetEntryWidget_Implementation(APlayerController* Controller) const
{
	UE_LOG(LogAtlas, Error, TEXT("GetEntryWidget not implemented"));
	return nullptr;
}