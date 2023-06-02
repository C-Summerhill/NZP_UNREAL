// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "NZP_PlayerState.generated.h"

/**
 * 
 */
UCLASS()
class NZP_UNREAL_API ANZP_PlayerState : public APlayerState
{
	GENERATED_BODY()

	ANZP_PlayerState();

public:

	UFUNCTION(BlueprintCallable)
	int64 GetCurrentPoints();
	
	UFUNCTION(BlueprintCallable)
	int64 GetTotalPoints();

protected:
	void SetCurrentPoints(int64 NewCurrentPoints);
	void SetTotalPoints(int64 NewCurrentPoints);

	UFUNCTION(BlueprintCallable)
	void AddPoints(int64 PointsToAdd);

	UFUNCTION(BlueprintCallable)
	bool SpendPoints(int64 PointsToTake);
	
private:
	int64 CurrentPoints;
	int64 TotalPoints;
	
};
