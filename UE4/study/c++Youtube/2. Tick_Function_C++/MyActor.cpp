// Fill out your copyright notice in the Description page of Project Settings.

#include "tutorial_of_c.h"
#include "MyActor.h"
#include "Components/BoxComponent.h"
#include "WorldCollision.h"
#include "PrimitiveViewRelevance.h"
#include "PrimitiveSceneProxy.h"
#include "SceneManagement.h"
#include "PhysicsEngine/BoxElem.h"
#include "PhysicsEngine/BodySetup.h"
#include "PrimitiveSceneProxy.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true; //ƽ����� ����Ѵ�.

	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root")); //���� ��ü�� �����. ������Ҵ� ���ڴ�
	RootComponent = Root;

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	MyMesh->AttachTo(RootComponent);//MyMesh�� RootComponent�� �����Ų��.

	//�����޽��� �ڽ���ü�� ����. staticMesh�� ���ӿ��� ���� ���̴°�
	//���� �޽��� ���͸� ���� ���ϻ�.


}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation(); // ������ ��ġ�� ��´�.
	float DeltaHeight = (FMath::Sin(RunningTime+DeltaTime)-FMath::Sin(RunningTime));
	//sin�� ����ϴ� ������ -1~ 1���̿� �����ϴ� ������ ���� �̵���ų �� �ֱ� ������?
	//1�� ġ�� �ٽ� -1�� ġ��, 1�� ġ��...���͸� ���Ʒ��� �����̰� �� �� �����Ƿ�...

	//�̰� ��� �������� ������?
	NewLocation.Z += DeltaHeight * 20.0f; 
	RunningTime += DeltaTime;
	SetActorLocation(NewLocation);


}

