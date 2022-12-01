#pragma once

#include "CoreMinimal.h"
#include "Components/TimelineComponent.h"
#include "Engine/StaticMeshActor.h"
#include "Platform.generated.h"

UCLASS()
class MECHANICS_API APlatform : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	APlatform();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere)
	FTimeline Timeline;

	UPROPERTY(EditAnywhere, Category = "Timeline")
	float MaxHeight;

	UPROPERTY(EditAnywhere, Category = "Timeline")
	UCurveFloat* CurveFloat;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (MakeEditWidget))
	FVector TargetLocation;

	UFUNCTION()
	void HandleMovingProgress(float Value);
private:
	FVector GlobalStartLocation;
	
	FVector GlobalTargetLocation;

	void LoopMove();

	FName HandleRequestFunctionName = "HandleMovingProgress";
};
