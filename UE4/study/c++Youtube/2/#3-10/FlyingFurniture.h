// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FlyingFurniture.generated.h" //�׻� ������ �ٿ� ����

UCLASS()  // ��ũ���̰�, �𸮾� ������Ʈ���� �����ϱ� ����
class BASIC_C_TUTORIAL_API AFlyingFurniture : public AActor
{
	// A~ �ö��� �۴��� ���� ���λ縦 ���־�, ǥ�� (Actor - A)
	// ���λ�� ũ�� A�� U�� ���Ǹ�, A�� ����, U�� Ŭ����.
	GENERATED_BODY() // �ش� Ŭ������ �𸮾� ������Ʈ���� �����ϱ� ����.
	
public:	
	// Sets default values for this actor's properties
	AFlyingFurniture();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override; //�������̵��Ѵ�.

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override; // ƽ�� �� ���� �����Ӹ��� ���� 30FPS�� 1�ʸ��� 30�� ȣ��

};
