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

UCLASS()
class ATLASSYSTEM_API UAtlasBase : public UUserWidget
{
	GENERATED_BODY()

public:
	// UUserWidget interface
	virtual void NativeOnInitialized() override;
	// End of UUserWidget interface

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Default")
	void AddWorldEntry(AActor* WorldEntry);
	virtual void AddWorldEntry_Implementation(AActor* WorldEntry) {};

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Default")
	void RemoveWorldEntry(AActor* WorldEntry);
	virtual void RemoveWorldEntry_Implementation(AActor* WorldEntry) {};

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Default")
	AAtlasStorage* Storage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default")
	TMap<AActor*, UAtlasWorldEntryWidget*> WorldEntryMap;
};
