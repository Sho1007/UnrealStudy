// Fill out your copyright notice in the Description page of Project Settings.


#include "./MainMenu.h"
#include "Components/Button.h"
#include "../PuzzlePlatformsGameInstance.h"




bool UMainMenu::Initialize()
{
	if (Super::Initialize() != true)
		return false;

	if (!ensure(Host != nullptr)) return false;
	Host->OnClicked.AddDynamic(this, &UMainMenu::HostBtnOnClicked);
	

	return true;
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