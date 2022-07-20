// Fill out your copyright notice in the Description page of Project Settings.


#include "./MainMenu.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Components/WidgetSwitcher.h"
#include "../PuzzlePlatformsGameInstance.h"




bool UMainMenu::Initialize()
{
	if (Super::Initialize() != true)
		return false;

	if (!ensure(Host != nullptr)) return false;
	Host->OnClicked.AddDynamic(this, &UMainMenu::HostBtnOnClicked);

	if (!ensure(Join != nullptr)) return false;
	Join->OnClicked.AddDynamic(this, &UMainMenu::JoinBtnOnClicked);

	if (!ensure(ConnectionBtn != nullptr)) return false;
	ConnectionBtn->OnClicked.AddDynamic(this, &UMainMenu::ConnectionBtnOnClicked);

	return true;
}

void UMainMenu::OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld)
{
	TearDown();
	Super::OnLevelRemovedFromWorld(InLevel, InWorld);
}

void UMainMenu::Setup(IMenuInterface* _MenuInterface)
{
	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	//UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(PlayerController, Menu, EMouseLockMode::LockAlways);
	// (아래 프로세스를 합친 것)
	FInputModeUIOnly InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	bIsFocusable = true;
	PlayerController->SetInputMode(InputModeData);

	PlayerController->bShowMouseCursor = true;

	AddToViewport();
	SetMenuInterface(_MenuInterface);
}

void UMainMenu::TearDown()
{
	UE_LOG(LogTemp, Warning, TEXT("MainMenu TearDown"));

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->SetInputMode(FInputModeGameOnly());
	PlayerController->bShowMouseCursor = false;
}

void UMainMenu::SetMenuInterface(IMenuInterface* _MenuInterface)
{
	this->MenuInterface = _MenuInterface;
}

void UMainMenu::HostBtnOnClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("Host Button Clicked"));

	if (!ensure(MenuInterface != nullptr)) return;
	MenuInterface->Host();
}

void UMainMenu::JoinBtnOnClicked()
{
	if (!ensure(MenuSwitcher != nullptr)) return;
	MenuSwitcher->SetActiveWidgetIndex(1);

	UE_LOG(LogTemp, Warning, TEXT("%d"), MenuSwitcher->ActiveWidgetIndex);
}

void UMainMenu::ConnectionBtnOnClicked()
{
	if (!ensure(IPAddressTextBox != nullptr)) return;
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *IPAddressTextBox->Text.ToString());

	MenuInterface->Join(IPAddressTextBox->Text.ToString());
}