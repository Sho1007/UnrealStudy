// Fill out your copyright notice in the Description page of Project Settings.


#include "GoKart.h"
#include "Components/SkeletalMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/BoxComponent.h"
#include "DrawDebugHelpers.h"


// Sets default values
AGoKart::AGoKart()
{
	bReplicates = true;
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SetReplicateMovement(false);

	MovementComponent = CreateDefaultSubobject<UGoKartMovementComponent>(FName("MovementComponent"));
	if (!ensure(MovementComponent != nullptr)) return;

	MovementReplicator = CreateDefaultSubobject<UGoKartMovementReplicator>(FName("MovementReplicator"));
	if (!ensure(MovementReplicator != nullptr)) return;

	MovementReplicator->SetMovementComponent(MovementComponent);

	Box = CreateDefaultSubobject<UBoxComponent>(FName("Box"));
	Box->bHiddenInGame = false;
	RootComponent = Box;

	MeshOffsetRoot = CreateDefaultSubobject<USceneComponent>(FName("MeshOffsetRoot"));
	MovementReplicator->SetMeshOffsetRoot(MeshOffsetRoot);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(FName("Mesh"));
	SpringArm = CreateDefaultSubobject <USpringArmComponent>(FName("SpringArm"));
	Camera = CreateDefaultSubobject<UCameraComponent>(FName("Camera"));


	Camera->SetupAttachment(SpringArm);
	SpringArm->SetupAttachment(Mesh);
	Mesh->SetupAttachment(MeshOffsetRoot);
	MeshOffsetRoot->SetupAttachment(Box);
}

// Called when the game starts or when spawned
void AGoKart::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		NetUpdateFrequency = 1;
	}
}

FString GetEnumText(ENetRole Role)
{
	switch (Role)
	{
	case ROLE_None:
		return "None";
	case ROLE_SimulatedProxy:
		return "SimulatedProxy";
	case ROLE_AutonomousProxy:
		return "AtuonomousProxy";
	case ROLE_Authority:
		return "Authority";
	default:
		return "Error";
	}
}

// Called every frame
void AGoKart::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DrawDebugString(GWorld, FVector(0, 0, 100), GetEnumText(GetLocalRole()), this, FColor::White, DeltaTime);
}

// Called to bind functionality to input
void AGoKart::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AGoKart::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AGoKart::MoveRight);
}

void AGoKart::MoveForward(float Value)
{
	if (!ensure(MovementComponent != nullptr)) return;

	MovementComponent->SetThrottle(Value);
}

void AGoKart::MoveRight(float Value)
{
	if (!ensure(MovementComponent != nullptr)) return;

	MovementComponent->SetSteeringThrow(Value);
}