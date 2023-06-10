// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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

	float DropStartingCountDownTimer;
	
	
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UFUNCTION()
	void DropBeginOverlapTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bBFromSweep,
	                                    const FHitResult& SweepResult);
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

