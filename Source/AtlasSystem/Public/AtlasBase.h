// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AtlasBase.generated.h"

/**
 *
 */

class AAtlasStorage;
class AActor;
class UAtlasWorldEntryWidget;
class UAtlasStorageEntry;

UCLASS()
class ATLASSYSTEM_API UAtlasBase : public UUserWidget
{
	GENERATED_BODY()

public:
	// UUserWidget interface
	virtual void NativeOnInitialized() override;
	// End of UUserWidget interface

protected:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Default")
	void SetupEntry(UAtlasWorldEntryWidget* EntryWidget);
	virtual void SetupEntry_Implementation(UAtlasWorldEntryWidget* EntryWidget) {};

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Default")
	void OnStorageTransformChanged(UAtlasWorldEntryWidget* Widget, const FTransform& Transform);
	virtual void OnStorageTransformChanged_Implementation(UAtlasWorldEntryWidget* Widget, const FTransform& Transform) {};

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Default")
	void AddEntry(UAtlasStorageEntry* StorageEntry);
	virtual void AddEntry_Implementation(UAtlasStorageEntry* StorageEntry);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Default")
	void RemoveEntry(UAtlasStorageEntry* StorageEntry);
	virtual void RemoveEntry_Implementation(UAtlasStorageEntry* StorageEntry);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Default")
	AAtlasStorage* Storage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default")
	TMap<UAtlasStorageEntry*, UAtlasWorldEntryWidget*> StorageEntryMap;
};
