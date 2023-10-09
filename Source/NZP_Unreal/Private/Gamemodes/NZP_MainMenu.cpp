// Connor Summerhill 2023


#include "Gamemodes/NZP_MainMenu.h"

#include "NZP_GameState.h"
#include "NZP_MenuPawn.h"
#include "Character/NZP_PlayerController.h"
#include "Character/NZP_PlayerState.h"

ANZP_MainMenu::ANZP_MainMenu()
{
	DefaultPawnClass = ANZP_MenuPawn::StaticClass();
    PlayerControllerClass = ANZP_PlayerController::StaticClass();
    PlayerStateClass = ANZP_PlayerState::StaticClass();
    GameStateClass = ANZP_GameState::StaticClass();
    /*TODO: Add Main Menu Hud*/
}
