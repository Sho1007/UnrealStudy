// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"
#include "Math/Vector.h"


AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}

	GlobalStartLocation = GetActorLocation();
	GlobalDirection = (GetTransform().TransformPosition(Direction) - GlobalStartLocation).GetSafeNormal();
	GlobalTargetLocation = GlobalStartLocation + (GlobalDirection * MoveDistance);
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasAuthority() && ActiveTriggers >= 1)
	{
		FVector Location = GetActorLocation();

		if (GoForward)
		{
			if ((GlobalStartLocation - Location).Length() >= MoveDistance)
				GoForward = !GoForward;
		}
		else
		{
			if ((Location - GlobalTargetLocation).Length() >= MoveDistance)
			{
				GoForward = !GoForward;
			}
		}

		if (GoForward)
			Location += (GlobalDirection * Speed * DeltaTime);
		else
			Location -= (GlobalDirection * Speed * DeltaTime);

		SetActorLocation(Location);
	}
}

void AMovingPlatform::AddActiveTrigger()
{
	ActiveTriggers++;
}

void AMovingPlatform::RemoveActiveTrigger()
{
	ActiveTriggers--;
}