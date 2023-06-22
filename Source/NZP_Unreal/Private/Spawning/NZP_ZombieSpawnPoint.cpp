// Connor Summerhill 2023


#include "Spawning/NZP_ZombieSpawnPoint.h"

// Sets default values
ANZP_ZombieSpawnPoint::ANZP_ZombieSpawnPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANZP_ZombieSpawnPoint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANZP_ZombieSpawnPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

