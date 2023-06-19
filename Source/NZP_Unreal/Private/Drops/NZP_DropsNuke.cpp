//Connor Summerhill 2023


#include "Drops/NZP_DropsNuke.h"

#include "EngineUtils.h"
#include "NZP_GameState.h"
#include "NZP_UnrealGameModeBase.h"
#include "HealthComponent/NZP_ZombieHealthComponent.h"
#include "AI/NZP_ZombieCharacter.h"
#include "Character/NZP_PlayerCharacter.h"

void ANZP_DropsNuke::PickupFunction(ANZP_PlayerCharacter* OtherActor)
{
	if (OtherActor && HasAuthority())
	{
		//Kill all zombies
		int NukeKills = 0;
		for (TActorIterator<ANZP_ZombieCharacter> Zombie(GetWorld()); Zombie; ++Zombie)
		{
			//Breaking. Might look at using an interface
			Zombie->ZombieHealthComponent->TakeDamage(Zombie->ZombieHealthComponent->MaxHealth, NukeDamageType,
			                                          OtherActor
			                                          , Head, 0, 0);
			NukeKills++;
		}

		//TODO: Achievement system trigger check [NZP: THE F BOMB: Kill only 1 zombie with a Nuke]

		const ANZP_PlayerState* PlayerState = Cast<ANZP_PlayerState>(OtherActor->GetPlayerState());
		ANZP_GameState* GameState = GetWorld()->GetGameState<ANZP_GameState>();
		//Reward team for collecting Nuke
		for (int PlayersCheckedCount = 0; PlayersCheckedCount < GameState->NZPPlayerState.Num(); PlayersCheckedCount++)
		{
			if (GameState->NZPPlayerState[PlayersCheckedCount]->TeamNumber == PlayerState->TeamNumber)
			{
				GameState->NZPPlayerState[PlayersCheckedCount]->AddPoints(BasePointsGiven);
			}
		}
	}

	Destroy();

	//Will Destroy the actor when used.
	Super::PickupFunction(OtherActor);
}
