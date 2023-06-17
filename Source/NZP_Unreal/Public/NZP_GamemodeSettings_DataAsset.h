// Connor Summerhill 2023

#pragma once

#include "CoreMinimal.h"
#include "NZP_DataAsset.h"
#include "Drops/NZP_DropsCore.h"
#include "NZP_GamemodeSettings_DataAsset.generated.h"

/**
 * 
 */
UCLASS()
class NZP_UNREAL_API UNZP_GamemodeSettings_DataAsset : public UNZP_DataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName GameModeName = "Classic";

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName GameModeDescription = "Classic zombie horde mode, get ready for a challenge";

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int64 StartingPoints = 500;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int StartingWave = 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ToolTip = "Inital only, if this changes during your map, trigger it manually"))
	bool bEndlessWaves = false;
	
	//UPROPERTY(EditAnywhere, BlueprintReadOnly)
	//GUNCLASS* StartingWeapon = Pistol;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bShouldPowerBeEnabled = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bShouldDoorsBeOpened = false;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	bool bShouldPlayersBeAbleToDropPoints = true;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(ToolTip="If disabled, box, wall weapons and pack-a-punch are disable regardless of other settings"))
	bool bShouldMagicExist = true;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bShouldMagicBoxExist = true;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bShouldWallWeaponsExist = true;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bShouldPackAPunchExist = true;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bSharedBank = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ToolTip = "Not for combat, triggers a winable condition for a single player or team"))
	bool bIsPvp = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ToolTip = "Leave at -1 for there to be no team limit"))
	int TeamSizes = -1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ToolTip = "Added for those who like pain"))
	float CostMultiplier = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float PointsMultiplier = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float ZombieCountMultiplier = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float DropSpawnChance = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly,meta = (ToolTip = "Add drops the GAMEMODE should support, not the map. map drops are in map details and the two are defined"))
	TSubclassOf<ANZP_DropsCore> SupportedDrops;
};