// Connor Summerhill 2023

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "WaveInstance_SubSystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCurrentWaveReplication, int64, CurrentWave);

/**
 * 
 */
UCLASS()
class NZP_UNREAL_API UWaveInstance_SubSystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	//Current Wave
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, ReplicatedUsing=OnRep_CurrentWave)
	int64 CurrentWave = 0;

	UPROPERTY(BlueprintAssignable)
	FCurrentWaveReplication CurrentWaveReplication;

	//Has Wave Started
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, ReplicatedUsing=OnRep_WaveStarted)
	bool bWaveStarted;

public:

	UFUNCTION()
	void OnRep_CurrentWave();

	UFUNCTION()
	void OnRep_WaveStarted();

	UFUNCTION(Reliable, Server)
	void StartWaveSystem();
};
