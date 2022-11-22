// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "mechanics/Collectable/Collectable.h"
#include "Coin.generated.h"

UCLASS()
class MECHANICS_API ACoin : public AActor, public ICollectable
{
	GENERATED_BODY()

public:
	ACoin();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* CoinMesh;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* SphereComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void OnCollect(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
};


