#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

struct FMessage
{
	FString Message;
	float Time;
	FColor Color;
	FMessage()
	{
		Time = 5.f;
		Color = FColor::White;
	}
	FMessage(FString IMessage, float ITime, FColor IColor)
	{
		Message = IMessage;
		Time = ITime;
		Color = IColor;
	}
};

UCLASS()
class MECHANICS_API AMyHUD : public AHUD
{
public:
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUDFont)
	UFont* HUDFont;

	TArray<FMessage> Messages;
	
	virtual void DrawHUD() override;
	void AddMessage(FMessage Message);
};
