// Fill out your copyright notice in the Description page of Project Settings.


#include "FlyingFurniture.h"

// Sets default values
AFlyingFurniture::AFlyingFurniture()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;  // Tick �Լ��� �� �����Ӹ��� ȣ��ɰŶ��Ŵ�.

}

// Called when the game starts or when spawned
void AFlyingFurniture::BeginPlay()
{
	Super::BeginPlay();  //BeginPlay�� �����Լ��̴�.  �� �Լ��� �������ϴ� ����� ������ �ִ�.
	// �� ���� BeingPlay���� ��� �Լ����� ȣ���ؿ´�.
	
}

// �⺻
//// Called every frame
//void AFlyingFurniture::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//	FVector NewLocation = GetActorLocation(); //FVector���·� ��ȯ
//	// NewLocation.Z += 20; => �׳� �̴�θ� �����ϸ� ������ ���� 20�� �����ϹǷ� 30�����ӿ��� 600, 60�����ӿ��� 1200 �����Ѵ�
//	//�ذ�å->
//	NewLocation.Z += 20 * DeltaTime; //Deltatime�� ���� �ذ�..
//	//������ ��ġ ���� ���
//	SetActorLocation(NewLocation);
//
//	
//
//	// �ش� �ڵ�� ������ �ð��� �ϴ÷� �ö󰡴� �������� �� �� �ִ�.
//}



