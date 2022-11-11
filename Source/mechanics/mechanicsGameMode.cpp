// Copyright Epic Games, Inc. All Rights Reserved.

#include "mechanicsGameMode.h"
#include "mechanicsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AmechanicsGameMode::AmechanicsGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
