// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tooltip/TooltipAnchorBase.h"
#include "TooltipAnchorWidget.generated.h"

/**
 * 
 */
UCLASS()
class ATLASSYSTEM_API UTooltipAnchorWidget : public UTooltipAnchorBase
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Default")
	void SetAnchorWidget(UUserWidget* InAnchorWidget) { this->AnchorWidget = InAnchorWidget; }

	virtual FVector2D GetPositionFromDirection_Implementation(const FVector2D& Direction) const override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default")
	UUserWidget* AnchorWidget;
};
