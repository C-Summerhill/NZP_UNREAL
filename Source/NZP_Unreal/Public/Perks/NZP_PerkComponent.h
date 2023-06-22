// Connor Summerhill 2023

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NZP_PerkComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NZP_UNREAL_API UNZP_PerkComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UNZP_PerkComponent();

	UPROPERTY(EditDefaultsOnly)
	UTexture2D* PerkIcon;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
