// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UIMainMenu.h"
#include "UINewGameMode.generated.h"

/**
 * 
 */
UCLASS()
class UI_PRACTICE_API AUINewGameMode : public AGameModeBase
{
	GENERATED_BODY()


public:
	UFUNCTION(BlueprintCallable, Category = "UMG_Game")
	void ChangeMenuWidget(TSubclassOf<UUserWidget>NewWidgetClass);
	//TSubClassOf => �𸮾� �������� UCLASSŸ���� �������� �����ϴ� ���ø� Ŭ����
	// TSubclassOf�� ���޵� ����� <> �ȿ� �־��� ���� Ÿ�԰� ��ġ�ϰų�, ���ø� ���ڷ� ���� Ÿ���� ��ӹ��� Ÿ������ �˻��Ѵ�. (��Ÿ�ӿ�)  

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG_Game")
	TSubclassOf<UUserWidget> StartingWidgetClass;

	UPROPERTY()
	UUserWidget* CurrentWidget;


};
