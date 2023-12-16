// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TTGameInstance.generated.h"


USTRUCT()
struct FStudentData
{
	GENERATED_BODY()

		FStudentData() { Name = TEXT("Park"), Order = 3; }
	FStudentData(FString InName, int32 InOrder) :Name(InName), Order(InOrder) {}

	UPROPERTY()
	FString Name;

	UPROPERTY()
	int32 Order;

};

UCLASS()
class TOUCHTEST_API UTTGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	UTTGameInstance();
	virtual void Init()override;

	FString MakeRandomName();

private :
	TArray<FStudentData> StudentData;

	UPROPERTY()	//Student��� �𸮾� ��ü�� ��ұ⿡, UPROPERTY() �����������.
	TArray<TObjectPtr<class UStudent>> Students;	//�����͸� ����.

	TMap<int32, FString> StudentsMap;

private:
	UPROPERTY()    
	FString SchoolName;

	UPROPERTY()
	TObjectPtr<class UCourseInfo> CourseInfo;
};

