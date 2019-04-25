// Fill out your copyright notice in the Description page of Project Settings.


#include "AtlasEntryFigure.h"
#include "AtlasStorageEntry.h"
#include "AtlasSystem.h"
#include "Tooltip/BorderedTooltipWidget.h"
#include "Tooltip/TooltipFunctionLibrary.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
AAtlasEntryFigure::AAtlasEntryFigure()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TooltipClass = UBorderedTooltipWidget::StaticClass();
	TooltipAlignment = ETooltipAlignment::UpperRight;
	TooltipAnchor = ETooltipAnchor::Entry;

}

// Called when the game starts or when spawned
void AAtlasEntryFigure::BeginPlay()
{
	Super::BeginPlay();
}

void AAtlasEntryFigure::NotifyActorBeginCursorOver()
{
	Super::NotifyActorBeginCursorOver();
	//UE_LOG(LogAtlas, Warning, TEXT("Begin Cursor Over"));

	// Only Create Tooltip if Function returns valid content
	UUserWidget* TooltipContent = CreateTooltipContent();
	if (TooltipContent)
	{
		APlayerController* OwningPlayer = TooltipContent->GetOwningPlayer(); // UGameplayStatics::GetPlayerController(GetWorld(), 0);
		TooltipInstance = UTooltipFunctionLibrary::CreateTooltipForActor(TooltipContent, OwningPlayer, this, TooltipClass, TooltipAlignment, TooltipAnchor);
	}
}

void AAtlasEntryFigure::NotifyActorEndCursorOver()
{
	Super::NotifyActorEndCursorOver();
	//UE_LOG(LogAtlas, Warning, TEXT("End Cursor Over"));

	// Destroy Tooltip if created earlier
	UTooltipFunctionLibrary::DestroyTooltip(TooltipInstance);
}

bool AAtlasEntryFigure::ConnectStorageEntry(UAtlasStorageEntry* InStorageEntry)
{
	// Valid Storage Entry?
	if (!InStorageEntry) return false;

	// Set References to WorldEntry
	this->StorageEntry = InStorageEntry;

	// Bind Delegates + Initialize Values
	StorageEntry->OnTransformChanged.AddDynamic(this, &AAtlasEntryFigure::OnStorageTransformChanged);
	StorageEntry->OnStateChanged.AddDynamic(this, &AAtlasEntryFigure::OnStorageStateChanged);

	OnStorageTransformChanged(StorageEntry->GetEntryTransform());
	OnStorageStateChanged();

	return true;
}

void AAtlasEntryFigure::OnStorageTransformChanged_Implementation(const FTransform& Transform)
{
	OnDesiredTransformChanged.Broadcast(this, Transform);
}

void AAtlasEntryFigure::OnStorageStateChanged_Implementation()
{

}

UUserWidget* AAtlasEntryFigure::CreateTooltipContent_Implementation()
{
	return nullptr;
}

