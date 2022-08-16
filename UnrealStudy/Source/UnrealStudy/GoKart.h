// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GokartMovementComponent.h"
#include "GoKartMovementReplicator.h"
#include "GoKart.generated.h"





UCLASS()
class UNREALSTUDY_API AGoKart : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AGoKart();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere)
	class USkeletalMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
	class UBoxComponent* Box;

	UPROPERTY(EditAnywhere)
	class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
	class USpringArmComponent* SpringArm;

private:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* MeshOffsetRoot;

	UPROPERTY(VisibleAnywhere)
	UGoKartMovementComponent* MovementComponent;

	UPROPERTY(VisibleAnywhere)
	UGoKartMovementReplicator* MovementReplicator;

	void MoveForward(float Value);
	void MoveRight(float Value);
};
