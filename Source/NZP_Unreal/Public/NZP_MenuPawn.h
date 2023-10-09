// Connor Summerhill 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NZP_MenuPawn.generated.h"

UCLASS()
class NZP_UNREAL_API ANZP_MenuPawn : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ANZP_MenuPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
