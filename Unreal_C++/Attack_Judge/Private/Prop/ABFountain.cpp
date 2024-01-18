
#include "Prop/ABFountain.h"
#include "Components/StaticMeshComponent.h"
// CDO���� ������ ������Ʈ�� �ڵ����� ���忡 ����� �ȴ�.
// NewObject�� ������ ������Ʈ�� �ݵ�� ��������� ���ľ��Ѵ�.
// ��ϵ� ������Ʈ�� ������ ����� ����� �� ������, ������ ������ ó���� �շ��Ѵ�.

// ������Ʈ Ȯ�� ����
// - ������ ���� �� BP���� �°踦 ���� ����
// - UPROPERTY() ������ ���� ����.

// ������Ʈ ������.
// Visible/Edit -> ũ�� ��üŸ�԰� ��Ÿ������ ���.
// anywhere, DefaultsOnly, InstanceOnly => ������ ���� ���ɿ���.
// BlueprintReadOnly / BlueprintReadWrite => BP�� Ȯ��� �б� Ȥ�� �б� ���� ���� �ο�
// Category => ������ ���� ���������� ī�װ� ����.


AABFountain::AABFountain()
{
	PrimaryActorTick.bCanEverTick = true;
	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	Water = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Water"));

	RootComponent = Body;
	Water->SetupAttachment(Body);
	Water->SetRelativeLocation(FVector(0.f, 0.f, 132.f));

	//������ ���� �ڵ��̱⿡ constructorHelpers�� �����.
	ConstructorHelpers::FObjectFinder<UStaticMesh>BodyMeshRef(TEXT("/Script/Engine.StaticMesh'/Game/ArenaBattle/Environment/Props/SM_Plains_Castle_Fountain_01.SM_Plains_Castle_Fountain_01'"));
	if (BodyMeshRef.Object)
	{
		Body->SetStaticMesh(BodyMeshRef.Object);
	}

	static ConstructorHelpers::FObjectFinder<UStaticMesh> WaterMeshRef(TEXT("/Script/Engine.StaticMesh'/Game/ArenaBattle/Environment/Props/SM_Plains_Fountain_02.SM_Plains_Fountain_02'"));
	if (WaterMeshRef.Object)
	{
		Water->SetStaticMesh(WaterMeshRef.Object);
	}
}

void AABFountain::BeginPlay()
{
	Super::BeginPlay();
	
}

void AABFountain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

