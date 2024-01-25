// Connor Summerhill 2023

#pragma once

#include "CoreMinimal.h"
#include "Gamestates/NZP_GameState.h"
#include "GameFramework/Actor.h"
#include "NZP_WaveSystem_old.generated.h"

UCLASS()
class NZP_UNREAL_API ANZP_WaveSystem : public AActor
{
	GENERATED_BODY()
	friend ANZP_GameState;
public:	
	// Sets default values for this actor's properties
	ANZP_WaveSystem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void BeginWaveSystem();

public:
	UPROPERTY(EditAnywhere)
	bool bShouldStartFromBeginPlay = true;
	
	UPROPERTY(EditAnywhere)
	int64 WaveCount;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ANZP_DropsCore> SupportedDrops;

	UPROPERTY(EditAnywhere)
	bool bEndlessWaves;


};
