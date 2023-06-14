// Connor Summerhill 2023

#pragma once

#include "CoreMinimal.h"
#include "HealthComponent.h"
#include "PlayerHealthComponent.generated.h"

/**
 * 
 */
UCLASS()
class NZP_UNREAL_API UPlayerHealthComponent : public UHealthComponent
{
	GENERATED_BODY()

	UPlayerHealthComponent();

	virtual void Death(FGameplayTag DamageType, AActor* ActorSource,
		ELocationHit LocationHit, int64 PointForKill, int64 PointForHeadshotKill) override;
};
