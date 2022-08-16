// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "MyAnimInstance.h"

#include "Knight.generated.h"

UCLASS()
class UNREALSTUDY_API AKnight : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AKnight();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void PostInitializeComponents() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted);

	UFUNCTION()
	void OnAttackMontageNotifyBegin(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointPayload);

private:
	UMyAnimInstance* AnimInstance;

	void DoAttack();

	void MoveForward(float InputAxis);
	void MoveRight(float InputAxis);
};
