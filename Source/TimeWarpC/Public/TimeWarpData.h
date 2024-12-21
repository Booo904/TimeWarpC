
#pragma once

#include "CoreMinimal.h"
#include "TimeWarpData.generated.h"

USTRUCT(BlueprintType)
struct FTimeSnap
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Time)
	FTransform SnapTransform;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Time)
	FVector SnapLinearVelocity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Time)
	FVector SnapAngularVelocity;
};