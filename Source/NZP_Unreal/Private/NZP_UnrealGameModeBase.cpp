// Copyright Epic Games, Inc. All Rights Reserved.


#include "NZP_UnrealGameModeBase.h"

#include "Character/NZP_PlayerController.h"
#include "Character/PlayerCharacter.h"

ANZP_UnrealGameModeBase::ANZP_UnrealGameModeBase()
{
	DefaultPawnClass = APlayerCharacter::StaticClass();
	PlayerControllerClass = ANZP_PlayerController::StaticClass();
}