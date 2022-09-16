// Fill out your copyright notice in the Description page of Project Settings.

#include "Noir.h"
#include "NoirActiveSkill.h"


// Sets default values
ANoirActiveSkill::ANoirActiveSkill()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	//createdefaultsubobject�� ����, �޽ø� ���� delete �����൵ �� -> ����Ʈ �����Ͱ��� ����
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("StaticMesh'/Game/PCH_PRIVATE/SM_airConditioner01.SM_airConditioner01'"));
	if (SM.Succeeded())
	{
		Mesh->SetStaticMesh(SM.Object);
	}
}

// Called when the game starts or when spawned
void ANoirActiveSkill::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANoirActiveSkill::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

