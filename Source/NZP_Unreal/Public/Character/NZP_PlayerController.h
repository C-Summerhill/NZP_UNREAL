//Connor Summerhill 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "NZP_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class NZP_UNREAL_API ANZP_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controls|Settings")
	bool bToggleCrouched = false;

public:

	UFUNCTION()
	bool GetCrouchToggle() const;

	UFUNCTION()
	void SetCrouchToggle(bool bNewCrouchState);
};
