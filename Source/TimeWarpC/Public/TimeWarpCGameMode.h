// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TimeWarpCGameMode.generated.h"

UCLASS(minimalapi)
class ATimeWarpCGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATimeWarpCGameMode();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Time)
	float MaxTimeTracked = 120.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Time)
	float TrackFrequency = 0.03f;
};



