// Connor Summerhill 2023

#pragma once

#include "CoreMinimal.h"
#include "NZP_BuyInteractionInterface.h"
#include "GameFramework/Actor.h"
#include "NZP_BuyableCore.generated.h"

UCLASS()
class NZP_UNREAL_API ANZP_BuyableCore : public AActor, public INZP_BuyInteractionInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANZP_BuyableCore();

	//Interface INZP_BuyInteractionInterface
	virtual bool IsBuyable_Implementation() override;
	virtual bool IsBuyable_Pure() override; //C++ only

	FString ReturnInformation_Pure() override;
	virtual FString ReturnInformation_Implementation() override;
	//Interface - End INZP_BuyInteractionInterface
	
public:
	//Cost of Buyable
	UPROPERTY(EditDefaultsOnly)
	int64 Cost;

	//Information we want to return to the user once they are within interaction range.
	UPROPERTY(EditDefaultsOnly)
	FString BuyableInformationToReturn;
};