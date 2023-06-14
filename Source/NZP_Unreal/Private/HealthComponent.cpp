//Connor Summerhill 2023

#include "HealthComponent.h"

#include "AI/NZP_ZombieCharacter.h"
#include "Character/NZP_PlayerCharacter.h"
#include "Character/NZP_PlayerState.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	InitializeSystem();
}

UHealthComponent::UHealthComponent(const FObjectInitializer& ObjectInitializer, int64 NewMaxHealth,
	FGameplayTagContainer NewDamageResistances, FGameplayTagContainer NewDamageImmunities
	, FGameplayTagContainer NewDamageWeakness)
{
	MaxHealth = NewMaxHealth;
	DamageResistances = NewDamageResistances;
	DamageImmunities = NewDamageImmunities;
	DamageWeakness = NewDamageWeakness;

	InitializeSystem();
}

void UHealthComponent::TakeDamage_Implementation(int64 DamageToTake, FGameplayTag DamageType, AActor* ActorSource,
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

void UHealthComponent::Death(FGameplayTag DamageType, AActor* ActorSource,
	ELocationHit LocationHit,int64 PointForKill, int64 PointForHeadshotKill)
{

}

void UHealthComponent::InitializeSystem()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentHealth = MaxHealth;
}

// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
/*
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
*/
