// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AtlasStorageEntry.generated.h"

class UAtlasWorldEntryWidget;
class AAtlasEntryFigure;

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
	
	UFUNCTION(BlueprintPure, Category = "Atlas")
	TSubclassOf<UAtlasWorldEntryWidget> GetEntryWidgetClass() const { return EntryWidgetClass; }

	UFUNCTION(BlueprintPure, Category = "Atlas")
	TSubclassOf<AAtlasEntryFigure> GetEntryFigureClass() const { return EntryFigureClass; }

	UFUNCTION(BlueprintPure, Category = "Atlas")
	AActor* GetReferenceActor() const { return ReferenceActor; }

	UFUNCTION(BlueprintCallable, Category = "Atlas")
	void SetEntryTransform(FTransform InTransform);

	UFUNCTION(BlueprintCallable, Category = "Atlas")
	void SetReferenceActor(AActor* InActor);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Atlas")
	AActor* ReferenceActor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Atlas")
	FTransform EntryTransform;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Atlas")
	TSubclassOf<UAtlasWorldEntryWidget> EntryWidgetClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Atlas")
	TSubclassOf<AAtlasEntryFigure> EntryFigureClass;

	// TODO: third type for widget components?
	// TODO: Data splitted in Widget and Figure related variables
};
