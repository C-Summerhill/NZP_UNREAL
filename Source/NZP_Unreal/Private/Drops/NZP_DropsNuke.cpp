//Connor Summerhill 2023


#include "Drops/NZP_DropsNuke.h"

#include "EngineUtils.h"
#include "NZP_GameState.h"
#include "Gamemodes/NZP_UnrealGameModeBase.h"
#include "HealthComponent/NZP_ZombieHealthComponent.h"
#include "AI/NZP_ZombieCharacter.h"
#include "Character/NZP_PlayerCharacter.h"

ANZP_DropsNuke::ANZP_DropsNuke()
{
	bReplicates = true;
}

void ANZP_DropsNuke::PickupFunction(ANZP_PlayerCharacter* OtherActor)
{
	if (OtherActor && HasAuthority())
	{
		//Kill all zombies
		int NukeKills = 0;

		//TODO: To be replaced with a call to WaveSystem when it gets created as that will have reference to all alive enemy classes.
		for (TActorIterator<AActor> It(GetWorld(), ANZP_ZombieCharacter::StaticClass()); It; ++It)
		{
			ANZP_ZombieCharacter* Zombie = Cast<ANZP_ZombieCharacter>(*It);
			Zombie->ZombieHealthComponent->TakeDamage(Zombie->ZombieHealthComponent->MaxHealth, NukeDamageType, OtherActor, ELocationHit::LowerBody, 0,0);
			NukeKills++;
		}

		//TODO [ACHIEVEMENT]: Achievement system trigger check [NZP: THE F BOMB: Kill only 1 zombie with a Nuke]

		const ANZP_PlayerState* PlayerState = Cast<ANZP_PlayerState>(OtherActor->GetPlayerState());
		ANZP_GameState* GameState = GetWorld()->GetGameState<ANZP_GameState>();

		//Reward team for collecting Nuke
		for (int PlayersCheckedCount = 0; PlayersCheckedCount < GameState->NZPPlayerStates.Num(); PlayersCheckedCount++)
		{
			if (GameState->NZPPlayerStates[PlayersCheckedCount]->TeamNumber == PlayerState->TeamNumber)
			{
				GameState->NZPPlayerStates[PlayersCheckedCount]->AddPoints(BasePointsGiven);
			}
		}
	}

	Destroy();

	//Will Destroy the actor when used.
	Super::PickupFunction(OtherActor);
}
