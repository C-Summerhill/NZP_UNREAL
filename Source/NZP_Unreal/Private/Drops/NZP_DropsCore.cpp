// Fill out your copyright notice in the Description page of Project Settings.


#include "Drops/NZP_DropsCore.h"

#include "Components/AudioComponent.h"

// Sets default values
ANZP_DropsCore::ANZP_DropsCore()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	InitializeDefaults();
}

ANZP_DropsCore::ANZP_DropsCore(const FObjectInitializer& ObjectInitializer, bool bNewDoesDegrade = true, float NewDropStartingCountDownTimer = 30.0f,
	float NewDropStartingFastFlashTimer = 20.f, float NewDropStartingFasterFlashTimer = 10.f, float NewDropFastFlashingSpeed = .5f,
	float NewDropFasterFlashingSpeed = .1f)
{
	
	PrimaryActorTick.bCanEverTick = false;

	bDoesDegrade = bNewDoesDegrade;
	DropStartingCountDownTimer = NewDropStartingCountDownTimer;
	DropStartingFastFlashTimer = NewDropStartingFastFlashTimer;
	DropStartingFasterFlashTimer = NewDropStartingFasterFlashTimer;
	DropFastFlashingSpeed = NewDropFastFlashingSpeed;
	DropFasterFlashingSpeed = NewDropFasterFlashingSpeed;
	
	InitializeDefaults();
}

// Called when the game starts or when spawned
void ANZP_DropsCore::BeginPlay()
{
	Super::BeginPlay();

	if (bDoesDegrade)
	{
		GetWorldTimerManager().SetTimer(DropRemainingTimerFastFlashing, this, &ANZP_DropsCore::FastFlash,DropStartingFastFlashTimer,false);

		GetWorldTimerManager().SetTimer(DropRemainingTimerFasterFlashing, this, &ANZP_DropsCore::FasterFlash,DropStartingFasterFlashTimer, false);
		
		GetWorldTimerManager().SetTimer(DropRemainingTimer, this, &ANZP_DropsCore::SelfDestroy, DropStartingCountDownTimer, false);
	}
}

void ANZP_DropsCore::DropBeginOverlapTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bBFromSweep, const FHitResult& SweepResult)
{
	if (ANZP_PlayerCharacter* PlayerCharacter = Cast<ANZP_PlayerCharacter>(OtherActor))
	{
		PickupFunction(PlayerCharacter);
	}
}

// Called every frame
void ANZP_DropsCore::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANZP_DropsCore::SelfDestroy()
{
	Destroy();
}

void ANZP_DropsCore::ToggleFlashing()
{
	DropStaticMesh->SetVisibility(!IsVisible);
	IsVisible = !IsVisible;
}

void ANZP_DropsCore::PickupFunction_Implementation(ANZP_PlayerCharacter* OtherActor)
{
	Destroy();
}

void ANZP_DropsCore::FastFlash()
{
	if(GetWorldTimerManager().TimerExists(DropTimerFlashingTimer))
	{
		GetWorldTimerManager().ClearTimer(DropTimerFlashingTimer);
	}
	GetWorldTimerManager().SetTimer(DropTimerFlashingTimer, this, &ANZP_DropsCore::ToggleFlashing,DropFastFlashingSpeed, true);
}

void ANZP_DropsCore::FasterFlash()
{
	if(GetWorldTimerManager().TimerExists(DropTimerFlashingTimer))
	{
		GetWorldTimerManager().ClearTimer(DropTimerFlashingTimer);
	}
	GetWorldTimerManager().SetTimer(DropTimerFlashingTimer, this, &ANZP_DropsCore::ToggleFlashing,DropFasterFlashingSpeed, true);
}

void ANZP_DropsCore::InitializeDefaults()
{
	DropStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Drop Mesh"));
	DropStaticMesh->SetCollisionProfileName(TEXT("OverlapOnlyPawn"));
	DropStaticMesh->OnComponentBeginOverlap.AddDynamic(this, &ANZP_DropsCore::DropBeginOverlapTrigger);
	DropStaticMesh->SetupAttachment(GetRootComponent());

	if (AudioCue)
	{
		AudioCue->VirtualizationMode = EVirtualizationMode::PlayWhenSilent;
	}

	AudioPlayer = CreateDefaultSubobject<UAudioComponent>(TEXT("Sound Cue"));
	AudioPlayer->bAutoActivate = true;
	AudioPlayer->SetSound(AudioCue);
	AudioPlayer->SetupAttachment(DropStaticMesh);

	DropLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("Drop Light"));
	DropLight->SetupAttachment(DropStaticMesh);
}