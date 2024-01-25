// Connor Summerhill 2023


#include "Buyables/NZP_BuyableCore.h"

// Sets default values
ANZP_BuyableCore::ANZP_BuyableCore()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	BuyableInformationToReturn = "Default Give information";
}

bool ANZP_BuyableCore::IsBuyable_Implementation()
{
	return INZP_BuyInteractionInterface::IsBuyable_Implementation();
}

bool ANZP_BuyableCore::IsBuyable_Pure()
{
	return false;
}

FString ANZP_BuyableCore::ReturnInformation_Pure()
{
	return "Default";
}

FString ANZP_BuyableCore::ReturnInformation_Implementation()
{
	return INZP_BuyInteractionInterface::ReturnInformation_Implementation();
}