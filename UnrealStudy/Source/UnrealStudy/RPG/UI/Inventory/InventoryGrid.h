// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Border.h"
#include "Components/CanvasPanel.h"

#include "./Inventory.h"

#include "InventoryGrid.generated.h"

/**
 * 
 */
USTRUCT(Atomic, BlueprintType)
struct FLine
{
	GENERATED_USTRUCT_BODY()

	FLine()
	{
	}
	FLine(float StartX, float StartY, float EndX, float EndY)
		: Start(FVector2D(StartX, StartY)), End(FVector2D(EndX, EndY))
	{
	}

	UPROPERTY(BlueprintReadWrite)
	FVector2D Start;
	UPROPERTY(BlueprintReadWrite)
	FVector2D End;
};

UCLASS()
class UNREALSTUDY_API UInventoryGrid : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual int32 NativePaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override;
public:
	bool Init(UInventory* _Inventory, float _TileSize);

	UFUNCTION()
	void Refresh();
	UFUNCTION()
	FEventReply OnGridBorderMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent);
private:
	void CreateLineSegments();

private:
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = true), Category = "Private")
	TArray<FLine> Lines;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = true, BindWidget), Category = "Private")
	UBorder* GridBorder;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = true, BindWidget), Category = "Private")
	UCanvasPanel* GridCanvasPanel;

	float TileSize;

	UInventory* Inventory;
};
