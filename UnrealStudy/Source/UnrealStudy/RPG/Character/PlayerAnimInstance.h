// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlayerAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class UNREALSTUDY_API UPlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
protected:
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

private:
	UPROPERTY(meta = (AllowPrivateAccess = true), BlueprintReadOnly, Category = "PlayerAnimInstance")
	float Speed;
	UPROPERTY(meta = (AllowPrivateAccess = true), BlueprintReadOnly, Category = "PlayerAnimInstance")
	float Direction;
};
