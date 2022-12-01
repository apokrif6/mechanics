// Fill out your copyright notice in the Description page of Project Settings.


#include "LiftPlatform.h"

#include "mechanics/mechanicsCharacter.h"

void ALiftPlatform::Tick(float DeltaTime)
{
}

void ALiftPlatform::OnStep(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<AmechanicsCharacter>(OtherActor) == nullptr)
	{
		return;
	}

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, TEXT("Step!"));
	}
}
