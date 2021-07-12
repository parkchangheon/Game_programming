// Fill out your copyright notice in the Description page of Project Settings.


#include "ARPlayer.h"

// Sets default values
AARPlayer::AARPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// ���̷�Ż �޽� �ε� => Onlt at spawner... ĳ���� ���۷��� �ҷ������ �ҷ����� ���
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> BodyAsset(TEXT("SkeletalMesh'/Game/ParagonCountess/Characters/Heroes/Countess/Meshes/SM_Countess.SM_Countess'"));

	//������ �𸮾󿡼� ���� �� �����Ƿ�, Ȯ���ϴ� �۾��� �ʿ���
	if (BodyAsset.Succeeded())
		GetMesh()->SetSkeletalMesh(BodyAsset.Object);
	//�����ϰ� �ε��ϸ� �𸮾� c++ Ŭ���� �׿� �����ȴ�.

	//ĳ���Ͱ� ���ֱ� ������ ������� ��ġ�� �����ϱ� ���� ���� ó���� ���ش�. ���� �𸮾󿡼� ���� Ʈ���������� ������ 
	GetMesh()->SetRelativeLocation(FVector(0, 0, -88.f));
}

// Called when the game starts or when spawned
void AARPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AARPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input �Է�ó�� 
void AARPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

