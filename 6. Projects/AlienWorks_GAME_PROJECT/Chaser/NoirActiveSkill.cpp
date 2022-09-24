// Fill out your copyright notice in the Description page of Project Settings.

#include "Noir.h"
#include "NoirActiveSkill.h"
#include "GameFramework/ProjectileMovementComponent.h"


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
	RootComponent = Mesh;
	Mesh->OnComponentHit.AddDynamic(this, &ANoirActiveSkill::OnHit);

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->SetUpdatedComponent(Mesh);
	ProjectileMovementComponent->InitialSpeed = 500.0f;
	ProjectileMovementComponent->MaxSpeed = 3000.0f;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;
	ProjectileMovementComponent->bShouldBounce = false;
	/*ProjectileMovementComponent->Bounciness = 0.3f;*/

	InitialLifeSpan = 3.0f;
}

// Called when the game starts or when spawned
void ANoirActiveSkill::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Projectile has spawned!!"));
	

}

// Called every frame
void ANoirActiveSkill::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANoirActiveSkill::FireInDirection(const FVector& ShootDirection)
{
	ProjectileMovementComponent->Velocity = ShootDirection * ProjectileMovementComponent->InitialSpeed;
}


void ANoirActiveSkill::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit) 
{
	if (OtherActor != this && OtherComponent->IsSimulatingPhysics())
		OtherComponent->AddImpulseAtLocation(ProjectileMovementComponent->Velocity * 100.0f, Hit.ImpactPoint);
}


//collision ������, spawn emitter at location�� �ѹ� �Ẹ��