#include "MyHUD.h"

#include "Engine/Canvas.h"

void AMyHUD::DrawHUD()
{
	Super::DrawHUD();
	
	for (int i = Messages.Num() - 1; i >= 0; i--)
	{
		FMessage& CurrentMessage = Messages[i];
		
		float OutputWidth, OutputHeight, Pad = 10.f;
		
		GetTextSize(CurrentMessage.Message, OutputWidth, OutputHeight, HUDFont, 1.f);
		
		float MessageHeight = OutputHeight + 2.f * Pad;
		float x = 0.f;
		float y = i * MessageHeight;
		
		DrawRect(FLinearColor::Black, x, y, Canvas->SizeX, MessageHeight);
		DrawText(CurrentMessage.Message, CurrentMessage.Color, x + Pad, y + Pad, HUDFont);
	
		CurrentMessage.Time -= GetWorld()->GetDeltaSeconds();
		
		if (CurrentMessage.Time < 0)
		{
			Messages.RemoveAt(i);
		}
	}
}

void AMyHUD::AddMessage(FMessage Message)
{
	Messages.Add(Message);
}