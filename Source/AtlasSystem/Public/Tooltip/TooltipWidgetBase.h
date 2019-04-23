// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TooltipTypes.h"
#include "TooltipWidgetBase.generated.h"

class UTooltipAnchorBase;

UCLASS()
class ATLASSYSTEM_API UTooltipWidgetBase : public UUserWidget
{
	GENERATED_BODY()

public:
	// UUserWidget interface
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	// End of UUserWidget interface

protected:
	UFUNCTION(BlueprintCallable, Category = "Default")
	void InitTooltip();

	UFUNCTION(BlueprintCallable, Category = "Default")
	void UpdateGeometry();

public:
	UFUNCTION(BlueprintCallable, Category = "Default")
	void SetTooltipAnchor(UTooltipAnchorBase* InTooltipAnchor) { this->TooltipAnchor = InTooltipAnchor; }

	UFUNCTION(BlueprintCallable, Category = "Default")
	void SetAnchorType(ETooltipAnchor InAnchorType) { this->AnchorType = InAnchorType; }

	UFUNCTION(BlueprintCallable, Category = "Default")
	void SetAlignmentType(ETooltipAlignment InAlignmentType) { this->AlignmentType = InAlignmentType; }

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Default")
	void SetTooltipContent(UUserWidget* Content);
	virtual void SetTooltipContent_Implementation(UUserWidget* Content);

protected:
	UFUNCTION(BlueprintPure, Category = "Default")
	FVector2D AlignmentToDirection(ETooltipAlignment AlignmentType) const;

	UFUNCTION(BlueprintPure, Category = "Default")
	FVector2D PositionFromDirection(const FVector2D& Direction) const;

	UFUNCTION(BlueprintPure, Category = "Default")
	FVector2D AlignmentFromDirection(const FVector2D& Direction) const;

	UFUNCTION(BlueprintPure, Category = "Default")
	FVector2D CalculateViewportOffset(const FVector2D& Position, const FVector2D& Alignment, const FVector2D& PriorityDirection) const;

	UFUNCTION(BlueprintPure, Category = "Default")
	bool AdjustDirectionByOffset(const FVector2D& TargetDirection, const FVector2D& Offset, FVector2D& OutDirection) const;

	UFUNCTION(BlueprintPure, Category = "Default")
	FVector2D ClipToViewport(const FVector2D& Position, const FVector2D& Alignment, const FVector2D& Direction) const;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
	UTooltipAnchorBase* TooltipAnchor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
	ETooltipAlignment AlignmentType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
	ETooltipAnchor AnchorType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
	float CursorHalfHeight = 20.0f;
};
