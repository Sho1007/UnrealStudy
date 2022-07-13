// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealStudyGameMode.h"
#include "UnrealStudyCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUnrealStudyGameMode::AUnrealStudyGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
