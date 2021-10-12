// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UserProfile.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class C_PLUS_PROJECT_API UUserProfile : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)    //EditAnywhere �� UPROPERTY�� �ڵ� �Ǵ� �����⸦ ���� ���氡���ϴٴ� �ǹ�,, BlueprintReadWrite�� �������Ʈ�� ������ ������ �а� ���� ������ �ǹ�
	float Armor;
	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	float HpMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	FString Name;



	//�������Ʈ ��Ӵٿ� �޴����� UObject�κ��� �Ļ��� ��� UClass ���
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Unit)
	TSubclassOf<UObject>UClassOfPlayer;


	//GameMode C++���̽� Ŭ�����κ��� �Ļ��� UCLASS���� ���ڿ� �̸��� ���
	UPROPERTY(EditAnywhere, meta = (MetaClass = "GameMode"), Category = Unit)
	FStringClassReference UClassGameMode;


	//Custom struct example UPROPERTY(EditAnywhere, BlueprintReadWrite,Category=HUD)
};





