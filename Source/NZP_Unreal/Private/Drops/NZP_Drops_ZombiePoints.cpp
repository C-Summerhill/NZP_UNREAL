//Connor Summerhill 2023


#include "Drops/NZP_Drops_ZombiePoints.h"

#include "Character/NZP_PlayerState.h"

ANZP_Drops_ZombiePoints::ANZP_Drops_ZombiePoints()
{
	
}

ANZP_Drops_ZombiePoints::ANZP_Drops_ZombiePoints(const FObjectInitializer& ObjectInitializer, float newBasePointsGiven)
{
	BasePointsGiven = newBasePointsGiven;
}

void ANZP_Drops_ZombiePoints::PickupFunction(ANZP_PlayerCharacter* OtherActor)
{
	Cast<ANZP_PlayerState>(OtherActor->GetPlayerState())->AddPoints(BasePointsGiven);
	Destroy(); //For some reason, can't be done via inheritance
	Super::PickupFunction(OtherActor);
}