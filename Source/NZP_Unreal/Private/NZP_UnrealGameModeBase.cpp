// Copyright Epic Games, Inc. All Rights Reserved.


#include "NZP_UnrealGameModeBase.h"

#include "Character/NZP_PlayerController.h"
#include "Character/NZP_PlayerCharacter.h"

ANZP_UnrealGameModeBase::ANZP_UnrealGameModeBase()
{
	DefaultPawnClass = ANZP_PlayerCharacter::StaticClass();
	PlayerControllerClass = ANZP_PlayerController::StaticClass();
}