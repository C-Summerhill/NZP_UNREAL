// Fill out your copyright notice in the Description page of Project Settings.


#include "NZP_DropsCore.h"

#include "Components/AudioComponent.h"

// Sets default values
ANZP_DropsCore::ANZP_DropsCore()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

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
	
	DropStartingCountDownTimer = 30.f;
	
}

// Called when the game starts or when spawned
void ANZP_DropsCore::BeginPlay()
{
	Super::BeginPlay();
	
}

void ANZP_DropsCore::DropBeginOverlapTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bBFromSweep, const FHitResult& SweepResult)
{
	
}

// Called every frame
void ANZP_DropsCore::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

