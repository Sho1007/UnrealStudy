// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MenuSystem/MenuInterface.h"

#include "PuzzlePlatformsGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class UNREALSTUDY_API UPuzzlePlatformsGameInstance : public UGameInstance, public IMenuInterface
{
	GENERATED_BODY()

public:
	UPuzzlePlatformsGameInstance(const FObjectInitializer& ObjectInitializer);


	UFUNCTION(Exec, BlueprintCallable)
	void LoadMenu();

	UFUNCTION(BlueprintCallable)
	void LoadInGameMenu();
protected:
	virtual void Init();

public:
	UFUNCTION()
	virtual void Host() override;

	UFUNCTION(Exec)
	virtual void Join(const FString& ServerAddress) override;

private:
	virtual void LoadMainMenu() override;

	virtual void QuitGame() override;

private:
	TSubclassOf<class UMainMenu> MenuClass;
	class UMainMenu* MainMenu;

	TSubclassOf<class UInGameMenu> InGameMenuClass;
	class UInGameMenu* InGameMenu;
};
