// Fill out your copyright notice in the Description page of Project Settings.


#include "Knight.h"

// Sets default values
AKnight::AKnight()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_BODY(TEXT("SkeletalMesh'/Game/AnimationTest/KnightCharacter/Knight/knight__1_.knight__1_'"));
	if (SK_BODY.Succeeded())
	{
		// 캐릭터에서 상속된 메시에 스켈레탈 메시  설정
		GetMesh()->SetSkeletalMesh(SK_BODY.Object);
	}
	// 애니메이션 모드 설정
	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);

	// 애니메이션 블루프린트 가져오기 : 클래스르르 가져오는 것이기 때문에 마지막에 _C를 붙여야함
	static ConstructorHelpers::FClassFinder<UAnimInstance> ANIM(
		TEXT("AnimBlueprint'/Game/AnimationTest/KnightCharacter/Animations/ABP_Knight.ABP_Knight_C'")
	);
	if (ANIM.Succeeded())
	{
		// 애니메이션 블루프린트를 설정
		GetMesh()->SetAnimInstanceClass(ANIM.Class);
	}
}

// Called when the game starts or when spawned
void AKnight::BeginPlay()
{
	Super::BeginPlay();
	
}

void AKnight::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	UAnimInstance* TempAnimInstance = GetMesh()->GetAnimInstance();
	AnimInstance = Cast<UMyAnimInstance>(TempAnimInstance);

	if (AnimInstance == nullptr) return;

	AnimInstance->OnMontageEnded.AddDynamic(this, &AKnight::OnAttackMontageEnded);

	AnimInstance->OnPlayMontageNotifyBegin.AddDynamic(this, &AKnight::OnAttackMontageNotifyBegin);
}

// Called every frame
void AKnight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AKnight::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("MouseLeft", IE_Pressed, this, &AKnight::DoAttack);

	PlayerInputComponent->BindAxis("MoveForward", this, &AKnight::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AKnight::MoveRight);
	PlayerInputComponent->BindAxis("LookRight", this, &AKnight::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AKnight::AddControllerPitchInput);
}

void AKnight::OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	if (Montage != AnimInstance->GetAttackMontage()) return;

	UE_LOG(LogTemp, Warning, TEXT("Montage Ended"));
}

void AKnight::OnAttackMontageNotifyBegin(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointPayload)
{
	AnimInstance->SetAttackCount(AnimInstance->GetAttackCount() - 1);
	if (AnimInstance->GetAttackCount() < 0) 
	{
		AnimInstance->Montage_Stop(0.25, AnimInstance->GetAttackMontage());
		AnimInstance->SetAttackCount(0);
	}
}

void AKnight::DoAttack()
{
	if (AnimInstance != nullptr)
	{
		AnimInstance->Attack();
	}
}

void AKnight::MoveForward(float InputAxis)
{
	if ((Controller == nullptr) || (InputAxis == 0.0f)) return;

	if (AnimInstance->Montage_IsPlaying(AnimInstance->GetAttackMontage())) return;

	// Find out which way is forward
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	// Get forward vector
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(Direction, InputAxis);
}

void AKnight::MoveRight(float InputAxis)
{
	if ((Controller == nullptr) || (InputAxis == 0.0f)) return;

	if (AnimInstance->Montage_IsPlaying(AnimInstance->GetAttackMontage())) return;

	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	// Get right vector
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	// Add Movement
	AddMovementInput(Direction, InputAxis);
}

