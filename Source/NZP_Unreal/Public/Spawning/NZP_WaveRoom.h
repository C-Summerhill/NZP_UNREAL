// Connor Summerhill 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NZP_WaveRoom.generated.h"

UCLASS()
class NZP_UNREAL_API ANZP_WaveRoom : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANZP_WaveRoom();

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	UPROPERTY(EditDefaultsOnly)
	FName RoomName;
	
	UPROPERTY(EditDefaultsOnly)
	TArray<class ANZP_ZombieSpawnPoint*> RelevantZombieSpawners;

	//UPROPERTY(EditDefaultsOnly)
	//TArray<class NZP_WaveRoom*>NeighbourRooms;
	
	UPROPERTY(BlueprintReadOnly)
	bool bIsActive = false;
};