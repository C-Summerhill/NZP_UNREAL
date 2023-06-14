// Connor Summerhill 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NZP_BuyableCore.generated.h"

UCLASS()
class NZP_UNREAL_API ANZP_BuyableCore : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANZP_BuyableCore();

	UFUNCTION(BlueprintCallable, Server, Reliable)
	void Buyable();

	UFUNCTION(BlueprintCallable)
	FString GiveInformation();
	
public:

	UPROPERTY(EditDefaultsOnly)
	int64 Cost;

	UPROPERTY(EditDefaultsOnly)
	FString InteractionInformation;
};