// Fill out your copyright notice in the Description page of Project Settings.


#include "./MainMenu.h"

#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Components/WidgetSwitcher.h"
#include "Components/InputComponent.h"

#include "../PuzzlePlatformsGameInstance.h"






bool UMainMenu::Initialize()
{
	if (Super::Initialize() != true)
		return false;

	if (!ensure(HostButton != nullptr)) return false;
	HostButton->OnClicked.AddDynamic(this, &UMainMenu::HostServer);

	if (!ensure(JoinButton != nullptr)) return false;
	JoinButton->OnClicked.AddDynamic(this, &UMainMenu::OpenJoinMenu);

	if (!ensure(ConnectionButton != nullptr)) return false;
	ConnectionButton->OnClicked.AddDynamic(this, &UMainMenu::ConnectionButtonOnClicked);

	if (!ensure(JoinMenu_CancleButton != nullptr)) return false;
	JoinMenu_CancleButton->OnClicked.AddDynamic(this, &UMainMenu::JoinMenu_CancleButtonOnClicked);

	if (!ensure(QuitButton != nullptr)) return false;
	QuitButton->OnClicked.AddDynamic(this, &UMainMenu::QuitGame);

	return true;
}


void UMainMenu::HostServer()
{
	UE_LOG(LogTemp, Warning, TEXT("Host Button Clicked"));

	if (!ensure(MenuInterface != nullptr)) return;
	MenuInterface->Host();
}

void UMainMenu::OpenJoinMenu()
{
	if (!ensure(MenuSwitcher != nullptr)) return;
	if (!ensure(JoinMenu != nullptr)) return;

	MenuSwitcher->SetActiveWidget(JoinMenu);
}

void UMainMenu::ConnectionButtonOnClicked()
{
	if (MenuInterface != nullptr)
	{
		if (!ensure(IPAddressTextBox != nullptr)) return;

		MenuInterface->Join(IPAddressTextBox->GetText().ToString());
	}
	
}

void UMainMenu::JoinMenu_CancleButtonOnClicked()
{
	if (!ensure(MenuSwitcher != nullptr)) return;
	if (!ensure(MainMenu != nullptr)) return;

	MenuSwitcher->SetActiveWidget(MainMenu);
}

void UMainMenu::QuitGame()
{
	if (!ensure(MenuInterface != nullptr)) return;

	MenuInterface->QuitGame();
}