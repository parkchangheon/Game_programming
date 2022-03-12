// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "S2R_Final_PannelLever.h"
#include "S2R_Second_Lever.generated.h"

/**
 * 
 */
UCLASS()
class TPS_C_PROJECT_API AS2R_Second_Lever : public AS2R_Final_PannelLever
{
	GENERATED_BODY()
	
public:
	AS2R_Second_Lever();
	virtual void BeginPlay() override;
	void StartTimer();
	void AdvanceTimer();   // Ÿ�̸Ӱ� ���ư��鼭 ȣ��� �Լ�
	void CountdownHasFinished();  //advanceTimer�� ������ ��ŭ �۵��� �ڿ� ������ ó���ϱ� ����


	FTimerHandle CountdownTimerHandle; // Ÿ�̸Ӹ� ��Ʈ�� �ϱ� ���� ����ü, ī��Ʈ�ٿ� ���� ��, Ÿ�̸� ���� �� ���ư��� �ʰ� �Ϸ���

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lever")
	class UStaticMeshComponent* NPC_Lever;

protected: 
	virtual void NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit); 

public: 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Overlap")
	class UBoxComponent* BoxMesh;



public:
	char answer[4] = { 'w','s','d','a' };
	UPROPERTY(EditAnywhere)
	int32 CountdownTime;
	bool isholding;


};
