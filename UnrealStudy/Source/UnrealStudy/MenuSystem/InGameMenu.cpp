// Fill out your copyright notice in the Description page of Project Settings.


#include "./InGameMenu.h"
#include "Components/Button.h"

bool UInGameMenu::Initialize()
{
	if (Super::Initialize() != true) return false;

	if (!ensure(CancelButton != nullptr)) return false;
	CancelButton->OnClicked.AddDynamic(this, &UInGameMenu::CloseMenu);

	if (!ensure(QuitButton != nullptr)) return false;
	QuitButton->OnClicked.AddDynamic(this, &UInGameMenu::ReturnMainMenu);

	return true;
}

void UInGameMenu::CloseMenu()
{
	TearDown();
}

void UInGameMenu::ReturnMainMenu()
{
	MenuInterface->LoadMainMenu();
}