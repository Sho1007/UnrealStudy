// Fill out your copyright notice in the Description page of Project Settings.


#include "./MenuWidget.h"

void UMenuWidget::Setup()
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
}

void UMenuWidget::TearDown()
{
	UE_LOG(LogTemp, Warning, TEXT("MainMenu TearDown"));

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->SetInputMode(FInputModeGameOnly());
	PlayerController->bShowMouseCursor = false;

	this->RemoveFromViewport();
}

void UMenuWidget::SetMenuInterface(IMenuInterface* _MenuInterface)
{
	this->MenuInterface = _MenuInterface;
}

void UMenuWidget::OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld)
{
	TearDown();
	Super::OnLevelRemovedFromWorld(InLevel, InWorld);
}