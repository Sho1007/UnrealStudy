// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "./MenuInterface.h"

#include "MainMenu.generated.h"


/**
 * 
 */
UCLASS()
class UNREALSTUDY_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()
public:
	void SetMenuInterface(IMenuInterface* _MenuInterface);
protected:
	virtual bool Initialize() override;

private:
	UPROPERTY(meta = (BindWidget))
	class UButton* Host;

	UPROPERTY(meta = (BindWidget))
	class UButton* Join;

private:
	UFUNCTION()
	void HostBtnOnClicked();

	IMenuInterface* MenuInterface;
};
