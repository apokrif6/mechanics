// Fill out your copyright notice in the Description page of Project Settings.


#include "Coin.h"


// Sets default values
ACoin::ACoin()
{
	CoinMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Coin mesh"));

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere component"));
	SphereComponent->SetSphereRadius(250.f);
	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ACoin::OnCollect);
	
}

// Called when the game starts or when spawned
void ACoin::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACoin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACoin::OnCollect(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, TEXT("Collected!"));
	}
}