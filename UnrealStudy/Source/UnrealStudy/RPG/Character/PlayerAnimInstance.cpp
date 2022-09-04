// Fill out your copyright notice in the Description page of Project Settings.


#include "./PlayerAnimInstance.h"

void UPlayerAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
}

void UPlayerAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	Speed = GetOwningActor()->GetVelocity().Size();
	Direction = CalculateDirection(GetOwningActor()->GetVelocity(), GetOwningActor()->GetActorRotation());
}
