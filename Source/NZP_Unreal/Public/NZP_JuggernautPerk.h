// Connor Summerhill 2023

#pragma once

#include "CoreMinimal.h"
#include "NZP_PerkComponent.h"
#include "NZP_JuggernautPerk.generated.h"

/**
 * 
 */
UCLASS()
class NZP_UNREAL_API UNZP_JuggernautPerk : public UNZP_PerkComponent
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	virtual void DestroyComponent(bool bPromoteChildren) override;
public:
	int64 HealthIncreaseValue = 200;

	int64 OriginalHealthValue;

protected:
	const class ANZP_PlayerCharacter* PlayerCharacter;
};
