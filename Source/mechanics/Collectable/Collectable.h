// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Collectable.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UCollectable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MECHANICS_API ICollectable
{
	GENERATED_BODY()

public:
	virtual void OnCollect(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) = 0;
};
