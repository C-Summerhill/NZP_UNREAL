//Connor Summerhill 2023


#include "GameStates/NZP_GameState.h"

#include "Character/NZP_PlayerState.h"
#include "GameFramework/PlayerState.h"

ANZP_GameState::ANZP_GameState()
{
	
}

void ANZP_GameState::BeginPlay()
{
	Super::BeginPlay();
	
	if (!CurrentGameModeSettings)
	{
		CurrentGameModeSettings = GetWorld()->SpawnActor<UNZP_GamemodeSettings_DataAsset>();
	}
}

void ANZP_GameState::AddPlayerState(APlayerState* PlayerState)
{
	if (!PlayerState->IsInactive())
	{
		NZPPlayerStates.AddUnique(Cast<ANZP_PlayerState>(PlayerState));
	}
	Super::AddPlayerState(PlayerState);
}

void ANZP_GameState::RemovePlayerState(APlayerState* PlayerState)
{
	for (int32 i = 0; i < PlayerArray.Num(); i++)
	{
		if (NZPPlayerStates[i] == PlayerState)
		{
			NZPPlayerStates.RemoveAt(i, 1);
			return;
		}
	}
	Super::RemovePlayerState(PlayerState);
}

UNZP_GamemodeSettings_DataAsset* ANZP_GameState::GetCurrentGameModeSettings()
{
	return CurrentGameModeSettings;
}