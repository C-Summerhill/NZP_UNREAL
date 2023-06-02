// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/NZP_PlayerState.h"

ANZP_PlayerState::ANZP_PlayerState()
{
	
}

int64 ANZP_PlayerState::GetCurrentPoints()
{
	return CurrentPoints;
}

int64 ANZP_PlayerState::GetTotalPoints()
{
	return TotalPoints;
}

void ANZP_PlayerState::SetCurrentPoints(int64 NewCurrentPoints)
{
	CurrentPoints = NewCurrentPoints;
}

void ANZP_PlayerState::SetTotalPoints(int64 NewCurrentPoints)
{
	TotalPoints = NewCurrentPoints;
}

void ANZP_PlayerState::AddPoints(int64 PointsToAdd)
{
	CurrentPoints += PointsToAdd;
	TotalPoints += PointsToAdd;
}

bool ANZP_PlayerState::SpendPoints(int64 PointsToTake)
{
	if (CurrentPoints < PointsToTake)
	{
		return false;
	}
	else
	{
		CurrentPoints -= PointsToTake;
		return true;
	}
}
