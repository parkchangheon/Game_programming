// Fill out your copyright notice in the Description page of Project Settings.


#include "SwingDoor.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ASwingDoor::ASwingDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Open = false;
	ReadyState = true;
	DoorFrame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door Frame"));//����
	RootComponent = DoorFrame; // root�� �� ������ ��ġ��Ŵ

	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door")); //�� ����
	Door->SetupAttachment(RootComponent); // ���� ������ �Ʒ��� ����.

}

// Called when the game starts or when spawned
void ASwingDoor::BeginPlay()
{
	Super::BeginPlay();
	RotateValue = 1.0f;

	if (DoorCurve) 
	{
		FOnTimelineFloat TimelineCallback; // 
		FOnTimelineEventStatic TimelineFinishCallback; //

		TimelineCallback.BindUFunction(this, FName("ControlDoor"));// �Լ� ���ε�.
		TimelineFinishCallback.BindUFunction(this, FName("SetState"));

		MyTimeLine.AddInterpFloat(DoorCurve, TimelineCallback); // ������ �߰�.(�������� ���̸� ����)
		MyTimeLine.SetTimelineFinishedFunc(TimelineFinishCallback); // 

	}
}

// Called every frame
void ASwingDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MyTimeLine.TickTimeline(DeltaTime); // Ÿ�Ӷ����� �����ð����� �������ش�.
}


void ASwingDoor::ControlDoor()
{
	Timelinevalue = MyTimeLine.GetPlaybackPosition();
	CurveFloatValue = RotateValue * DoorCurve->GetFloatValue(Timelinevalue);

	FQuat NewRotation = FQuat(FRotator(0.0f, CurveFloatValue, 0.0f));
	Door->SetRelativeRotation(NewRotation);
}

void ASwingDoor::SetState()
{
	ReadyState = true;
}

void ASwingDoor::ToggleDoor() {
	if (ReadyState)
	{
		Open = !Open;

		APawn* OurPawn = UGameplayStatics::GetPlayerPawn(this, 0);
		FVector PawnLocation = OurPawn->GetActorLocation();
		FVector Direction = GetActorLocation() - PawnLocation;
		Direction = UKismetMathLibrary::LessLess_VectorRotator(Direction, GetActorRotation());

		DoorRotation = Door->GetRelativeRotation();


		if (Open) {
			if (Direction.X > 0.0f) {
				RotateValue = 1.f;
			}
			else {
				RotateValue = -1.0f;
			}
			ReadyState = false;
			MyTimeLine.PlayFromStart();
		}

		else 
		{
			ReadyState = false;
			MyTimeLine.Reverse();
		}
	}
}