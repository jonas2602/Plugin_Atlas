// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AtlasWorldEntryWidget.generated.h"

/**
 * 
 */

class UAtlasWorldEntryComponent;
class AActor;
class UAtlasStorageEntry;

UCLASS()
class ATLASSYSTEM_API UAtlasWorldEntryWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Default")
	bool ConnectWorldEntry(AActor* WorldActor);

	UFUNCTION(BlueprintCallable, Category = "Default")
	bool ConnectEntry(UAtlasStorageEntry* StorageEntry);

protected:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Default")
	void OnWorldTransformChanged(const FTransform& Transform);
	virtual void OnWorldTransformChanged_Implementation(const FTransform& Transform);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Default")
	void OnWorldEntryChanged();
	virtual void OnWorldEntryChanged_Implementation();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default")
	AActor* WorldEntryActor;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default")
	UAtlasWorldEntryComponent* WorldEntryComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default")
	UAtlasStorageEntry* StorageEntry;
};
