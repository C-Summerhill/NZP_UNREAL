// Connor Summerhill 2023


#include "Gamemodes/NZP_Survival.h"

#include "NZP_GameState.h"
#include "Net/UnrealNetwork.h"

ANZP_Survival::ANZP_Survival() : ANZP_UnrealGameModeBase()
{
	DefaultPawnClass = ANZP_PlayerCharacter::StaticClass();
	PlayerControllerClass = ANZP_PlayerController::StaticClass();
	PlayerStateClass = ANZP_PlayerState::StaticClass();
	GameStateClass = ANZP_GameState::StaticClass(); 
}

void ANZP_Survival::OnRep_CurrentWave()
{
	
}

void ANZP_Survival::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ANZP_Survival, CurrentWave);
}
