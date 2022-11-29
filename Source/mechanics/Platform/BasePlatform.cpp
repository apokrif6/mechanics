#include "BasePlatform.h"

ABasePlatform::ABasePlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	
	SetMobility(EComponentMobility::Movable);
}

void ABasePlatform::BeginPlay()
{
	Super::BeginPlay();

	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
}

void ABasePlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Location = GetActorLocation();
	
	const float Distance = (GlobalTargetLocation - GlobalStartLocation).Size();
	const float DistanceTraveled = (Location - GlobalStartLocation).Size();

	if (DistanceTraveled >= Distance)
	{
		SwapTarget();
	}

	FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();

	Location += Speed * Direction * DeltaTime;

	SetActorLocation(Location);
}

void ABasePlatform::SwapTarget()
{
	FVector LocationToSwap = GlobalStartLocation;
	GlobalStartLocation = GlobalTargetLocation;
	GlobalTargetLocation = LocationToSwap;
}
