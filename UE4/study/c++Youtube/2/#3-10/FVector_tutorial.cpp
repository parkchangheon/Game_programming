// Fill out your copyright notice in the Description page of Project Settings.


#include "FVector_tutorial.h"

// Sets default values
AFVector_tutorial::AFVector_tutorial()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFVector_tutorial::BeginPlay()
{
	Super::BeginPlay();

	/*
	//1 ��° ��� 
	FTransform ActorTransform = GetTransform();
	FVector Location  = ActorTransform.GetLocation();

	//2��° ��� 
	GetTransform().GetLocation();

	//3��° ���
	GetActorLocation();
	*/

	//�� ��� �����ϰ� ����ü�� ���� ��ĵ� ����
	FVector ActorLocation = FVector(10.f, 15.f, 20.f);
	SetActorLocation(ActorLocation);
}

// Called every frame
void AFVector_tutorial::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

