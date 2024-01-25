// Connor Summerhill 2023


#include "HUD/NZP_Hud_Class.h"

#include "Widgets/MainMenu_Widget.h"
#include "Blueprint/UserWidget.h"

ANZP_Hud_Class::ANZP_Hud_Class()
{
	
}

void ANZP_Hud_Class::BeginPlay()
{
	if (IsValid(WidgetClass))
	{
		MainMenu = Cast<UMainMenu_Widget>(CreateWidget(GetOwningPlayerController(), WidgetClass));

		if(MainMenu)
		{
			MainMenu->AddToViewport();
		}
		
		FInputModeGameAndUI Mode;
		Mode.SetLockMouseToViewportBehavior(EMouseLockMode::LockOnCapture);
		Mode.SetHideCursorDuringCapture(false);
		GetOwningPlayerController()->SetInputMode(Mode);
	}
	
	Super::BeginPlay();
}
