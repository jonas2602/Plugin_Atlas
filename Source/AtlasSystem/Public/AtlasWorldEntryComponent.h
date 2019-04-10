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

UCLASS()
class ATLASSYSTEM_API UAtlasWorldEntryComponent : public UWidgetComponent
{
	GENERATED_BODY()
	
public:
	UAtlasWorldEntryComponent();

protected:
	virtual void OnUpdateTransform(EUpdateTransformFlags UpdateTransformFlags, ETeleportType Teleport = ETeleportType::None) override;

	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Default")
	void CreateWorldEntry();
	virtual void CreateWorldEntry_Implementation();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
	UAtlasStorageEntry* StorageTemplate;
};
