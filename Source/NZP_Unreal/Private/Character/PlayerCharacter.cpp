// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PlayerCharacter.h"

#include "AITypes.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInput/Public/EnhancedInputComponent.h"

#include "Camera/CameraComponent.h"
#include "Character/NZP_PlayerController.h"
#include "Character/NZP_PlayerState.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//Get Correct Player Controller
	//PlayerController = Cast<ANZP_PlayerController>(GetController());

	//Get Correct Player State
	LocalPlayerState = Cast<ANZP_PlayerState>(GetPlayerState());

	//First Person Mesh Setup
	GetMesh()->CastShadow = false;
	GetMesh()->SetOnlyOwnerSee(true);
	GetMesh()->bCastDynamicShadow = false;
	GetMesh()->CastShadow = false;

	//Third Person Mesh Setup
	ThirdPersonMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Third Person Mesh"));
	ThirdPersonMesh->SetupAttachment(GetRootComponent());
	ThirdPersonMesh->SetOwnerNoSee(true);
	ThirdPersonMesh->bCastDynamicShadow = true;
	ThirdPersonMesh->CastShadow = true;
	ThirdPersonMesh->bCastHiddenShadow = true;

	//Camera Setup
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	CameraComponent->SetupAttachment(GetMesh());
	CameraComponent->SetRelativeLocation(FVector(0,0,50));
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input

void APlayerCharacter::Movement(const FInputActionValue& Value)
{
	if (Value.GetMagnitude() != 0.0f)
	{
		AddMovementInput(GetActorForwardVector(), Value[1]);
		AddMovementInput(GetActorRightVector(), Value[0]);
	}
}

void APlayerCharacter::LookingAround(const FInputActionValue& Value)
{
	if (Value.GetMagnitude() != 0.0f)
	{
		AddControllerPitchInput(Value[1] * -1);
		AddControllerYawInput(Value[0]);
	}
}

void APlayerCharacter::Firing(const FInputActionValue& Value)
{
	if (Value[0] != 0.0f)
	{
		//TODO: Firing Code.
	}
}

void APlayerCharacter::Crouching(const FInputActionValue& Value)
{
	if (PlayerController->GetCrouchToggle())
	{
		if (IsCrouching)
		{
			UnCrouch();
		}
		else
		{
			Crouch();
		}
	}
	else
	{
		if (Value[0])
		{
			Crouch();
		}
		else
		{
			UnCrouch();
		}
	}
}

void APlayerCharacter::DropPointsFunction(const FInputActionValue& Value)
{
	if (LocalPlayerState->GetCurrentPoints() >= PointsToDrop)
	{
		//TODO: Drop points.
		//TODO: Take Points from Current Player State.
	}
}

void APlayerCharacter::PawnClientRestart()
{
	Super::PawnClientRestart();

	PlayerController = Cast<ANZP_PlayerController>(GetController());
	LocalPlayerState = Cast<ANZP_PlayerState>(GetPlayerState());

	if (PlayerController)
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->ClearAllMappings();

			Subsystem->AddMappingContext(FPSMappingContext, FPSMappingContextPriority);
		}
	}
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* PlayerEnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (JumpAction)
		{
			PlayerEnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered,this, &ACharacter::Jump);
			PlayerEnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed,this, &ACharacter::StopJumping);
		}
		if (Fire)
		{
			PlayerEnhancedInputComponent->BindAction(Fire, ETriggerEvent::Triggered,this, &APlayerCharacter::Firing);
		}
		if (Looking)
		{
			PlayerEnhancedInputComponent->BindAction(Looking, ETriggerEvent::Triggered,this, &APlayerCharacter::LookingAround);
		}
		if (MovementAction)
		{
			PlayerEnhancedInputComponent->BindAction(MovementAction, ETriggerEvent::Triggered,this, &APlayerCharacter::Movement);
		}

		if (CrouchAction)
		{
			PlayerEnhancedInputComponent->BindAction(CrouchAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Crouching);
		}
		
		if (DropPoints)
		{
			PlayerEnhancedInputComponent->BindAction(DropPoints, ETriggerEvent::Triggered, this, &APlayerCharacter::DropPointsFunction);
		}
	}
}
