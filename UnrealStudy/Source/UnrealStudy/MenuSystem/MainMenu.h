// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "./MenuInterface.h"

#include "MainMenu.generated.h"


/**
 * 
 */
UCLASS()
class UNREALSTUDY_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()
public:
	void SetMenuInterface(IMenuInterface* _MenuInterface);

	void Setup(IMenuInterface* _MenuInterface);

	void TearDown();

protected:
	virtual bool Initialize() override;
	virtual void OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld) override;

private:
	UPROPERTY(meta = (BindWidget))
	class UButton* Host;

	UPROPERTY(meta = (BindWidget))
	class UButton* Join;

	UPROPERTY(meta = (BindWidget))
	class UEditableTextBox* IPAddressTextBox;

	UPROPERTY(meta = (BindWidget))
	class UButton* ConnectionBtn;

	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* MenuSwitcher;

private:
	UFUNCTION()
	void HostBtnOnClicked();

	UFUNCTION()
	void JoinBtnOnClicked();

	UFUNCTION()
	void ConnectionBtnOnClicked();

	IMenuInterface* MenuInterface;
};
