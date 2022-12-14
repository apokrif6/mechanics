#include "NPC.h"

#include "mechanics/mechanicsCharacter.h"
#include "mechanics/MyHUD/MyHUD.h"

ANPC::ANPC()
{
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box collision"));
	BoxCollision->InitBoxExtent(FVector(250, 250, 100));
	BoxCollision->SetCollisionProfileName(TEXT("Trigger"));
	BoxCollision->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ANPC::BeginPlay()
{
	Super::BeginPlay();
	
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ANPC::OnOverlapBegin);

}

// Called every frame
void ANPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANPC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ANPC::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<AmechanicsCharacter>(OtherActor) == nullptr)
	{
		return;
	}

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	
	AMyHUD* MyHUD = Cast<AMyHUD>(PlayerController->GetHUD());
	
	MyHUD->AddMessage(FMessage(NpcMessage, 2.f, FColor::Red));
}
