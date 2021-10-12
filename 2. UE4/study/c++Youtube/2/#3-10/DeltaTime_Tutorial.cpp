// Fill out your copyright notice in the Description page of Project Settings.
//DeltaTime �̶� Fstring���� ��ü�� �޾ƿ��� �� ���� �����Ͽ���.
// FTransform -> ����ü ���� (F Ű����� ����ü�̴�) 

#include "DeltaTime_Tutorial.h"

// Sets default values
ADeltaTime_Tutorial::ADeltaTime_Tutorial()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADeltaTime_Tutorial::BeginPlay()
{
	Super::BeginPlay();
	FString ActorName = GetName(); //FString ������ �޴´� GetName�� �ƴ϶� GetActorLabel�� �ϸ� ������Ⱑ ����ȴ�.
	UE_LOG(LogTemp, Warning, TEXT("MY Name is %s"), *ActorName);
	// -------------------------------------------------------------------------

	//FTransform ����
	FTransform ActorTransform = GetTransform(); // 
	ActorTransform.GetRotation();//GetScale3D , Location... ��Ÿ ����� ���� �� ����. (Transform�� �ִ� �͵�)

	UE_LOG(LogTemp, Warning, TEXT("Location X=  %.3f"), ActorTransform.GetRotation().X);
}

// Called every frame
void ADeltaTime_Tutorial::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); //DeltaTime�� 30FPS �̸� 1/30 => 0.0333���� ~ 
	FVector NewLocation = GetActorLocation();

	NewLocation.Z += SpeedDelta * DeltaTime;
	SetActorLocation(NewLocation);
}

