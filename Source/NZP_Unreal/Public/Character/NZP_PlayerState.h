//Connor Summerhill 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "NZP_PlayerState.generated.h"

DECLARE_DYNAMIC_DELEGATE_OneParam(FCurrentPointsUpdated, int64, NewCurrentPoints);

/**
 * 
 */
UCLASS()
class NZP_UNREAL_API ANZP_PlayerState : public APlayerState
{
	GENERATED_BODY()

	ANZP_PlayerState();

public:
	UFUNCTION(Server, Reliable)
	void SetTeamNumberOnServer(int NewTeamNumber);

	UFUNCTION(Server, Reliable)
	void SetPositionInTeam(int NewPositionNumber);

	UFUNCTION(BlueprintCallable)
	void AddPoints(int64 PointsToAdd);

	UFUNCTION(BlueprintCallable)
	bool SpendPoints(int64 PointsToTake);

	void SetCurrentPoints(int64 NewCurrentPoints);
	
protected:
	void SetTotalPoints(int64 NewCurrentPoints);

private:
	
	UFUNCTION()
	void OnRep_CurrentPoints();

	//Variables
public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	int64 GetCurrentPoints() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	int64 GetTotalPoints() const;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay|Team")
	int TeamNumber;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay|Team")
	int PositionInTeam;

protected:
	FCurrentPointsUpdated UpdateCurrentPoints;
	
private:
	UPROPERTY(ReplicatedUsing=OnRep_CurrentPoints)
	int64 CurrentPoints;

	int64 TotalPoints;
};
