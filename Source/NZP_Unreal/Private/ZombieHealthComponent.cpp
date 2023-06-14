// Connor Summerhill 2023
#include "ZombieHealthComponent.h"

#include "AI/NZP_ZombieCharacter.h"
#include "Character/NZP_PlayerCharacter.h"
#include "Character/NZP_PlayerState.h"

void UZombieHealthComponent::Death(FGameplayTag DamageType, AActor* ActorSource, ELocationHit LocationHit,
                                   int64 PointForKill, int64 PointForHeadshotKill)
{
 	Super::Death(DamageType, ActorSource, LocationHit, PointForKill, PointForHeadshotKill);

 	if (ANZP_ZombieCharacter* ZombieCharacter = Cast<ANZP_ZombieCharacter>(GetOwner()))
 	{
 		if(ANZP_PlayerCharacter* PlayerCharacter = Cast<ANZP_PlayerCharacter>(ActorSource))
 		{
 			Cast<ANZP_PlayerState>(PlayerCharacter->GetPlayerState())->AddPoints(
				 LocationHit==Head ? PointForHeadshotKill : PointForKill);
 		}
		
 		//TODO: Update wave system to let it know I died.
 		//TODO: Ready death animation.
 	}
}
