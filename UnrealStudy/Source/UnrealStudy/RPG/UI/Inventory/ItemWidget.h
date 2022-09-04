// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Border.h"
#include "Components/Image.h"

#include "../../Object/Item/Item.h"

#include "ItemWidget.generated.h"

/**
 * 
 */

DECLARE_DELEGATE_OneParam(FItemWidget_DELE_Single_One, FItemData);

UCLASS()
class UNREALSTUDY_API UItemWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void SetItemData(FItemData Value) { ItemData = Value; Refresh(); }

	void Refresh() { ItemImage->SetBrushFromTexture(ItemData.ItemImage); }

	FItemWidget_DELE_Single_One OnRemoved;

protected:

private:
	UPROPERTY(meta = (AllowPrivateAccess = true), EditDefaultsOnly, BlueprintReadWrite, Category = "Private")
	FItemData ItemData;

	UPROPERTY(meta = (AllowPrivateAccess = true, BindWidget), EditDefaultsOnly, BlueprintReadWrite, Category = "Private")
	UBorder* ItemBorder;

	UPROPERTY(meta = (AllowPrivateAccess = true, BindWidget), EditDefaultsOnly, BlueprintReadWrite, Category = "Private")
	UImage* ItemImage;
};
