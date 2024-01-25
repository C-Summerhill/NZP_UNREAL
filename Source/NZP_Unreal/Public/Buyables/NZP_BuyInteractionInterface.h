// Connor Summerhill 2023

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "NZP_BuyInteractionInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UNZP_BuyInteractionInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class NZP_UNREAL_API INZP_BuyInteractionInterface
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent)
	bool IsBuyable();

	UFUNCTION()
	virtual bool IsBuyable_Pure() = 0;

	UFUNCTION(BlueprintNativeEvent)
	FString ReturnInformation();

	UFUNCTION()
	virtual FString ReturnInformation_Pure() = 0;
};
