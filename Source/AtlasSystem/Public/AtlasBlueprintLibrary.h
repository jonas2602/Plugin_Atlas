// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AtlasBlueprintLibrary.generated.h"

/**
 * 
 */

class AAtlasStorage;

UCLASS()
class ATLASSYSTEM_API UAtlasBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, meta = (WorldContext = "WorldContextObject"), Category = "Atlas")
	static AAtlasStorage* GetAtlasStorage(UObject* WorldContextObject);
};
