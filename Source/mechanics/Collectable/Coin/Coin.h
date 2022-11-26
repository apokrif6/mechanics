#pragma once

#include "CoreMinimal.h"
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

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION()
	virtual void OnCollect(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
	                       int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
};


