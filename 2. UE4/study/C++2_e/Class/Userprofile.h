// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Userprofile.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class CPP_STUDY_API UUserprofile : public UObject
{
	GENERATED_BODY()
	

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	float Armor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	float HpMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	FString Name;


	//�������Ʈ ��Ӵٿ� �޴����� UObject�κ��� �Ļ��� ��� UClass�� ���
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = Unit)
	TSubclassOf<UObject> UClassOfPlayer;

	//GameMode C++���̽� Ŭ�����κ��� �Ļ��� UCLASS���� ���ڿ� �̸��� ���
	UPROPERTY(EditAnywhere, meta = (MetaClass = "GameMode"),
		Category = Unit)
		FStringClassReference UClassGameMode;
};


