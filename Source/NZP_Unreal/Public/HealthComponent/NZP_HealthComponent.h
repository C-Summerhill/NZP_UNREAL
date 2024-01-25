//Connor Summerhill 2023

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "NZP_HealthComponent.generated.h"

UENUM()
enum ELocationHit
{
	Head UMETA(DisplayName="Headshot"),
	UpperBody UMETA(DisplayName="UpperBody"),
	LowerBody UMETA(DisplayName="LowerBody"),
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class NZP_UNREAL_API UNZP_HealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UNZP_HealthComponent();

	UNZP_HealthComponent(const FObjectInitializer& ObjectInitializer, int64 NewMaxHealth,
	                     FGameplayTagContainer NewDamageResistances, FGameplayTagContainer NewDamageImmunities
	                     , FGameplayTagContainer NewDamageWeakness);

	void StartRenegration();
	void StartRenegration(float InRate, float InitialDelay);

	// Called every frame
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	UFUNCTION(BlueprintCallable, Server, Unreliable)
	void TakeDamage(int64 DamageToTake, FGameplayTag DamageType, AActor* ActorSource, ELocationHit LocationHit,
	                int64 PointForKill, int64 PointForHeadshotKill);

	UFUNCTION(BlueprintCallable, Server, Unreliable)
	void GainHealth(int64 HealthToGain/*, FGameplayTag HealingType, AActor* ActorSource*/);

	UFUNCTION(BlueprintCallable, Server, Unreliable)
	void BeginRegeneration();

	UFUNCTION()
	virtual void Death(FGameplayTag DamageType, AActor* ActorSource,
	                   ELocationHit LocationHit, int64 PointForKill, int64 PointForHeadshotKill);

	void InitializeSystem();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int64 MaxHealth;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
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

	UPROPERTY(EditDefaultsOnly, Category = "Regeneration")
	bool bCanRegeneratedHealth;

	UPROPERTY(EditDefaultsOnly, Category = "Regeneration")
	float DelayBeforeStartRegeneration = 5.f;

	UPROPERTY(EditDefaultsOnly, Category = "Regeneration")
	float RegenerationRateOfHealthGained = 10;

	UPROPERTY(EditDefaultsOnly, Category = "Regeneration")
	float DelayBetweenHealthGains = 0.1f;

	FGameplayTagContainer DamageResistances;
	FGameplayTagContainer DamageImmunities;
	FGameplayTagContainer DamageWeakness;
	FTimerHandle TriggerRegenerationOfHealth;
};
