
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimeWarpInterface.h"
#include "TimeObjectBase.generated.h"

class UMaterialInterface;
class UTimeComponent;

UCLASS()
class TIMEWARPC_API ATimeObjectBase : public AActor, public ITimeWarpInterface
{
	GENERATED_BODY()

public:

	ATimeObjectBase();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Time, meta = (AllowPrivateAccess = "true"))
	UTimeComponent* TimeComponent;

	virtual void TimePause() override;
	virtual void TimeEnd() override;
	virtual void TimeReverse(float ReverseSpeed) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Materials)
	TArray<UMaterialInterface*> OriginalMaterials;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Materials)
	UMaterialInterface* TimeMaterial;

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;
};