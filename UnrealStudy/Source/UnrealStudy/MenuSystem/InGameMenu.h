// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "./MenuWidget.h"

#include "InGameMenu.generated.h"

/**
 * 
 */
UCLASS()
class UNREALSTUDY_API UInGameMenu : public UMenuWidget
{
	GENERATED_BODY()

protected:
	virtual bool Initialize() override;

private:
	UPROPERTY(meta = (BindWidget))
	class UButton* QuitButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* CancelButton;
	

	UFUNCTION()
	void CloseMenu();

	UFUNCTION()
	void ReturnMainMenu();
};
