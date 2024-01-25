// Connor Summerhill 2023


#include "Gamemodes/NZP_MainMenu.h"

#include "GameStates/NZP_GameState.h"
#include "HUD/NZP_Hud_Class.h"
#include "Pawn/NZP_MenuPawn.h"
#include "Character/NZP_PlayerController.h"
#include "Character/NZP_PlayerState.h"

ANZP_MainMenu::ANZP_MainMenu():ANZP_UnrealGameModeBase()
{
	DefaultPawnClass = ANZP_MenuPawn::StaticClass();
	PlayerControllerClass = ANZP_PlayerController::StaticClass();
	PlayerStateClass = ANZP_PlayerState::StaticClass();
	GameStateClass = ANZP_GameState::StaticClass();
	HUDClass = ANZP_Hud_Class::StaticClass();
}
