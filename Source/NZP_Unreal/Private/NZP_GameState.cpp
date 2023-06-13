// Fill out your copyright notice in the Description page of Project Settings.


#include "NZP_GameState.h"

#include "Character/NZP_PlayerState.h"
#include "GameFramework/PlayerState.h"

void ANZP_GameState::AddPlayerState(APlayerState* PlayerState)
{
	if (!PlayerState->IsInactive())
	{
		NZPPlayerState.AddUnique(Cast<ANZP_PlayerState>(PlayerState));
	}
	Super::AddPlayerState(PlayerState);
}

void ANZP_GameState::RemovePlayerState(APlayerState* PlayerState)
{
	for (int32 i=0; i<PlayerArray.Num(); i++)
	{
		if (NZPPlayerState[i] == PlayerState)
		{
			NZPPlayerState.RemoveAt(i, 1);
			return;
		}
	}
	Super::RemovePlayerState(PlayerState);
}