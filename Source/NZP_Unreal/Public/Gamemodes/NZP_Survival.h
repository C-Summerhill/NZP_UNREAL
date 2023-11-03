// Connor Summerhill 2023

#pragma once

#include "CoreMinimal.h"
#include "GameInstanceSubsystem/WaveInstance_SubSystem.h"
#include "Gamemodes/NZP_UnrealGameModeBase.h"
#include "NZP_Survival.generated.h"

/**
 * 
 */
UCLASS()
class NZP_UNREAL_API ANZP_Survival : public ANZP_UnrealGameModeBase
{
	GENERATED_BODY()

	friend UWaveInstance_SubSystem;
	
	ANZP_Survival();

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, ReplicatedUsing=OnRep_CurrentWave)
	int64 CurrentWave = 0;

public:

	UFUNCTION()
	void OnRep_CurrentWave();
};
