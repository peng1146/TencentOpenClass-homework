// Copyright Epic Games, Inc. All Rights Reserved.

#include "Homework1GameMode.h"
#include "Homework1Character.h"
#include "UObject/ConstructorHelpers.h"

AHomework1GameMode::AHomework1GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
