// Fill out your copyright notice in the Description page of Project Settings.

#include "AtlasBlueprintLibrary.h"
#include "AtlasStorage.h"

#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

AAtlasStorage* UAtlasBlueprintLibrary::GetAtlasStorage(UObject* WorldContextObject)
{
	if (!WorldContextObject) return nullptr;

	TArray<AActor*> OutActors;
	UGameplayStatics::GetAllActorsOfClass(WorldContextObject, AAtlasStorage::StaticClass(), OutActors);
	if (OutActors.Num() > 0)
	{
		return Cast<AAtlasStorage>(OutActors[0]);
	}

	return nullptr;
}