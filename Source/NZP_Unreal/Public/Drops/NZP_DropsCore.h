//Connor Summerhill 2023

#pragma once

#include "CoreMinimal.h"
#include "Character/NZP_PlayerCharacter.h"
#include "Components/SpotLightComponent.h"
#include "GameFramework/Actor.h"
#include "Sound/SoundCue.h"
#include "NZP_DropsCore.generated.h"

UCLASS()
class NZP_UNREAL_API ANZP_DropsCore : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ANZP_DropsCore();

	ANZP_DropsCore(const FObjectInitializer& ObjectInitializer, bool bNewDoesDegrade,
	               float NewDropStartingCountDownTimer, float NewDropStartingFastFlashTimer
	               , float NewDropStartingFasterFlashTimer, float NewDropFastFlashingSpeed,
	               float NewDropFasterFlashingSpeed);

	UFUNCTION()
	void InitializeDefaults();

	FTimerHandle DropRemainingTimer;
	FTimerHandle DropRemainingTimerFastFlashing;
	FTimerHandle DropRemainingTimerFasterFlashing;
	FTimerHandle DropTimerFlashingTimer;

#pragma region DROPVISUALS

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* DropStaticMesh;

	UPROPERTY(EditDefaultsOnly)
	USoundCue* AudioCue;

	UPROPERTY(EditDefaultsOnly)
	UAudioComponent* AudioPlayer;

	UPROPERTY(EditDefaultsOnly)
	UPointLightComponent* DropLight;

#pragma endregion

protected:
	UPROPERTY(EditDefaultsOnly)
	float DropStartingCountDownTimer = 30.0f;

	UPROPERTY(EditDefaultsOnly)
	float DropStartingFastFlashTimer = 10.0f;

	UPROPERTY(EditDefaultsOnly)
	float DropStartingFasterFlashTimer = 20.0f;

	UPROPERTY(EditDefaultsOnly)
	float DropFastFlashingSpeed = .25f;

	UPROPERTY(EditDefaultsOnly)
	float DropFasterFlashingSpeed = .1f;

private:
	UPROPERTY()
	bool IsVisible = true;

	UPROPERTY(EditAnywhere)
	bool bDoesDegrade = true;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void DropBeginOverlapTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	                                     UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bBFromSweep,
	                                     const FHitResult& SweepResult);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SelfDestroy();
	void FasterFlash();
	void FastFlash();
	void ToggleFlashing();

	UFUNCTION(Server, Reliable)
	virtual void PickupFunction(ANZP_PlayerCharacter* OtherActor);

private:
};
