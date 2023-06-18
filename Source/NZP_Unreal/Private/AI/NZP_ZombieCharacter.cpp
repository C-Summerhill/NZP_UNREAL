//Connor Summerhill 2023


#include "AI/NZP_ZombieCharacter.h"

// Sets default values
ANZP_ZombieCharacter::ANZP_ZombieCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ZombieHealthComponent = CreateDefaultSubobject<UNZP_ZombieHealthComponent>(TEXT("Heath Component"));
	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Zombie Mesh"));
	SkeletalMeshComponent->SetupAttachment(GetRootComponent());
}

UNZP_ZombieHealthComponent* ANZP_ZombieCharacter::GetZombieHealthComponent()
{
	return ZombieHealthComponent;
}

// Called when the game starts or when spawned
void ANZP_ZombieCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}