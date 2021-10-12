// Fill out your copyright notice in the Description page of Project Settings.


#include "Furniture_RL.h"

// Sets default values
AFurniture_RL::AFurniture_RL()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFurniture_RL::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFurniture_RL::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector Location_RL = GetActorLocation();

	Location_RL.X += 20 * DeltaTime;
	SetActorLocation(Location_RL);
}



//UPROPERTY�� ��ũ���̴�
//�𸮾� �����Ϳ��� �������� �ٲ� �� �ְ� ���ش�
// ���� ���α׷��� ������ ���� �����̳ʰ� ����ϱ� ���ϰ� �Ѵ�.
