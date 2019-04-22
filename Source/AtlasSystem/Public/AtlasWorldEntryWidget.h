// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AtlasStorageEntry.h"
#include "AtlasWorldEntryWidget.generated.h"

/**
 * 
 */

class UAtlasWorldEntryComponent;
class AActor;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDesiredWidgetTransformChanged, UAtlasWorldEntryWidget*, Widget, const FTransform&, Transform);

UCLASS()
class ATLASSYSTEM_API UAtlasWorldEntryWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Atlas")
	FDesiredWidgetTransformChanged OnDesiredTransformChanged;

public:
	//UAtlasWorldEntryWidget(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintCallable, Category = "Default")
	bool ConnectStorageEntry(UAtlasStorageEntry* StorageEntry);

	UFUNCTION(BlueprintPure, Category = "Default")
	const FTransform& GetStorageTransform() const { return StorageEntry->GetEntryTransform(); }
	
	UFUNCTION(BlueprintPure, Category = "Default")
	FVector GetStorageLocation() const { return StorageEntry->GetEntryTransform().GetLocation(); }
	
	UFUNCTION(BlueprintPure, Category = "Default")
	FRotator GetStorageRotation() const { return StorageEntry->GetEntryTransform().Rotator(); }

	UFUNCTION(BlueprintPure, Category = "Default")
	AActor* GetWorldActor() const { return StorageEntry->GetReferenceActor(); }

protected:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Default")
	void OnStorageTransformChanged(const FTransform& Transform);
	virtual void OnStorageTransformChanged_Implementation(const FTransform& Transform);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Default")
	void OnStorageStateChanged();
	virtual void OnStorageStateChanged_Implementation();

	/*UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Default")
	UUserWidget* CreateTooltipWidget();
	virtual UUserWidget* CreateTooltipWidget_Implementation() { return nullptr; }*/

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default")
	UAtlasStorageEntry* StorageEntry;
};
