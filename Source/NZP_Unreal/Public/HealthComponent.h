//Connor Summerhill 2023

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

UENUM()
enum ELocationHit
{
	Head		UMETA(DisplayName="Headshot"),
	UpperBody	UMETA(DisplayName="UpperBody"),
	LowerBody	UMETA(DisplayName="LowerBody"),
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NZP_UNREAL_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

	UHealthComponent(const FObjectInitializer& ObjectInitializer, int64 NewMaxHealth,
	FGameplayTagContainer NewDamageResistances, FGameplayTagContainer NewDamageImmunities
	, FGameplayTagContainer NewDamageWeakness);

	// Called every frame
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	
	UFUNCTION(BlueprintCallable, Server, Unreliable)
	void TakeDamage(int64 DamageToTake, FGameplayTag DamageType, AActor* ActorSource, ELocationHit LocationHit, int64 PointForKill, int64 PointForHeadshotKill);

	UFUNCTION()
	virtual void Death(FGameplayTag DamageType, AActor* ActorSource,
	                   ELocationHit LocationHit, int64 PointForKill, int64 PointForHeadshotKill);

	void InitializeSystem();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditDefaultsOnly)
	int64 MaxHealth;

	UPROPERTY(EditDefaultsOnly)
	int64 CurrentHealth;

	UPROPERTY(EditDefaultsOnly)
	float DamageResistanceModifier = .5f;

	UPROPERTY(EditDefaultsOnly)
	float DamageWeaknessModifier = 1.5f;

	int64 MinimumHealth = 0;

	UPROPERTY(EditDefaultsOnly)
	float HeadShotDamageModifier = 2.f;

	UPROPERTY(EditDefaultsOnly)
	float UpperBodyDamageModifier = 1.5f;

	UPROPERTY(EditDefaultsOnly)
	float LowerBodyDamageModifer = 1.f;

	FGameplayTagContainer DamageResistances;
	FGameplayTagContainer DamageImmunities;
	FGameplayTagContainer DamageWeakness;
};
