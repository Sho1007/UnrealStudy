// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"

UMyAnimInstance::UMyAnimInstance()
{
	bIsAttack = false;
	bDoNextAttack = false;

	AttackCount = 0;

	ConstructorHelpers::FObjectFinder<UAnimMontage> ATTACK_MONTAGE(
		TEXT("AnimMontage'/Game/AnimationTest/KnightCharacter/Animations/AttackMontage.AttackMontage'")
	);
	if (ATTACK_MONTAGE.Succeeded())
	{
		AttackMontage = ATTACK_MONTAGE.Object;
	}
}

void UMyAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
}

void UMyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	AActor* OwningActor = GetOwningActor();

	if (OwningActor == nullptr) return;

	Speed = OwningActor->GetVelocity().Size();

	Direction = CalculateDirection(OwningActor->GetVelocity(), OwningActor->GetActorRotation());
}

void UMyAnimInstance::Attack()
{
	/*
	if (!bIsAttack)
	{
		bIsAttack = true;
		// TODO : Play Attack Montage
		Montage_Play(AttackMontage);
	}
	*/

	if (Montage_IsPlaying(AttackMontage))
	{
		AttackCount = 1;
	}
	else
	{
		Montage_Play(AttackMontage);
	}
}
