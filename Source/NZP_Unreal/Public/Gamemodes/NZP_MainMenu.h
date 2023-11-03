// Connor Summerhill 2023

#pragma once

#include "CoreMinimal.h"
#include "NZP_UnrealGameModeBase.h"
#include "GameFramework/GameMode.h"
#include "NZP_MainMenu.generated.h"

UENUM()
enum WaveStage
{
	Waiting		UMETA(DisplayName = "Waiting"),
	Starting	UMETA(DisplayName = "Starting"),
	Live		UMETA(DisplayName = "Live"),
	End			UMETA(DisplayName = "End")
};
/**
 * 
 */
UCLASS()
class NZP_UNREAL_API ANZP_MainMenu : public ANZP_UnrealGameModeBase
{
	GENERATED_BODY()

	ANZP_MainMenu();
};
