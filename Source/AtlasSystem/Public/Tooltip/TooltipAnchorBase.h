// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TooltipAnchorBase.generated.h"

/**
 * 
 */
UCLASS(Abstract, Blueprintable, BlueprintType)
class ATLASSYSTEM_API UTooltipAnchorBase : public UObject
{
	GENERATED_BODY()

public:
	virtual UWorld* GetWorld() const override
	{
		if (HasAllFlags(RF_ClassDefaultObject))
		{
			// If we are a CDO, we must return nullptr instead of calling Outer->GetWorld() to fool UObject::ImplementsGetWorld.
			return nullptr;
		}
		return GetOuter()->GetWorld();
	}

public:
	UFUNCTION(BlueprintCallable, Category = "Default")
	void SetOwningPlayer(APlayerController* InOwningPlayer) { this->OwningPlayer = InOwningPlayer; }

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category = "Default")
	FVector2D GetPositionFromDirection(const FVector2D& Direction) const;
	virtual FVector2D GetPositionFromDirection_Implementation(const FVector2D& Direction) const;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default")
	APlayerController* OwningPlayer;
	
};
