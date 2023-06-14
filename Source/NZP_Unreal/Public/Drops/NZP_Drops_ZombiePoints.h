//Connor Summerhill 2023

#pragma once

#include "CoreMinimal.h"
#include "Drops/NZP_DropsCore.h"
#include "NZP_Drops_ZombiePoints.generated.h"

/**
 * 
 */
UCLASS()
class NZP_UNREAL_API ANZP_Drops_ZombiePoints : public ANZP_DropsCore
{
	GENERATED_BODY()

	ANZP_Drops_ZombiePoints();

	ANZP_Drops_ZombiePoints(const FObjectInitializer& ObjectInitializer, float PointsToDrop);
public:
	virtual void PickupFunction(ANZP_PlayerCharacter* OtherActor) override;

public:
	UPROPERTY(EditAnywhere)
	int64 BasePointsGiven = 250;
};
