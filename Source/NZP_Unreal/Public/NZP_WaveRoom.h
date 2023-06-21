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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly)
	FName RoomName;
};
