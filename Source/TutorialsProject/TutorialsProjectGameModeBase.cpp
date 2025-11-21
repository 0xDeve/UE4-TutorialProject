// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "TutorialsProjectGameModeBase.h"

#include "Blueprint/UserWidget.h"

void ATutorialsProjectGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	if (SampleWidgetClass)
	{
		if (UUserWidget* SampleWidget = CreateWidget<UUserWidget>(GetWorld(), SampleWidgetClass))
		{
			if (UFunction* UpdateHealthFunc = SampleWidget->FindFunction(FName("SetHealth")))
			{
				struct FSetHealthParams { double NewHealth; };
				FSetHealthParams Params;
				float RandomHealth = FMath::RandRange(0, 100);
				Params.NewHealth = RandomHealth;
				SampleWidget->ProcessEvent(UpdateHealthFunc, &Params);
			}
			SampleWidget->AddToViewport();
		}
	}
}
