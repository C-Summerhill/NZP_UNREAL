// Connor Summerhill 2023


#include "HealthComponent/NZP_PlayerHealthComponent.h"

#include "Character/NZP_PlayerCharacter.h"

UNZP_PlayerHealthComponent::UNZP_PlayerHealthComponent()
{
	MaxHealth = 100;
	CurrentHealth = 100;
	bCanRegeneratedHealth = true;
}

void UNZP_PlayerHealthComponent::Death(FGameplayTag DamageType, AActor* ActorSource, ELocationHit LocationHit,
                                   int64 PointForKill, int64 PointForHeadshotKill)
{
	Super::Death(DamageType, ActorSource, LocationHit, PointForKill, PointForHeadshotKill);

	if (ANZP_PlayerCharacter* PlayerCharacter = Cast<ANZP_PlayerCharacter>(GetOwner()))
	{
		//TODO: Put into downed mode.
		//TODO: see if other players are alive
			//TODO: Start end of game.
	}
}
