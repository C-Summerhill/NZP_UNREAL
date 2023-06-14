// Copyright Epic Games, Inc. All Rights Reserved.


#include "NZP_UnrealGameModeBase.h"

#include "NZP_GameState.h"
#include "Character/NZP_PlayerController.h"
#include "Character/NZP_PlayerCharacter.h"
#include "Character/NZP_PlayerState.h"

ANZP_UnrealGameModeBase::ANZP_UnrealGameModeBase()
{
	DefaultPawnClass = ANZP_PlayerCharacter::StaticClass();
	PlayerControllerClass = ANZP_PlayerController::StaticClass();
	PlayerStateClass = ANZP_PlayerState::StaticClass();
	GameStateClass = ANZP_GameState::StaticClass();
}

void ANZP_UnrealGameModeBase::OnPostLogin(AController* NewPlayer)
{
	Super::OnPostLogin(NewPlayer);

	if (ANZP_PlayerState* newPlayerState = Cast<ANZP_PlayerController>(NewPlayer)->GetPlayerState<ANZP_PlayerState>())
	{
		newPlayerState->SetTeamNumberOnServer(CurrentTeam);
		newPlayerState->SetPositionInTeam(PositionToAddTeamMembers);
		PositionToAddTeamMembers++;
		
		if (PositionToAddTeamMembers == MaxPlayersPerTeam)
		{
			PositionToAddTeamMembers = 0;
			CurrentTeam++;
		}
	}
}
