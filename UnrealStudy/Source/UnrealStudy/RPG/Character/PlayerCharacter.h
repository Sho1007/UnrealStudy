// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "./RPGCharacter.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

#include "../Interface/InteractableInterface.h"
#include "../UI/Inventory/Inventory.h"

#include "PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class UNREALSTUDY_API APlayerCharacter : public ARPGCharacter, public IInteractableInterface
{
	GENERATED_BODY()

public:
	APlayerCharacter();

	UFUNCTION()
	void MoveForward(float InputAxis);
	UFUNCTION()
	void MoveRight(float InputAxis);

protected:
	/** Setup pawn when game starts. **/
	virtual void BeginPlay() override;

	/** Cleanup pawn when game ends. **/
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void Interact() override;
	
private:
	UPROPERTY(EditAnywhere)
	USpringArmComponent*	SpringArmComponent;
	UPROPERTY(EditAnywhere)
	UCameraComponent*		CameraComponent;

	/** Widget class to spawn for the crosshair **/
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> HUDClass;

	/** The widget instance that we are using as our HUD **/
	UPROPERTY()
	class UUserWidget* HUDWidget;

	UInventory* Inventory;

	// Inventory 를 위한 임시 변수
	UPROPERTY(meta = (AllowPrivateAccess = true), EditDefaultsOnly)
	int Rows;
	UPROPERTY(meta = (AllowPrivateAccess = true), EditDefaultsOnly)
	int Columns;
	UPROPERTY(meta = (AllowPrivateAccess = true), EditDefaultsOnly)
	float TileSize;
};
