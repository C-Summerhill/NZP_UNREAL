// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "Character/NZP_PlayerState.h"
#include "NZP_GameState.generated.h"

/**
 * 
 */
UCLASS()
class NZP_UNREAL_API ANZP_GameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	//UPROPERTY(Transient, BlueprintReadOnly, Category=GameState)
	TArray<ANZP_PlayerState*> NZPPlayerState;

	virtual void AddPlayerState(APlayerState* PlayerState) override;

	/** Remove PlayerState from the PlayerArray. */
	virtual void RemovePlayerState(APlayerState* PlayerState) override;
};