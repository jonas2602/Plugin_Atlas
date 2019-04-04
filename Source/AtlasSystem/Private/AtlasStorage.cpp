// Fill out your copyright notice in the Description page of Project Settings.

#include "AtlasStorage.h"
#include "AtlasBase.h"
#include "AtlasWorldEntryInterface.h"

#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AAtlasStorage::AAtlasStorage()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAtlasStorage::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AAtlasStorage::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AAtlasStorage::RegisterWorldEntry(AActor* WorldEntry)
{
	// Is World Entry?
	if (!WorldEntry || !WorldEntry->Implements<UAtlasWorldEntryInterface>())
	{
		return false;
	}

	// Successfully added?
	if (WorldEntryList.AddUnique(WorldEntry) == -1)
	{
		return false;
	}

	OnEntryAdded.Broadcast(WorldEntry);
	return true;
}

bool AAtlasStorage::UnregisterWorldEntry(AActor* WorldEntry)
{
	if (WorldEntryList.Remove(WorldEntry) == 0)
	{
		return false;
	}

	OnEntryRemoved.Broadcast(WorldEntry);
	return true;
}

bool AAtlasStorage::RegisterAtlas(UAtlasBase* Atlas)
{
	if (AtlasList.AddUnique(Atlas) == -1)
	{
		return false;
	}

	return true;
}

bool AAtlasStorage::UnregisterAtlas(UAtlasBase* Atlas)
{
	return AtlasList.Remove(Atlas) > 0;
}

