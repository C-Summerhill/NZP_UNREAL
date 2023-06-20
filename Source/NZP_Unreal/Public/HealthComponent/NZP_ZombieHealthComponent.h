// Connor Summerhill 2023

#pragma once

#include "CoreMinimal.h"
#include "NZP_HealthComponent.h"
#include "NZP_ZombieHealthComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=("Health Component"))
class NZP_UNREAL_API UNZP_ZombieHealthComponent : public UNZP_HealthComponent
{
	GENERATED_BODY()

	virtual void Death(FGameplayTag DamageType, AActor* ActorSource,
		ELocationHit LocationHit, int64 PointForKill, int64 PointForHeadshotKill) override;

public:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class ANZP_Drops_ZombiePoints> Anzp_Drops_ZombiePointsReference;
};
