// Connor Summerhill 2023


#include "GameInstanceSubsystem/WaveInstance_SubSystem.h"

#include "Net/UnrealNetwork.h"

void UWaveInstance_SubSystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	
}

void UWaveInstance_SubSystem::OnRep_CurrentWave()
{
	CurrentWaveReplication.Broadcast(CurrentWave);
}

void UWaveInstance_SubSystem::OnRep_WaveStarted()
{
}

void UWaveInstance_SubSystem::StartWaveSystem_Implementation()
{
	if (!bWaveStarted)
	{
		bWaveStarted = true;
	}
}

void UWaveInstance_SubSystem::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UWaveInstance_SubSystem, CurrentWave);
}
