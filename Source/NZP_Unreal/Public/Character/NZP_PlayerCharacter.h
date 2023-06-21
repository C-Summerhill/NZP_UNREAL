//Connor Summerhill 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "InputActionValue.h"
#include "HealthComponent/NZP_PlayerHealthComponent.h"

#include "NZP_PlayerCharacter.generated.h"

class UInputAction;
class UInputMappingContext;

UCLASS()
class NZP_UNREAL_API ANZP_PlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	//VARIABLES

	//Sets default values for this character's properties
	ANZP_PlayerCharacter();

	UPROPERTY(EditDefaultsOnly, Category = Mesh)
	USkeletalMeshComponent* ThirdPersonMesh;

	UPROPERTY(EditDefaultsOnly, Category = Mesh)
	class UCameraComponent* CameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controls")
	bool IsCrouching = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Point Systems")
	int64 PointsToDrop = 250;

	UPROPERTY(EditAnywhere, Category = "Point Systems")
	TSubclassOf<class ANZP_Drops_ZombiePoints> Anzp_Drops_ZombiePointsReference;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UNZP_PlayerHealthComponent* PlayerHealthComponent;

	//Interaction with the world
	UPROPERTY(BlueprintReadWrite)
	FString CurrentObjectInRange = "";

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

	UPROPERTY(EditDefaultsOnly)
	float TraceDistance = 500;

#pragma endregion

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Controller")
	class ANZP_PlayerController* PlayerController;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Player State")
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

	UFUNCTION(BlueprintGetter)
	UNZP_PlayerHealthComponent* GetHealthComponent() const;

protected:
	void ScanForIntractable();

	//Inputs
	void Movement(const FInputActionValue& Value);
	void LookingAround(const FInputActionValue& Value);
	void Firing(const FInputActionValue& Value);
	void Crouching(const FInputActionValue& Value);
	void DropPointsFunction(const FInputActionValue& Value);
	void Interaction(const FInputActionValue& Value);

	virtual void PawnClientRestart() override;
};
