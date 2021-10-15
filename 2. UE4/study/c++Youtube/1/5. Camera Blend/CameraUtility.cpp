// Fill out your copyright notice in the Description page of Project Settings.

#include "CameraUtility.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACameraUtility::ACameraUtility()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACameraUtility::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACameraUtility::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//const = ������ �� ���Բ� ������ ����.
	const float TimeBetweenCameraChanges = 2.0f;
	const float SmoothBlendTime = 0.75f;

	TimeToNextCameraChange -= DeltaTime; // ī��Ʈ �ٿ�.

	if (TimeToNextCameraChange <= 0.0) {
		TimeToNextCameraChange += TimeBetweenCameraChanges;

		APlayerController* OurPlayer = UGameplayStatics::GetPlayerController(this, 0);
		if (OurPlayer)
		{
			if (CameraTwo && (OurPlayer->GetViewTarget()==CameraOne))
			{
				OurPlayer -> SetViewTargetWithBlend(CameraTwo,SmoothBlendTime); // smoothBlendTime�� ��������ν� �ε巴�� �̵�. 
			}
			else if (CameraOne)
			{
				OurPlayer->SetViewTarget(CameraOne);
			}
		}
	}
}

