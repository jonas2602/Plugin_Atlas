// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tooltip/TooltipAnchorBase.h"
#include "TooltipAnchorActor.generated.h"

/**
 * 
 */
UCLASS()
class ATLASSYSTEM_API UTooltipAnchorActor : public UTooltipAnchorBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Default")
	void SetAnchorActor(AActor* InAnchorActor) { this->AnchorActor = InAnchorActor; }

	virtual FVector2D GetPositionFromDirection_Implementation(const FVector2D& Direction) const override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default")
	AActor* AnchorActor;
};
