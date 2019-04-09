// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "AtlasWorldEntryComponent.generated.h"

/**
 * 
 */

class UAtlasWorldEntryWidget;
class UAtlasStorageEntry;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWorldTransformChanged, const FTransform&, Transform);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FWorldEntryChanged);

UCLASS()
class ATLASSYSTEM_API UAtlasWorldEntryComponent : public UWidgetComponent
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Atlas")
	FWorldTransformChanged OnWorldTransformChanged;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Atlas")
	FWorldEntryChanged OnWorldEntryChanged;

	UAtlasWorldEntryComponent();

protected:
	virtual void OnUpdateTransform(EUpdateTransformFlags UpdateTransformFlags, ETeleportType Teleport = ETeleportType::None) override;

public:
	UFUNCTION(BlueprintCallable, Category = "Default")
	void UpdateEntryWidget();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Default")
	TSubclassOf<UAtlasWorldEntryWidget> EntryWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
	UAtlasStorageEntry* StorageTemplate;
};
