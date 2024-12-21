#include "TimeObjectBase.h"
#include "TimeComponent.h"
#include "Materials/MaterialInterface.h"

ATimeObjectBase::ATimeObjectBase()
{
	PrimaryActorTick.bCanEverTick = false;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	RootComponent = StaticMesh;
	StaticMesh->SetSimulatePhysics(true);

	TimeComponent = CreateDefaultSubobject<UTimeComponent>(TEXT("Time Component"));
}

void ATimeObjectBase::TimePause()
{
	if (!TimeComponent->bIsFrozen)
	{
		TimeComponent->bIsFrozen = true;

		OriginalMaterials = StaticMesh->GetMaterials();

		for (int x = 0; x < OriginalMaterials.Num(); x++)
		{
			StaticMesh->SetMaterial(x, TimeMaterial);
		}
	}
}

void ATimeObjectBase::TimeEnd()
{
	TimeComponent->StopManipulation();

	for (int x = 0; x < OriginalMaterials.Num(); x++)
	{
		StaticMesh->SetMaterial(x, OriginalMaterials[x]);
	}
}

void ATimeObjectBase::TimeReverse(float ReverseSpeed)
{
	if (ReverseSpeed > 0.f)
	{
		TimeComponent->bIsRewinding = true;
		TimeComponent->RewindSpeed = ReverseSpeed;
	}
	else
	{
		TimeComponent->bIsFrozen = true;
		TimeComponent->bIsRewinding = false;
	}
}

void ATimeObjectBase::BeginPlay()
{
	Super::BeginPlay();
}

void ATimeObjectBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
