// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AtlasStorage.generated.h"

class UAtlasBase;
class UAtlasStorageEntry;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAtlasStorageDelegate, AActor*, WorldEntry);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAtlasStorageEntryDelegate, UAtlasStorageEntry*, StorageEntry);

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

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Atlas")
	FAtlasStorageEntryDelegate OnStorageEntryAdded;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Atlas")
	FAtlasStorageEntryDelegate OnStorageEntryRemoved;

	UFUNCTION(BlueprintPure, Category = "Default")
	TArray<AActor*> GetWorldEntries() const { return WorldEntryList; }

	UFUNCTION(BlueprintPure, Category = "Default")
	TArray<UAtlasStorageEntry*> GetStorageEntries() const { return StorageEntryList; }

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
	UAtlasStorageEntry* CreateEntry(TSubclassOf<UAtlasStorageEntry> EntryClass);

	UFUNCTION(BlueprintCallable, Category = "Default")
	bool RegisterEntry(UAtlasStorageEntry* Entry);

	UFUNCTION(BlueprintCallable, Category = "Default")
	bool UnregisterEntry(UAtlasStorageEntry* Entry);

	UFUNCTION(BlueprintCallable, Category = "Default")
	bool RegisterAtlas(UAtlasBase* Atlas);

	UFUNCTION(BlueprintCallable, Category = "Default")
	bool UnregisterAtlas(UAtlasBase* Atlas);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default")
	TArray<AActor*> WorldEntryList;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default")
	TArray<UAtlasStorageEntry*> StorageEntryList;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default")
	TArray<UAtlasBase*> AtlasList;

};
