// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "./MenuWidget.h"

#include "MainMenu.generated.h"


/**
 * 
 */
UCLASS()
class UNREALSTUDY_API UMainMenu : public UMenuWidget
{
	GENERATED_BODY()

protected:
	virtual bool Initialize() override;

private:
	UPROPERTY(meta = (BindWidget))
	class UButton* QuitButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* HostButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* JoinButton;

	UPROPERTY(meta = (BindWidget))
	class UEditableTextBox* IPAddressTextBox;

	UPROPERTY(meta = (BindWidget))
	class UButton* ConnectionButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* JoinMenu_CancleButton;

	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* MenuSwitcher;

	UPROPERTY(meta = (BindWidget))
	class UWidget* MainMenu;

	UPROPERTY(meta = (BindWidget))
	class UWidget* JoinMenu;

private:
	UFUNCTION()
	void HostServer();

	UFUNCTION()
	void OpenJoinMenu();

	UFUNCTION()
	void ConnectionButtonOnClicked();

	UFUNCTION()
	void JoinMenu_CancleButtonOnClicked();

	UFUNCTION()
	void QuitGame();
};
