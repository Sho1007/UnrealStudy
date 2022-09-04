// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "../../Object/Item/Item.h"

#include "Inventory.generated.h"

/**
 * 
 */

DECLARE_DELEGATE(FInventory_Dele_Single)

UCLASS()
class UNREALSTUDY_API UInventory : public UObject
{
	GENERATED_BODY()
	
public:
	FInventory_Dele_Single OnInventoryChanged;

	void Init(int _Rows, int _Columns) { Rows = _Rows; Columns = _Columns; }

	int GetRows() const { return Rows; }
	int GetColumns() const { return Columns; }

	TArray<FItemData> GetItems() { return Items; }
private:
	int Rows;

	int Columns;

	TArray<FItemData> Items;
};
