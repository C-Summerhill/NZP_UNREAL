// Connor Summerhill 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Core_Weapon.generated.h"

UCLASS()
class NZP_UNREAL_API ACore_Weapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACore_Weapon();

	virtual void Tick(float DeltaTime) override;

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


};
