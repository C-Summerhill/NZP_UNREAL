// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Character/NZP_PlayerController.h"
#include "Character/NZP_PlayerState.h"
#include "GameFramework/GameModeBase.h"
#include "NZP_UnrealGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class NZP_UNREAL_API ANZP_UnrealGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	ANZP_UnrealGameModeBase();

public:
	virtual void OnPostLogin(AController* NewPlayer) override;

public:
	UPROPERTY(EditDefaultsOnly)
	int MaxPlayersPerTeam = 4;

	UPROPERTY(EditDefaultsOnly)
	int PositionToAddTeamMembers = 0;

	UPROPERTY()
	int CurrentTeam = 0;
};
