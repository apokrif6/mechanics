#include "Platform.h"

APlatform::APlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	
	SetMobility(EComponentMobility::Movable);
}

void APlatform::BeginPlay()
{
	Super::BeginPlay();

	LoopMove();
}

void APlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Timeline.TickTimeline(DeltaTime);
}

void APlatform::HandleMovingProgress(float Value)
{
	const FVector LocationToMove = FMath::Lerp(GlobalStartLocation, GlobalTargetLocation, Value);
	SetActorLocation(LocationToMove);
}


void APlatform::LoopMove()
{
	if (CurveFloat)
	{
		FOnTimelineFloat ProgressFunction;

		ProgressFunction.BindUFunction(this, HandleRequestFunctionName);

		Timeline.AddInterpFloat(CurveFloat, ProgressFunction);
		Timeline.SetLooping(true);

		GlobalStartLocation = GetActorLocation();
		GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);

		Timeline.PlayFromStart();
	}
}
