// Connor Summerhill 2023


#include "Perks/NZP_JuggernautPerk.h"

#include "Character/NZP_PlayerCharacter.h"

void UNZP_JuggernautPerk::BeginPlay()
{
	Super::BeginPlay();

	PlayerCharacter = Cast<ANZP_PlayerCharacter>(GetOwner());
	
	if(PlayerCharacter)
	{
		OriginalHealthValue = PlayerCharacter->PlayerHealthComponent->MaxHealth;
		PlayerCharacter->PlayerHealthComponent->MaxHealth = HealthIncreaseValue;
		PlayerCharacter->PlayerHealthComponent->StartRenegration(0.1f, 0.1f);
	}
}

void UNZP_JuggernautPerk::DestroyComponent(bool bPromoteChildren)
{
	Super::DestroyComponent(bPromoteChildren);

	if(PlayerCharacter)
	{
		PlayerCharacter->PlayerHealthComponent->MaxHealth = OriginalHealthValue;
	}
}
