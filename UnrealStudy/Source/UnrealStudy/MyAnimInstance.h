// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyAnimInstance.generated.h"

/**
 * 
 */

// 다음 공격 체크 델러게이트
DECLARE_MULTICAST_DELEGATE(FOnNextAttackCheckDelegate);
// 공격 체크용 델러게이트
DECLARE_MULTICAST_DELEGATE(FOnAttackHitCheckDelegate);

UCLASS()
class UNREALSTUDY_API UMyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UMyAnimInstance();

	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	UFUNCTION()
	void Attack();

	const UAnimMontage* GetAttackMontage() { return AttackMontage; }

	const float GetAttackCount() { return AttackCount; }
	void SetAttackCount(const float Value) { AttackCount = Value; }

	void SetIsAttack(bool Value) { bIsAttack = false; }

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = MyInstance, meta = (AllowPrivateAccess = "true"))
	bool bIsAttack;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = MyInstance, meta = (AllowPrivateAccess = "true"))
	float Speed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = MyInstance, meta = (AllowPrivateAccess = "true"))
	float Direction;

	bool bDoNextAttack;

	int AttackCount;

	UAnimMontage* AttackMontage;
};
