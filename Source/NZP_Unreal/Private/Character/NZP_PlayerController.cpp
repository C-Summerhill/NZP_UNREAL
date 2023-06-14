//Connor Summerhill 2023


#include "Character/NZP_PlayerController.h"

bool ANZP_PlayerController::GetCrouchToggle() const
{
	return bToggleCrouched;
}

void ANZP_PlayerController::SetCrouchToggle(bool bNewCrouchState)
{
	bToggleCrouched = bNewCrouchState;
}
