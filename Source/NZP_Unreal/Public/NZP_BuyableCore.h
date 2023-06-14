// Connor Summerhill 2023

#pragma once

#include "CoreMinimal.h"
#include "BuyInteractionInterface.h"
#include "GameFramework/Actor.h"
#include "NZP_BuyableCore.generated.h"

UCLASS()
class NZP_UNREAL_API ANZP_BuyableCore : public AActor, public IBuyInteractionInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANZP_BuyableCore();

	bool Buyable_Implementation() override;
	virtual bool BuyablePure() override; //C++ only

	FString GiveInformationPure() override;
	virtual FString GiveInformation_Implementation() override;
	
public:

	UPROPERTY(EditDefaultsOnly)
	int64 Cost;

	UPROPERTY(EditDefaultsOnly)
	FString InteractionInformation;
};