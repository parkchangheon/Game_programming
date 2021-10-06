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

	tBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Root")); //���� ��ü�� �����. ������Ҵ� ���ڴ�
	tBox->SetGenerateOverlapEvents(true); // Box->bGenerateOverlapEvents=true;
	tBox->OnComponentBeginOverlap.AddDynamic(this, &AMyActor::TriggerEnter);

	tBox->SetRelativeScale3D(BoxSize);
	RootComponent = tBox;

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	MyMesh->AttachTo(RootComponent);//MyMesh�� RootComponent�� �����Ų��.

	//�����޽��� �ڽ���ü�� ����. staticMesh�� ���ӿ��� ���� ���̴°�
	//���� �޽��� ���͸� ���� ���ϻ�.

	SpeedScale = 0.0f;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime) 
{
	Super::Tick(DeltaTime);  //DeltaTime�� ������ �����ӿ��� ���ӿ��� �帥�ð�

	FVector NewLocation = GetActorLocation(); // ������ ��ġ�� ��´�.
	float DeltaHeight = (FMath::Sin(RunningTime+DeltaTime)-FMath::Sin(RunningTime));
	//sin�� ����ϴ� ������ -1~ 1���̿� �����ϴ� ������ ���� �̵���ų �� �ֱ� ������?
	//1�� ġ�� �ٽ� -1�� ġ��, 1�� ġ��...���͸� ���Ʒ��� �����̰� �� �� �����Ƿ�...

	//�̰� ��� �������� ������?
	//NewLocation.Z += DeltaHeight * 20.0f; #2������ ����
	NewLocation.Y += DeltaHeight * SpeedScale;
	RunningTime += DeltaTime;
	SetActorLocation(NewLocation);
}


void AMyActor::TriggerEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	FVector PlayerStartingLocation = FVector(-350.0f, -100.0f, 235.0f);   //�÷��̾��� ���� ��ġ�� �����ϴµ�, �Ŀ� �޽���� �浹 �Ŀ� ���ƿ��� ���ϱ� ���� ����.
	//�÷��̾ ���� �΋H������ �ٽ� ��Ÿ�� ����Ʈ�� ���ư������Ѵ�.
	OtherActor->SetActorLocation(PlayerStartingLocation);
}
