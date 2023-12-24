// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Engine/StreamableManager.h"
#include "TTGameInstance.generated.h"



UCLASS()
class TOUCHTEST_API UTTGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	virtual void Init()override;
	UTTGameInstance();

	// ��Ű���� �̿��Ͽ� ����/�ε�
	void SaveStudentPackage() const;
	void LoadStudentPackage() const;

	// ��θ� �̿��Ͽ� ����/�ε�
	void LoadStudentObject()const;

private:
	UPROPERTY()
	TObjectPtr<class USerialize_Student> StudentSrc;

	static const FString PackageName;
	static const FString AssetName;


	//�񵿱� �ε�
	FStreamableManager StreamableManager;
	TSharedPtr<FStreamableHandle> Handle;		//��Ʈ���ֵ� �ּ��� ������ �� �ִ� Handler

};

