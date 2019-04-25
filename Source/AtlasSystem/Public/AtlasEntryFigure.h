// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AtlasStorageEntry.h"
#include "Tooltip/TooltipTypes.h"
#include "AtlasEntryFigure.generated.h"

class UTooltipWidgetBase;

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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void NotifyActorBeginCursorOver() override;
	virtual void NotifyActorEndCursorOver() override;

public:
	UFUNCTION(BlueprintCallable, Category = "Default")
	bool ConnectStorageEntry(UAtlasStorageEntry* InStorageEntry);

protected:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Default")
	void OnStorageTransformChanged(const FTransform& Transform);
	virtual void OnStorageTransformChanged_Implementation(const FTransform& Transform);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Default")
	void OnStorageStateChanged();
	virtual void OnStorageStateChanged_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Tooltip")
	UUserWidget* CreateTooltipContent();
	virtual UUserWidget* CreateTooltipContent_Implementation();


protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default")
	UAtlasStorageEntry* StorageEntry;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Tooltip")
	ETooltipAlignment TooltipAlignment;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Tooltip")
	ETooltipAnchor TooltipAnchor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Tooltip")
	TSubclassOf<UTooltipWidgetBase> TooltipClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tooltip")
	UTooltipWidgetBase* TooltipInstance;
};
