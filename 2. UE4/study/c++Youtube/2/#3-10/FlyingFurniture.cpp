// Fill out your copyright notice in the Description page of Project Settings.


#include "FlyingFurniture.h"
FVector NewLocation;
int Start;
int End;
bool flag = true;


// Sets default values
AFlyingFurniture::AFlyingFurniture()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;  // Tick �Լ��� �� �����Ӹ��� ȣ��ɰŶ��Ŵ�.

}

// Called when the game starts or when spawned
void AFlyingFurniture::BeginPlay()
{
	Super::BeginPlay();  //BeginPlay�� �����Լ��̴�.  �� �Լ��� �������ϴ� ����� ������ �ִ�.
	// �� ���� BeingPlay���� ��� �Լ����� ȣ���ؿ´�.
	int Number = 10;
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay() has called!!"));
	UE_LOG(LogTemp, Warning, TEXT("Number value is %d"),Number);
	/*UE_LOG�� c++ ��ũ�η�,
		������ ����ɶ�, �޽����� logging �ϰ� sending �ϴ� ������ �Ѵ�.

		�� ���� �ֳ� ?
		-checking if some method / finction is being called
		- looking at some data during gameplay*/



	
	/* // Ʃ�丮��1 ���� ��Ʈ(�ϵ�)
	NewLocation = GetActorLocation();
	Start = NewLocation.Z;
	End = NewLocation.Z + 200;
	*/
}

// �⺻
//// Called every frame
//void AFlyingFurniture::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//	FVector NewLocation = GetActorLocation(); //FVector���·� ��ȯ
//	// NewLocation.Z += 20; => �׳� �̴�θ� �����ϸ� ������ ���� 20�� �����ϹǷ� 30�����ӿ��� 600, 60�����ӿ��� 1200 �����Ѵ�
//	//�ذ�å->
//	NewLocation.Z += 20 * DeltaTime; //Deltatime�� ���� �ذ�..
//	//������ ��ġ ���� ���
//	SetActorLocation(NewLocation);
//
//	
//
//	// �ش� �ڵ�� ������ �ð��� �ϴ÷� �ö󰡴� �������� �� �� �ִ�.
//}




void AFlyingFurniture::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (flag==true) {
		NewLocation.Z += 20 * DeltaTime;
		if (NewLocation.Z >= End)
			flag = false;
	}

	if (flag == false) {
		NewLocation.Z -= 20 * DeltaTime;
		if (NewLocation.Z <= Start) {
			flag = true;
		}
	}

	
	SetActorLocation(NewLocation);

	//UE_LOG(LogTemp, Warning, TEXT("EverySingleTime!!"));



}

