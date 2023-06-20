// Connor Summerhill 2023
#include "HealthComponent/NZP_ZombieHealthComponent.h"

#include "AI/NZP_ZombieCharacter.h"
#include "Character/NZP_PlayerCharacter.h"
#include "Character/NZP_PlayerState.h"
#include "Drops/NZP_Drops_ZombiePoints.h"

void UNZP_ZombieHealthComponent::Death(FGameplayTag DamageType, AActor* ActorSource, ELocationHit LocationHit,
                                       int64 PointForKill, int64 PointForHeadshotKill)
{
 	Super::Death(DamageType, ActorSource, LocationHit, PointForKill, PointForHeadshotKill);

 	if (ANZP_ZombieCharacter* ZombieCharacter = Cast<ANZP_ZombieCharacter>(GetOwner()))
 	{
 		if(PointForKill != 0 || PointForHeadshotKill != 0)
 		{
 			if(const ANZP_PlayerCharacter* PlayerCharacter = Cast<ANZP_PlayerCharacter>(ActorSource))
 			{
 				Cast<ANZP_PlayerState>(PlayerCharacter->GetPlayerState())->AddPoints(
					 LocationHit==Head ? PointForHeadshotKill : PointForKill);
 			}
 		}
 		//TODO: Update wave system to let it know I died.
 		//TODO: Ready death animation.
 		GetWorld()->SpawnActor<ANZP_Drops_ZombiePoints>(Anzp_Drops_ZombiePointsReference, ZombieCharacter->GetActorLocation(), FRotator(0, 0, 0));
 		ZombieCharacter->Destroy();
 	}
}