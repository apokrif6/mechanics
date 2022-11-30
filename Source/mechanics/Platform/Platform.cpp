#include "Platform.h"

APlatform::APlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	
	SetMobility(EComponentMobility::Movable);
}

void APlatform::BeginPlay()
{
	Super::BeginPlay();

	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
}

void APlatform::Tick(float DeltaTime)
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

void APlatform::SwapTarget()
{
	FVector LocationToSwap = GlobalStartLocation;
	GlobalStartLocation = GlobalTargetLocation;
	GlobalTargetLocation = LocationToSwap;
}
