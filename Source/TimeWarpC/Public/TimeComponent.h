
#pragma once

#include "CoreMinimal.h"
#include "TimeWarpData.h"
#include "TimeComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TIMEWARPC_API UTimeComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	UTimeComponent();

	void Setup();

	void TimeProgress();

	void StartTimeTracker();

	void ReverseTime();

	void PauseTime();

	void RecordTime();

	void PausePhysics(bool ShouldPause);

	void ApplyTime(FTimeSnap TimeApplied);

	void ApplyTimeInterpolated(FTimeSnap TimeSnapBegin, FTimeSnap TimeSnapEnd);

	void StopManipulation();


protected:

	virtual void BeginPlay() override;

public:

	 FTimerHandle SnapTimer;

	 UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Time)
	 TArray<FTimeSnap> TimeSnaps;

	 UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Time)
	 bool bIsFrozen;

	 UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Time)
	 UPrimitiveComponent* OwnerRoot;

	 UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Time)
	 bool bIsRewinding;

	 UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Time)
	 float MaxTimeTracked;

	 UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Time)
	 float MaxSnaps;

	 UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Time)
	 float RewindSpeed;

	 UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Time)
	 float Progress;

	 UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Time)
	 float SnapFrequency;
};