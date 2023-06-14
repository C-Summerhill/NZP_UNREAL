//Connor Summerhill 2023


#include "Character/NZP_PlayerCharacter.h"

#include "AITypes.h"
#include "BuyInteractionInterface.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInput/Public/EnhancedInputComponent.h"

#include "Camera/CameraComponent.h"
#include "Character/NZP_PlayerController.h"
#include "Character/NZP_PlayerState.h"
#include "Drops/NZP_Drops_ZombiePoints.h"

// Sets default values
ANZP_PlayerCharacter::ANZP_PlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Get Correct Player Controller /* here in case I need it */
	//PlayerController = Cast<ANZP_PlayerController>(GetController());

	//Get Correct Player State
	LocalPlayerState = Cast<ANZP_PlayerState>(GetPlayerState());

	//First Person Mesh Setup
	GetMesh()->CastShadow = false;
	GetMesh()->SetOnlyOwnerSee(true);
	GetMesh()->bCastDynamicShadow = false;
	GetMesh()->CastShadow = false;
	GetMesh()->SetRelativeLocation(FVector(-20,0,-90));

	//Third Person Mesh Setup
	ThirdPersonMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Third Person Mesh"));
	ThirdPersonMesh->SetupAttachment(GetRootComponent());
	ThirdPersonMesh->SetOwnerNoSee(true);
	ThirdPersonMesh->bCastDynamicShadow = true;
	ThirdPersonMesh->CastShadow = true;
	ThirdPersonMesh->bCastHiddenShadow = true;

	//Third Person Adjustments
	ThirdPersonMesh->SetRelativeLocation(FVector(0,0,-90));
	ThirdPersonMesh->SetRelativeRotation(FRotator(0,-90,0));

	//Camera Setup
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	CameraComponent->SetupAttachment(GetMesh());
	CameraComponent->SetRelativeLocation(FVector(20,0,150));
	CameraComponent->bUsePawnControlRotation = true;

	PlayerHealthComponent = CreateDefaultSubobject<UPlayerHealthComponent>(TEXT("Health System"));
}

// Called when the game starts or when spawned
void ANZP_PlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ANZP_PlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

// Called to bind functionality to input

void ANZP_PlayerCharacter::Movement(const FInputActionValue& Value)
{
	if (Value.GetMagnitude() != 0.0f)
	{
		AddMovementInput(GetActorForwardVector(), Value[1]);
		AddMovementInput(GetActorRightVector(), Value[0]);
	}
}

void ANZP_PlayerCharacter::LookingAround(const FInputActionValue& Value)
{
	if (Value.GetMagnitude() != 0.0f)
	{
		AddControllerPitchInput(Value[1] * -1);
		AddControllerYawInput(Value[0]);
	}
}

void ANZP_PlayerCharacter::Firing(const FInputActionValue& Value)
{
	if (Value[0] != 0.0f)
	{
		//TODO: Firing Code.
	}
}

void ANZP_PlayerCharacter::Crouching(const FInputActionValue& Value)
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

void ANZP_PlayerCharacter::DropPointsFunction(const FInputActionValue& Value)
{
	if (LocalPlayerState->GetCurrentPoints() >= PointsToDrop && Anzp_Drops_ZombiePointsReference)
	{
		//TODO: Drop points.
		GetWorld()->SpawnActor<ANZP_Drops_ZombiePoints>(Anzp_Drops_ZombiePointsReference,GetActorLocation() + (GetActorForwardVector() * 100)
			,FRotator(0,0,0));

		//TODO: Take Points from Current Player State.
		LocalPlayerState->SpendPoints(PointsToDrop);
	}
}

void ANZP_PlayerCharacter::Interaction(const FInputActionValue& Value)
{
	
}

void ANZP_PlayerCharacter::PawnClientRestart()
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

void ANZP_PlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
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
			PlayerEnhancedInputComponent->BindAction(Fire, ETriggerEvent::Triggered,this, &ANZP_PlayerCharacter::Firing);
		}
		if (Looking)
		{
			PlayerEnhancedInputComponent->BindAction(Looking, ETriggerEvent::Triggered,this, &ANZP_PlayerCharacter::LookingAround);
		}
		if (MovementAction)
		{
			PlayerEnhancedInputComponent->BindAction(MovementAction, ETriggerEvent::Triggered,this, &ANZP_PlayerCharacter::Movement);
		}

		if (CrouchAction)
		{
			PlayerEnhancedInputComponent->BindAction(CrouchAction, ETriggerEvent::Triggered, this, &ANZP_PlayerCharacter::Crouching);
		}
		
		if (DropPoints)
		{
			PlayerEnhancedInputComponent->BindAction(DropPoints, ETriggerEvent::Completed, this, &ANZP_PlayerCharacter::DropPointsFunction);
		}
		if (InteractionAction)
		{
			PlayerEnhancedInputComponent->BindAction(InteractionAction, ETriggerEvent::Triggered, this, &ANZP_PlayerCharacter::Interaction);
		}
	}
}

void ANZP_PlayerCharacter::ScanForIntractable()
{
	FVector Start = GetOwner()->GetActorLocation();
	FVector End = ((GetActorForwardVector()*TraceDistance) + Start);

	FHitResult Hit;
	FCollisionQueryParams TraceParams;

	bool bHit = GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, TraceParams);
	DrawDebugLine(GetWorld(), Start, End, FColor::Orange, false, 0.1f);

	if (bHit)
	{
		if (Hit.GetActor()->GetClass()->ImplementsInterface(UBuyInteractionInterface::StaticClass()))
		{
			CurrentObjectInRange = Cast<IBuyInteractionInterface>(Hit.GetActor())->GiveInformation();
			CurrentObjectInRange = IBuyInteractionInterface::Execute_GiveInformation(Hit.GetActor());
		}
	}
	else
	{
		CurrentObjectInRange = "";
	}
}