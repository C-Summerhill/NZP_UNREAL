//Connor Summerhill 2023

#pragma once

#include "CoreMinimal.h"
#include "NZP_DropsCore.h"
#include "NZP_DropsNuke.generated.h"

/**
 * 
 */
UCLASS()
class NZP_UNREAL_API ANZP_DropsNuke : public ANZP_DropsCore
{
	GENERATED_BODY()

public:	
	virtual void PickupFunction(ANZP_PlayerCharacter* OtherActor) override;

public:
	UPROPERTY(EditDefaultsOnly)
	int64 BasePointsGiven = 400;

	UPROPERTY(EditDefaultsOnly)
	FGameplayTag NukeDamageType = FGameplayTag::RequestGameplayTag("DamageType.Nuke");
};