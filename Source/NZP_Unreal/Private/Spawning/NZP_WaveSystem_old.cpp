// Connor Summerhill 2023


#include "..\..\Public\Spawning\NZP_WaveSystem_old.h"

#include "GameStates/NZP_GameState.h"

// Sets default values
ANZP_WaveSystem::ANZP_WaveSystem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANZP_WaveSystem::BeginPlay()
{
	Super::BeginPlay();

	if (const ANZP_GameState* GameState = GetWorld()->GetGameState<ANZP_GameState>())
	{
		WaveCount = GameState->CurrentGameModeSettings->StartingWave;
		SupportedDrops = GameState->CurrentGameModeSettings->SupportedDrops;
		bEndlessWaves = GameState->CurrentGameModeSettings->bEndlessWaves;
	}
}

// Called every frame
void ANZP_WaveSystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ANZP_WaveSystem::BeginWaveSystem()
{
	if (bEndlessWaves)
	{
		//We just run the spawning code.
	}
}

