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
	if (!ensure(MovementComponent != nullptr)) return;

	float LerpRatio = ClientTimeSinceUpdate / ClientTimeBetweenLastUpdate;

	FHermiteCubicSpline Spline = CreateSpline();

	InterpolateLocation(Spline, LerpRatio);

	InterpolateVelocity(Spline, LerpRatio);

	InterpolateRotation(LerpRatio);
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
	if (!ensure(MovementComponent != nullptr)) return;

	ClientTimeBetweenLastUpdate = ClientTimeSinceUpdate;
	ClientTimeSinceUpdate = 0;

	if (!ensure(MeshOffsetRoot != nullptr)) return;
	ClientStartTransform.SetLocation(MeshOffsetRoot->GetComponentLocation());
	ClientStartTransform.SetRotation(MeshOffsetRoot->GetComponentQuat());
	ClientStartVelocity = MovementComponent->GetVelocity();

	GetOwner()->SetActorTransform(ServerState.Transform);
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

float UGoKartMovementReplicator::VelocityToDerivative()
{
	return ClientTimeBetweenLastUpdate * 100.0f; // cm - > m
}

FHermiteCubicSpline UGoKartMovementReplicator::CreateSpline()
{
	FHermiteCubicSpline Spline;

	Spline.StartLocation = ClientStartTransform.GetLocation();
	Spline.StartDerivative = ClientStartVelocity * VelocityToDerivative();
	Spline.TargetLocation = ServerState.Transform.GetLocation();
	Spline.TargetDerivative = ServerState.Velocity * VelocityToDerivative();

	return Spline;
}

void UGoKartMovementReplicator::InterpolateLocation(const FHermiteCubicSpline& Spline, float LerpRatio)
{
	// Cubic Interpolation


	FVector NextLocation = Spline.InterpolateLocation(LerpRatio);

	if (!ensure(MeshOffsetRoot != nullptr)) return;
	MeshOffsetRoot->SetWorldLocation(NextLocation);

	//GetOwner()->SetActorLocation(NextLocation);
}

void UGoKartMovementReplicator::InterpolateVelocity(const FHermiteCubicSpline& Spline, float LerpRatio)
{
	// Set Velocity

	FVector NewDerivative = Spline.InterpolateDerivative(LerpRatio);
	FVector NewVelocity = NewDerivative / VelocityToDerivative();

	MovementComponent->SetVelocity(NewVelocity);
}

void UGoKartMovementReplicator::InterpolateRotation(float LerpRatio)
{
	FQuat NextRotation = FQuat::Slerp(ClientStartTransform.GetRotation(), ServerState.Transform.GetRotation(), LerpRatio);

	if (!ensure(MeshOffsetRoot != nullptr)) return;
	MeshOffsetRoot->SetWorldRotation(NextRotation);

	//GetOwner()->SetActorRotation(NextRotation);
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

	ClientSimulatedTime += Move.DeltaTime;
	MovementComponent->SimulateMove(Move);

	UpdateServerState(Move);
}

bool UGoKartMovementReplicator::Server_ReceiveMove_Validate(const FGoKartMove& Value)
{
	float ProposedTmie = ClientSimulatedTime + Value.DeltaTime;
	
	return Value.IsValid() && ProposedTmie < GetWorld()->TimeSeconds;
}