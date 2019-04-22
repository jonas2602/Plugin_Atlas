// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AtlasStorageEntry.h"
#include "AtlasEntryFigure.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDesiredFigureTransformChanged, AAtlasEntryFigure*, Figure, const FTransform&, Transform);

UCLASS()
class ATLASSYSTEM_API AAtlasEntryFigure : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Atlas")
	FDesiredFigureTransformChanged OnDesiredTransformChanged;

	// Sets default values for this actor's properties
	AAtlasEntryFigure();

	UFUNCTION(BlueprintCallable, Category = "Default")
	bool ConnectStorageEntry(UAtlasStorageEntry* StorageEntry);

protected:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Default")
	void OnStorageTransformChanged(const FTransform& Transform);
	virtual void OnStorageTransformChanged_Implementation(const FTransform& Transform);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Default")
	void OnStorageStateChanged();
	virtual void OnStorageStateChanged_Implementation();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default")
	UAtlasStorageEntry* StorageEntry;
};
