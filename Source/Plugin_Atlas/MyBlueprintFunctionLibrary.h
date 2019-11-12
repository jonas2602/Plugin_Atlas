// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBlueprintFunctionLibrary.generated.h"

USTRUCT(BlueprintType)
struct FMyStructTest 
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "First")
	int value1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Second")
	int value2;

};

/**
 * 
 */
UCLASS()
class PLUGIN_ATLAS_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
};
