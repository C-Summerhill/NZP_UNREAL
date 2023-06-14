//Connor Summerhill 2023


#include "Drops/NZP_DropsNuke.h"

#include "NZP_GameState.h"
#include "NZP_UnrealGameModeBase.h"
#include "Character/NZP_PlayerCharacter.h"
#include "Kismet/GameplayStatics.h"

void ANZP_DropsNuke::PickupFunction(ANZP_PlayerCharacter* OtherActor)
{
	if (OtherActor && HasAuthority())
	{
		//TODO: Kill all zombies

		ANZP_PlayerState* PlayerState = Cast<ANZP_PlayerState>(OtherActor->GetPlayerState());
		ANZP_GameState* GameState = GetWorld()->GetGameState<ANZP_GameState>();
		//TODO: Reward team for collecting Nuke
		for (int PlayersCheckedCount = 0; PlayersCheckedCount == GameState->NZPPlayerState.Num(); PlayersCheckedCount++)
		{
			if (GameState->NZPPlayerState[PlayersCheckedCount]->TeamNumber == PlayerState->TeamNumber)
			{
				GameState->NZPPlayerState[PlayersCheckedCount]->AddPoints(BasePointsGiven);
			}			
		}
	}
	
	//Will Destory the actor when used.
	Super::PickupFunction(OtherActor);
}