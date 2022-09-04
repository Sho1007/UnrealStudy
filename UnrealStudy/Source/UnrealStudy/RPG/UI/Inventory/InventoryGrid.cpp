// Fill out your copyright notice in the Description page of Project Settings.


#include "./InventoryGrid.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Blueprint/SlateBlueprintLibrary.h"
#include "Components/CanvasPanelSlot.h"

#include "../../Object/Item/Item.h"
#include "./ItemWidget.h"

int32 UInventoryGrid::NativePaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	int32 Result = Super::NativePaint(Args, AllottedGeometry, MyCullingRect, OutDrawElements, LayerId, InWidgetStyle, bParentEnabled);

	FPaintContext Context(AllottedGeometry, MyCullingRect, OutDrawElements, LayerId, InWidgetStyle, bParentEnabled);

	for (FLine Line : Lines)
	{
		FVector2D TopLeft = USlateBlueprintLibrary::GetLocalTopLeft(GridBorder->GetCachedGeometry());
		UWidgetBlueprintLibrary::DrawLine(Context, TopLeft + Line.Start, TopLeft + Line.End, FLinearColor(0.5, 0.5, 0.5, 0.5));
	}

	return Result;
}

bool UInventoryGrid::Init(UInventory* _Inventory, float _TileSize)
{
	if (IsValid(_Inventory))
		Inventory = _Inventory;
	else
		return false;

	TileSize = _TileSize;

	UE_LOG(LogTemp, Warning, TEXT("Rows : %d, Columns : %d, TileSize : %f"), Inventory->GetRows(), Inventory->GetColumns(), TileSize);

	UWidgetLayoutLibrary::SlotAsCanvasSlot(GridBorder)->SetSize(FVector2D(Inventory->GetColumns() * TileSize, Inventory->GetRows() * TileSize));

	CreateLineSegments();

	Refresh();

	Inventory->OnInventoryChanged.BindUFunction(this, FName("Refresh"));
	GridBorder->OnMouseButtonDownEvent.BindUFunction(this, FName("OnGridBorderMouseButtonDown"));

	return true;
}

void UInventoryGrid::Refresh()
{
	GridCanvasPanel->ClearChildren();

	TArray<FItemData> Items = Inventory->GetItems();

	for (int i = 0; i < Items.Num(); ++i)
	{
		UItemWidget* ItemWidget = CreateWidget<UItemWidget>(this, UItemWidget::StaticClass());
		ItemWidget->SetItemData(Items[i]);
		ItemWidget->OnRemoved.BindUFunction(this, FName("OnItemRemoved"));
		GridCanvasPanel->AddChild(ItemWidget);

		UCanvasPanelSlot* CanvasPanelSlot = UWidgetLayoutLibrary::SlotAsCanvasSlot(ItemWidget);
		CanvasPanelSlot->SetAutoSize(true);

		int X = i % Inventory->GetColumns() * TileSize;
		int Y = i / Inventory->GetColumns() * TileSize;
		CanvasPanelSlot->SetPosition(FVector2d(X, Y));
	}
}

FEventReply UInventoryGrid::OnGridBorderMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	return UWidgetBlueprintLibrary::Handled();
}

void UInventoryGrid::CreateLineSegments()
{
	int Columns = Inventory->GetColumns();
	int Rows = Inventory->GetRows();

	int EndY = Rows * TileSize;
	for (int i = 0; i <= Columns; ++i)
	{
		int x = TileSize * i;
		FLine Line(x, 0, x, EndY);

		Lines.Add(Line);
	}

	int EndX = Columns * TileSize;
	for (int i = 0; i <= Rows; ++i)
	{
		int y = TileSize * i;
		FLine Line(0, y, EndX, y);

		Lines.Add(Line);
	}
}
