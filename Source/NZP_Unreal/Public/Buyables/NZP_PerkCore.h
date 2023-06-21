// Connor Summerhill 2023

#pragma once

#include "CoreMinimal.h"
#include "Buyables/NZP_BuyableCore.h"
#include "NZP_PerkCore.generated.h"

/**
 * 
 */
UCLASS()
class NZP_UNREAL_API ANZP_PerkCore : public ANZP_BuyableCore
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly)
	class UStaticMeshComponent* StaticMeshComponent;

	//UPROPERTY(EditDefaultsOnly)
	//class
};
