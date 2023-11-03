// Connor Summerhill 2023


#include "Weapons/Core_Weapon.h"

// Sets default values
ACore_Weapon::ACore_Weapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACore_Weapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACore_Weapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

