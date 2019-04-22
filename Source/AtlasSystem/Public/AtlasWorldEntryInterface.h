// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "AtlasWorldEntryInterface.generated.h"

class UAtlasWorldEntryComponent;
class UAtlasWorldEntryWidget;
class APlayerController;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UAtlasWorldEntryInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ATLASSYSTEM_API IAtlasWorldEntryInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Atlas")
	UAtlasWorldEntryComponent* GetWorldEntryComponent() const;
	virtual UAtlasWorldEntryComponent* GetWorldEntryComponent_Implementation() const;

	/*UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Atlas")
	UAtlasWorldEntryWidget* GetEntryWidget(APlayerController* Controller) const;
	virtual UAtlasWorldEntryWidget* GetEntryWidget_Implementation(APlayerController* Controller) const;*/
};
