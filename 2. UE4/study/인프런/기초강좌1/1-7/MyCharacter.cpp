// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "MyAnimInstance.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

	SpringArm->SetupAttachment(GetCapsuleComponent()); // ĸ��������Ʈ�� ��Ʈ������Ʈ�� ���� ������ ���� �ٿ���
	Camera->SetupAttachment(SpringArm);

	SpringArm->TargetArmLength = 500.f; //������ �� ����
	SpringArm->SetRelativeRotation(FRotator(-35.f, 0.f, 0.f)); //ĸ���� �������� ȸ��

	GetMesh()->SetRelativeLocationAndRotation(
		FVector(0, 0, -88.f), FRotator(0.f, -90.f, 0.f));
	


	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SM(TEXT("SkeletalMesh'/Game/ParagonRevenant/Characters/Heroes/Revenant/Meshes/Revenant.Revenant'"));
	if (SM.Succeeded()) {
		GetMesh()->SetSkeletalMesh(SM.Object);
	}
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	AnimInstance = Cast<UMyAnimInstance>(GetMesh()->GetAnimInstance());
	AnimInstance->OnMontageEnded.AddDynamic(this, &AMyCharacter::OnAttackMontageEnded); //Montage�� ������, ���� �Լ��� ȣ���ض�
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed,this,&AMyCharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Attack"), EInputEvent::IE_Pressed, this, &AMyCharacter::Attack);

	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AMyCharacter::UpDown);
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AMyCharacter::LeftRight);
	PlayerInputComponent->BindAxis(TEXT("Yaw"), this, &AMyCharacter::Yaw);
}

void AMyCharacter::UpDown(float Value)
{
	//UE_LOG(LogTemp, Warning, TEXT("UpDown %f"), Value);
	AddMovementInput(GetActorForwardVector(), Value);
}

void AMyCharacter::LeftRight(float Value)
{
	//UE_LOG(LogTemp,Warning,TEXT("LeftRight %f"), Value)
	AddMovementInput(GetActorRightVector(), Value);
}

void AMyCharacter::Yaw(float Value) {
	AddControllerYawInput(Value);
}

void AMyCharacter::OnAttackMontageEnded(UAnimMontage* Montage, bool binterrupted)
{
	IsAttacking = false;
}


void AMyCharacter::Attack() 
{
	if (IsAttacking) // �������϶��� �ٸ� ���� ���Ѵ�.
		return; 

	//AnimInstance = Cast<UMyAnimInstance>(GetMesh()->GetAnimInstance());
	//if (AnimInstance)
	
	AnimInstance->PlayAttackMontage();
	AnimInstance->JumpToSection(AttackIndex);
	AttackIndex = (AttackIndex + 1) % 3;
	
	IsAttacking = true; //������״ٸ�, �ٽ� true�� �ٲ��ش�.
}