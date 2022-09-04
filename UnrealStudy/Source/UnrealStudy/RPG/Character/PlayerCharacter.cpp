// Fill out your copyright notice in the Description page of Project Settings.


#include "./PlayerCharacter.h"
#include "./RPGPlayerController.h"

#include "Blueprint/UserWidget.h"
#include "Kismet/KismetSystemLibrary.h"

#include "../UI/Inventory/ItemWidget.h"
#include "../UI/Inventory/InventoryGrid.h"

APlayerCharacter::APlayerCharacter()
{
#pragma region Mesh / Animation Setting

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_BODY(TEXT("SkeletalMesh'/Game/RPG/Meshes/Knight/knight.knight'"));
	if (SK_BODY.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SK_BODY.Object);
	}
	else
	{
		// TODO : 오류코드 만들어서 오류발생 표시하기 ASSERT였나
		return;
	}
		
	// 애니메이션 모드 설정
	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);

	// 애니메이션 블루프린트 가져오기 : 클래스를 가져오기 때문에 _C붙이기
	static ConstructorHelpers::FClassFinder<UAnimInstance> ANIM(
		TEXT("AnimBlueprint'/Game/RPG/Blueprints/Animations/Knight/ABP_Knight.ABP_Knight_C'")
	);
	if (ANIM.Succeeded())
	{
		// 애니메이션 블루프린트(인스턴스클래스) 설정
		GetMesh()->SetAnimInstanceClass(ANIM.Class);
	}
	else
	{
		// TODO : 오류코드 만들어서 오류발생 표시하기 ASSERT였나
		return;
	}

#pragma endregion
	
#pragma region Component Setting

	GetMesh()->SetRelativeLocationAndRotation(FVector(0, 0, -90.0f), FQuat(FRotator(0, -90.0f, 0)));

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(FName("SpringArmComponet"));
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(FName("CameraComponent"));

	CameraComponent->SetupAttachment(SpringArmComponent);
	SpringArmComponent->SetupAttachment(GetMesh());
	SpringArmComponent->bUsePawnControlRotation = true;

#pragma endregion

#pragma region HUD Setting
	// HUD
	HUDClass = nullptr;
	HUDWidget = nullptr;

	ConstructorHelpers::FClassFinder<UUserWidget> Temp(TEXT("Blueprint'/Game/RPG/Blueprints/UI/Inventory/WBP_InventoryGrid.WBP_InventoryGrid_C'"));
	if (Temp.Succeeded())
		HUDClass = Temp.Class;
#pragma endregion
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
#pragma region InventorySetting

	Inventory = NewObject<UInventory>();;
	Inventory->Init(Rows, Columns);
#pragma endregion
#pragma region Create Widget

	if (IsLocallyControlled() && HUDClass)
	{
		ARPGPlayerController* RPC = GetController<ARPGPlayerController>();
		if (IsValid(RPC))
		{
			HUDWidget = CreateWidget<UUserWidget>(RPC, HUDClass);

			//Cast<UItemWidget>(HUDWidget)->SetItemData(FItemData());
			Cast<UInventoryGrid>(HUDWidget)->Init(Inventory, TileSize);

			if (IsValid(HUDWidget))
				HUDWidget->AddToPlayerScreen();
		}
	}
#pragma endregion
}
void APlayerCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
#pragma region Remove Widget
	if (HUDWidget)
	{
		HUDWidget->RemoveFromParent();
		// We can't destroy the widget directly, let the GC take care of it.
		HUDWidget = nullptr;
	}
#pragma endregion

	Super::EndPlay(EndPlayReason);
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Interact", EInputEvent::IE_Pressed, this, &APlayerCharacter::Interact);

	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);

	PlayerInputComponent->BindAxis("LookUp", this, &APlayerCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookRight", this, &APlayerCharacter::AddControllerYawInput);
}

void APlayerCharacter::Interact()
{
	FVector Start = CameraComponent->GetComponentLocation();
	FVector End = Start + CameraComponent->GetForwardVector() * 500.0f;

	FHitResult HitResult;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	if (GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECollisionChannel::ECC_Visibility, Params))
	{
		if (AActor* Actor = HitResult.GetActor())
		{
			UE_LOG(LogTemp, Warning, TEXT("Hit Actor : %s"), *Actor->GetName());

			if (Actor->GetClass()->ImplementsInterface(UInteractableInterface::StaticClass()))
			{
				Cast<IInteractableInterface>(Actor)->Interact();
			}
		}
	}
}

void APlayerCharacter::MoveForward(float InputAxis)
{
	if ((Controller == nullptr) || (InputAxis == 0.0)) return;

	// Find out which way is forward
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotaion(0, Rotation.Yaw, 0);

	// Get Forward Vector
	const FVector Direction = FRotationMatrix(YawRotaion).GetUnitAxis(EAxis::X);
	AddMovementInput(Direction, InputAxis);
}

void APlayerCharacter::MoveRight(float InputAxis)
{
	if ((Controller == nullptr) || (InputAxis == 0.0)) return;

	// Find out which way is forward
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotaion(0, Rotation.Yaw, 0);

	// Get Forward Vector
	const FVector Direction = FRotationMatrix(YawRotaion).GetUnitAxis(EAxis::Y);
	AddMovementInput(Direction, InputAxis);
}

