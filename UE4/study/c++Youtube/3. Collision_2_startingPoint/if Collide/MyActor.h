// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class TUTORIAL_OF_C_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

	UPROPERTY(EditAnywhere)
		UShapeComponent* tBox; // ����� UShapeComponent ������ ���� ��ü tBOX
	// ����? �𸮾� ���÷��� �ý��ۿ� �ش� ������Ƽ�� ������ �˸�
	// ���÷����� ���α׷��� ����ð��� �ڱ��ڽ��� �����ϴ� ���.

	UPROPERTY(EditAnywhere) // ����� u ���� ���� ��� ��δ� �츮�� �ִ� �Ӽ��� ��� �������� ������� ���ȴ�.
		UStaticMeshComponent* MyMesh;

	UPROPERTY(EditAnywhere)
		float SpeedScale;


	float RunningTime;
	
	FVector BoxSize = FVector(1.5f, 1.5f, 1.5f);

	UFUNCTION()
		void TriggerEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
		// �÷��̾ �����̴� �޽��� �΋H������ ( �ݸ��� �ڽ���) �ٽ� ���������� ���Բ� �ϴ� �Լ�
		// �̰��� MyActor.cpp�� BOX�� ���� ���Ѻ���



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
