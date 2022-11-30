// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed = 50.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (MakeEditWidget))
	FVector TargetLocation;

private:
	FVector GlobalStartLocation;
	
	FVector GlobalTargetLocation;

	void SwapTarget();
};
