// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AtlasStorage.generated.h"

class UAtlasBase;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAtlasStorageDelegate, AActor*, WorldEntry);

UCLASS()
class ATLASSYSTEM_API AAtlasStorage : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAtlasStorage();

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Atlas")
	FAtlasStorageDelegate OnEntryAdded;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Atlas")
	FAtlasStorageDelegate OnEntryRemoved;

	UFUNCTION(BlueprintPure, Category = "Default")
	TArray<AActor*> GetWorldEntries() const { return WorldEntryList; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Default")
	bool RegisterWorldEntry(AActor* WorldEntry);

	UFUNCTION(BlueprintCallable, Category = "Default")
	bool UnregisterWorldEntry(AActor* WorldEntry);

	UFUNCTION(BlueprintCallable, Category = "Default")
	bool RegisterAtlas(UAtlasBase* Atlas);

	UFUNCTION(BlueprintCallable, Category = "Default")
	bool UnregisterAtlas(UAtlasBase* Atlas);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default")
	TArray<AActor*> WorldEntryList;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default")
	TArray<UAtlasBase*> AtlasList;

};
