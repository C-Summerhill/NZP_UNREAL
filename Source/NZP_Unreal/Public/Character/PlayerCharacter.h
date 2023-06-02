// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "InputActionValue.h"

#include "PlayerCharacter.generated.h"

class UInputAction;
class UInputMappingContext;

UCLASS()
class NZP_UNREAL_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	//VARIABLES
	
	//Sets default values for this character's properties
	APlayerCharacter();

	UPROPERTY(EditDefaultsOnly, Category = Mesh)
	USkeletalMeshComponent* ThirdPersonMesh;

	UPROPERTY(EditDefaultsOnly, Category = Mesh)
	class UCameraComponent* CameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controls")
	bool IsCrouching = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Point Systems")
	int64 PointsToDrop;

protected:

#pragma region INPUT

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Controls|Input Actions")
	UInputAction* MovementAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Controls|Input Actions")
	UInputAction* Fire;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Controls|Input Actions")
	UInputAction* Looking;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Controls|Input Actions")
	UInputAction* JumpAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Controls|Input Actions")
	UInputAction* InteractionAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Controls|Input Actions")
	UInputAction* MeleeAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Controls|Input Actions")
	UInputAction* DropPoints;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Controls|Input Actions")
	UInputAction* CrouchAction;

	//Mapping Context
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Controls|Input Mappings")
	UInputMappingContext* FPSMappingContext;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Controls|Input Mappings")
	int32 FPSMappingContextPriority = 0;

#pragma endregion

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Controller")
	class ANZP_PlayerController* PlayerController;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Player State")
	class ANZP_PlayerState* LocalPlayerState;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// FUNCTIONS
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	void Movement(const FInputActionValue& Value);
	void LookingAround(const FInputActionValue& Value);
	void Firing(const FInputActionValue& Value);
	void Crouching(const FInputActionValue& Value);
	void DropPointsFunction(const FInputActionValue& Value);

	virtual void PawnClientRestart() override;

};