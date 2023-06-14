// Connor Summerhill 2023


#include "NZP_BuyableCore.h"

// Sets default values
ANZP_BuyableCore::ANZP_BuyableCore()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	InteractionInformation = "Default Give information";
}

bool ANZP_BuyableCore::Buyable_Implementation()
{
	return false;
}

bool ANZP_BuyableCore::BuyablePure()
{
	return false;
}

FString ANZP_BuyableCore::GiveInformationPure()
{
	return "Default";
}

FString ANZP_BuyableCore::GiveInformation_Implementation()
{
	return "Default";
}
