// Fill out your copyright notice in the Description page of Project Settings.

#include <Blueprint/UserWidget.h>
#include "GameMode/UINewGameMode.h"


void AUINewGameMode::BeginPlay()
{
	Super::BeginPlay();
	ChangeMenuWidget(StartingWidgetClass);
}


void AUINewGameMode::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
	// 1. ���� ������ �����Ѵٸ� �����
	// 2. ������ ǥ���� ������ ����� => �ش� ������ CurrentWidget�� ������ش�.

	if (CurrentWidget != nullptr)
	{
		CurrentWidget->RemoveFromViewport();
		CurrentWidget = nullptr;
	}

	if (NewWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget(GetWorld(), NewWidgetClass);
		if (CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
		}
	}



}