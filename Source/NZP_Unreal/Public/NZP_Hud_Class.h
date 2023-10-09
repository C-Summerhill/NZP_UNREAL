// Connor Summerhill 2023

#pragma once

#include "CoreMinimal.h"
#include "MainMenu_Widget.h"
#include "GameFramework/HUD.h"
#include "NZP_Hud_Class.generated.h"

/**
 * 
 */
UCLASS()
class NZP_UNREAL_API ANZP_Hud_Class : public AHUD
{
	GENERATED_BODY()

	ANZP_Hud_Class();

public:
	virtual void BeginPlay() override;

public:
	
	UUserWidget* MainMenu;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> WidgetClass;
};
