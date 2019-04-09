// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AtlasStorageEntry.generated.h"

class UAtlasWorldEntryWidget;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEntryTransformChanged, const FTransform&, Transform);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEntryStateChanged);

UCLASS(Blueprintable, BlueprintType, EditInlineNew, DefaultToInstanced)
class ATLASSYSTEM_API UAtlasStorageEntry : public UObject
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAtlasStorageEntry();

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Atlas")
	FEntryTransformChanged OnTransformChanged;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Atlas")
	FEntryStateChanged OnStateChanged;

	UFUNCTION(BlueprintPure, Category = "Atlas")
	const FTransform& GetEntryTransform() const { return EntryTransform; }

	UFUNCTION(BlueprintCallable, Category = "Atlas")
	void SetEntryTransform(FTransform InTransform);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Atlas")
	FTransform EntryTransform;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Atlas")
	TSubclassOf<UAtlasWorldEntryWidget> EntryWidgetClass;
};
