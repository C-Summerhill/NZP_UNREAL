//Connor Summerhill 2023

#include "HealthComponent/NZP_HealthComponent.h"

#include "AI/NZP_ZombieCharacter.h"
#include "Character/NZP_PlayerCharacter.h"
#include "Character/NZP_PlayerState.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UNZP_HealthComponent::UNZP_HealthComponent()
{
	InitializeSystem();
}

UNZP_HealthComponent::UNZP_HealthComponent(const FObjectInitializer& ObjectInitializer, int64 NewMaxHealth,
	FGameplayTagContainer NewDamageResistances, FGameplayTagContainer NewDamageImmunities
	, FGameplayTagContainer NewDamageWeakness)
{
	MaxHealth = NewMaxHealth;
	DamageResistances = NewDamageResistances;
	DamageImmunities = NewDamageImmunities;
	DamageWeakness = NewDamageWeakness;

	InitializeSystem();
}

void UNZP_HealthComponent::TakeDamage_Implementation(int64 DamageToTake, FGameplayTag DamageType, AActor* ActorSource,
	ELocationHit LocationHit,int64 PointForKill, int64 PointForHeadshotKill)
{
	if (DamageImmunities.HasTagExact(DamageType))
	{
		return;
	}
	
	int64 DamageToTakeModified = DamageToTake;
	
	if (DamageResistances.HasTagExact(DamageType))
	{
		DamageToTakeModified *= DamageResistanceModifier;
	}

	if (DamageWeakness.HasTagExact(DamageType))
	{
		DamageToTakeModified *= DamageWeaknessModifier;
	}

	switch (LocationHit)
	{
	case ELocationHit::Head:
		DamageToTakeModified *= HeadShotDamageModifier;
		break;
	case ELocationHit::UpperBody:
		DamageToTakeModified *= UpperBodyDamageModifier;
		break;
	case ELocationHit::LowerBody:
		DamageToTakeModified *= LowerBodyDamageModifer;
		break;
	default:
		break;
	}
	
	CurrentHealth -= DamageToTakeModified;
	if (CurrentHealth <= MinimumHealth)
	{
		Death(DamageType, ActorSource, LocationHit, PointForKill, PointForHeadshotKill);
	}
}

void UNZP_HealthComponent::Death(FGameplayTag DamageType, AActor* ActorSource,
	ELocationHit LocationHit,int64 PointForKill, int64 PointForHeadshotKill)
{
	
}

void UNZP_HealthComponent::InitializeSystem()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentHealth = MaxHealth;
}

// Called when the game starts
void UNZP_HealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
/*
void UNZP_HealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
*/
