// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class UNREALSTUDY_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	AMovingPlatform();

	bool GoForward = true;

	UPROPERTY(EditAnywhere)
	float Speed;

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
	FVector Direction;

	UPROPERTY(EditAnywhere)
	float MoveDistance;

private:
	FVector GlobalTargetLocation;
	FVector GlobalStartLocation;
	FVector GlobalDirection;

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float deltaTime) override;
};
