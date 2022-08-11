// Fill out your copyright notice in the Description page of Project Settings.


#include "GoKartMovementReplicator.h"
#include "GoKart.h"
#include "Net/UnrealNetwork.h"

// Sets default values for this component's properties
UGoKartMovementReplicator::UGoKartMovementReplicator()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	SetIsReplicated(true);
	
}


// Called when the game starts
void UGoKartMovementReplicator::BeginPlay()
{
	Super::BeginPlay();
	
	// ...
}

void UGoKartMovementReplicator::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UGoKartMovementReplicator, ServerState);
}

void UGoKartMovementReplicator::ClientTick(float DeltaTime)
{
	ClientTimeSinceUpdate += DeltaTime;

	if (ClientTimeBetweenLastUpdate < KINDA_SMALL_NUMBER) return;

	float LerpRatio = ClientTimeSinceUpdate / ClientTimeBetweenLastUpdate;

	FVector NextLocation = FMath::LerpStable(ClientStartLocation, ServerState.Transform.GetLocation(), LerpRatio);

	GetOwner()->SetActorLocation(NextLocation);
}


// Called every frame
void UGoKartMovementReplicator::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	if (!ensure(MovementComponent != nullptr)) return;

	FGoKartMove LastMove = MovementComponent->GetLastMove();

	if (GetOwner()->GetLocalRole() == ROLE_AutonomousProxy)
	{
		UnacknowledgeMoves.Add(LastMove);
		Server_ReceiveMove(LastMove);
	}
	// We are the server and in control of the pawn
	// 의문점)	GetOwner()->GetLocalRole() == ROLE_Authority && 를 지웠는데,
	//			어째서 RemoteRoll == SimulatedProxy 인게 LocalRole 이 Authority인걸 증명하는지? Client 를 다른 Client가 봤을 때도 SimulatedProxy가 아닌가?
	// 해답)		내가 서버일 때는 RemoteRoll == SimulatedProxy 이고 내가 Client 일 때, 다른 Server 나 Client 의 Authority 혹은 AutonomousProxy 는
	//			LocalRole == SimulatedProxy 이다.
	if (GetOwner()->GetRemoteRole() == ROLE_SimulatedProxy)
	{
		UpdateServerState(LastMove);
	}
	if (GetOwner()->GetLocalRole() == ROLE_SimulatedProxy)
	{
		ClientTick(DeltaTime);
	}
}



void UGoKartMovementReplicator::ClearAcknowledgeMoves(FGoKartMove LastMove)
{
	TArray<FGoKartMove> NewMoves;

	for (const FGoKartMove& Move : UnacknowledgeMoves)
	{
		if (Move.Time > LastMove.Time)
		{
			NewMoves.Add(Move);
		}
	}

	UnacknowledgeMoves = NewMoves;
}

void UGoKartMovementReplicator::SimulatedProxy_OnRep_ServerState()
{
	ClientTimeBetweenLastUpdate = ClientTimeSinceUpdate;
	ClientTimeSinceUpdate = 0;

	ClientStartLocation = GetOwner()->GetActorLocation();
}
void UGoKartMovementReplicator::AutonomousProxy_OnRep_ServerState()
{
	if (!ensure(MovementComponent != nullptr)) return;

	GetOwner()->SetActorTransform(ServerState.Transform);
	MovementComponent->SetVelocity(ServerState.Velocity);

	ClearAcknowledgeMoves(ServerState.LastMove);

	for (const FGoKartMove& Move : UnacknowledgeMoves)
	{
		MovementComponent->SimulateMove(Move);
	}
}

void UGoKartMovementReplicator::OnRep_ServerState()
{
	switch (GetOwnerRole())
	{
	case ROLE_SimulatedProxy:
		SimulatedProxy_OnRep_ServerState();
		break;
	case ROLE_AutonomousProxy:
		AutonomousProxy_OnRep_ServerState();
		break;
	}
}

void UGoKartMovementReplicator::UpdateServerState(const FGoKartMove& Move)
{
	ServerState.LastMove = Move;
	ServerState.Transform = GetOwner()->GetActorTransform();
	ServerState.Velocity = MovementComponent->GetVelocity();
}

void UGoKartMovementReplicator::Server_ReceiveMove_Implementation(const FGoKartMove& Move)
{
	if (!ensure(MovementComponent != nullptr)) return;

	MovementComponent->SimulateMove(Move);

	UpdateServerState(Move);
}

bool UGoKartMovementReplicator::Server_ReceiveMove_Validate(const FGoKartMove& Value)
{
	return true;
}