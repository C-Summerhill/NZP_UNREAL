// Connor Summerhill 2023

#pragma once

#include "CoreMinimal.h"
#include "NZP_DataAsset.h"
#include "NZP_GamemodeSettings_DataAsset.h"
#include "NZP_Map_DataAsset.generated.h"

/**
 * 
 */
UCLASS()
class NZP_UNREAL_API UNZP_Map_DataAsset : public UNZP_DataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName MapName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText MapDetails;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture* MapThumbnail;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName Author;
};
