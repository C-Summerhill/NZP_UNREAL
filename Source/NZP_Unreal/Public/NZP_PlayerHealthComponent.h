// Connor Summerhill 2023

#pragma once

#include "CoreMinimal.h"
#include "NZP_HealthComponent.h"
#include "NZP_PlayerHealthComponent.generated.h"

/**
 * 
 */
UCLASS()
class NZP_UNREAL_API UNZP_PlayerHealthComponent : public UNZP_HealthComponent
{
	GENERATED_BODY()

	UNZP_PlayerHealthComponent();

	virtual void Death(FGameplayTag DamageType, AActor* ActorSource,
		ELocationHit LocationHit, int64 PointForKill, int64 PointForHeadshotKill) override;
};
