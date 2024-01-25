//Connor Summerhill 2023


#include "Character/NZP_PlayerState.h"

#include "Net/UnrealNetwork.h"

ANZP_PlayerState::ANZP_PlayerState()
{
	CurrentPoints = 0;
}

int64 ANZP_PlayerState::GetCurrentPoints() const
{
	return CurrentPoints;
}

int64 ANZP_PlayerState::GetTotalPoints() const
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

void ANZP_PlayerState::OnRep_CurrentPoints()
{
	UpdateCurrentPoints.ExecuteIfBound(CurrentPoints);
}

void ANZP_PlayerState::AddPoints(int64 PointsToAdd)
{
	//TODO: Checks for point increases (eg. Double Points)
	CurrentPoints += PointsToAdd;
	TotalPoints += PointsToAdd;
}

bool ANZP_PlayerState::SpendPoints(int64 PointsToTake)
{
	if (CurrentPoints < PointsToTake)
	{
		return false;
	}
	CurrentPoints -= PointsToTake;
	return true;
}

void ANZP_PlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME(ANZP_PlayerState, CurrentPoints);
}

void ANZP_PlayerState::SetPositionInTeam_Implementation(int NewPositionNumber)
{
	PositionInTeam = NewPositionNumber;
}

void ANZP_PlayerState::SetTeamNumberOnServer_Implementation(const int NewTeamNumber)
{
	TeamNumber = NewTeamNumber;
}
