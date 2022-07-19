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
protected:
	virtual void Init();

public:
	UFUNCTION()
	virtual void Host() override;

	UFUNCTION(Exec)
	void Join(const FString& ServerAddress);

private:
	TSubclassOf<class UMainMenu> MenuClass;
};
