// Connor Summerhill 2023


#include "PlayerHealthComponent.h"

#include "Character/NZP_PlayerCharacter.h"

UPlayerHealthComponent::UPlayerHealthComponent()
{
	MaxHealth = 100;
	CurrentHealth = 100;
}

void UPlayerHealthComponent::Death(FGameplayTag DamageType, AActor* ActorSource, ELocationHit LocationHit,
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
