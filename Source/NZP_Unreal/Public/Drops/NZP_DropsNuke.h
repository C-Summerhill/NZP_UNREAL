// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NZP_DropsCore.h"
#include "NZP_DropsNuke.generated.h"

/**
 * 
 */
UCLASS()
class NZP_UNREAL_API ANZP_DropsNuke : public ANZP_DropsCore
{
	GENERATED_BODY()

public:	
	virtual void PickupFunction(ANZP_PlayerCharacter* OtherActor) override;

public:
	UPROPERTY(EditDefaultsOnly)
	int64 BasePointsGiven = 400;
};
