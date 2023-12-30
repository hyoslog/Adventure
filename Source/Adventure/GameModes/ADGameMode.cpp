// Fill out your copyright notice in the Description page of Project Settings.

#include "ADGameMode.h"
#include "UObject/ConstructorHelpers.h"

AADGameMode::AADGameMode()
{
	// set default pawn class to our Blueprinted character
	static const ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Characters/Blueprints/BP_ADCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
