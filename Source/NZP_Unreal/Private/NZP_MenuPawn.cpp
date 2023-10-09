// Connor Summerhill 2023


#include "NZP_MenuPawn.h"

// Sets default values
ANZP_MenuPawn::ANZP_MenuPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANZP_MenuPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANZP_MenuPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANZP_MenuPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

