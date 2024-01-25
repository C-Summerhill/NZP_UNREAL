//Connor Summerhill 2023

#pragma once

#include "CoreMinimal.h"
#include "HealthComponent/NZP_ZombieHealthComponent.h"
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

	//Returns Zombie Health Component
	UFUNCTION(BlueprintCallable)
	UNZP_ZombieHealthComponent* GetZombieHealthComponent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	UNZP_ZombieHealthComponent* ZombieHealthComponent;

	UPROPERTY(EditDefaultsOnly)
	USkeletalMeshComponent* SkeletalMeshComponent;
};
