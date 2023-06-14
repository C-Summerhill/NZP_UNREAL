// Connor Summerhill 2023

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "BuyInteractionInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UBuyInteractionInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class NZP_UNREAL_API IBuyInteractionInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintNativeEvent)
	bool Buyable();

	UFUNCTION()
	virtual bool BuyablePure() = 0;

	UFUNCTION(BlueprintNativeEvent)
	FString GiveInformation();

	UFUNCTION()
	virtual FString GiveInformationPure() = 0;
};
