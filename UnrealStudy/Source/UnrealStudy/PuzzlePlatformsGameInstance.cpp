// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzlePlatformsGameInstance.h"

#include "PlatformTrigger.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "MenuSystem/MainMenu.h"
#include "MenuSystem/InGameMenu.h"
#include "MenuSystem/MenuWidget.h"

#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

UPuzzlePlatformsGameInstance::UPuzzlePlatformsGameInstance(const FObjectInitializer& ObjectInitializer)
{
	ConstructorHelpers::FClassFinder<UMainMenu> MenuBPClass(TEXT("/Game/PuzzlePlatforms/MenuSystem/WBP_MainMenu"));
	if (!ensure(MenuBPClass.Class != nullptr)) return;

	MenuClass = MenuBPClass.Class;

	ConstructorHelpers::FClassFinder<UInGameMenu> InGameMenuBPClass(TEXT("/Game/PuzzlePlatforms/MenuSystem/WBP_InGameMenu"));
	if (!ensure(InGameMenuBPClass.Class != nullptr)) return;

	InGameMenuClass = InGameMenuBPClass.Class;
}

void UPuzzlePlatformsGameInstance::Init()
{
}

void UPuzzlePlatformsGameInstance::LoadMenu()
{
	if (!ensure(MenuClass != nullptr)) return;
	MainMenu = CreateWidget<UMainMenu>(this, MenuClass);

	if (!ensure(MainMenu != nullptr)) return;
	MainMenu->Setup();
	MainMenu->SetMenuInterface(this);
}

void UPuzzlePlatformsGameInstance::LoadInGameMenu()
{
	if (!ensure(InGameMenuClass != nullptr)) return;

	if (InGameMenu == nullptr)
	{
		InGameMenu = CreateWidget<UInGameMenu>(this, InGameMenuClass);
		if (!ensure(InGameMenu != nullptr)) return;
		InGameMenu->SetMenuInterface(this);
	}

	if (!ensure(InGameMenu != nullptr)) return;
	InGameMenu->Setup();
}

void UPuzzlePlatformsGameInstance::Host()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Hosting")));

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	World->ServerTravel("/Game/PuzzlePlatforms/Maps/Map_PuzzleGameMap?listen");
}

void UPuzzlePlatformsGameInstance::Join(const FString& ServerAddress)
{
	// TODO

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Joining %s"), *ServerAddress));

	APlayerController* PlayerController = this->GetFirstLocalPlayerController(GetWorld());
	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->ClientTravel(ServerAddress, ETravelType::TRAVEL_Absolute);
}

void UPuzzlePlatformsGameInstance::LoadMainMenu()
{
	APlayerController* PlayerController = this->GetFirstLocalPlayerController(GetWorld());
	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->ClientTravel("/Game/PuzzlePlatforms/Maps/MainMenu", ETravelType::TRAVEL_Absolute);
}

void UPuzzlePlatformsGameInstance::QuitGame()
{
	APlayerController* PlayerController = this->GetFirstLocalPlayerController(GWorld);
	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->ConsoleCommand(FString("quit"), false);
}