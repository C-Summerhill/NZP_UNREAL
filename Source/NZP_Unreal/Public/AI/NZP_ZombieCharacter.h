//Connor Summerhill 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NZP_ZombieCharacter.generated.h"

UCLASS()
class NZP_UNREAL_API ANZP_ZombieCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANZP_ZombieCharacter();

	//ANZP_ZombieCharacter(const FObjectInitializer& ObjectInitializer);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
