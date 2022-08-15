// Fill out your copyright notice in the Description page of Project Settings.


#include "TestCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"


//ĳ���� ����
enum CHARATER_STATE
{
	NORMAL_STATE,     //�Ϲݻ���
	SHOCK_STATE,      //��������
	EXPOSED_STATE,    //�������
	CLOAKING_STATE,  //���Ż���
	FAST_STATE,      //�żӻ���
	ARRESTED_STATE   //ü������
};


// Sets default values
ATestCharacter::ATestCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);

	TurnRateGamepad = 50.f;

	//// Don't rotate when the controller rotates. Let that just affect the camera.
	//bUseControllerRotationPitch = false;
	//bUseControllerRotationYaw = false;
	//bUseControllerRotationRoll = false;

	//ĳ���� ������ ����
	GetCharacterMovement()->bOrientRotationToMovement = true; //�ڵ������� ĳ������ �̵��������� �������ش�.
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.f, 0.0f);

	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));

	
	CameraBoom->SetupAttachment(RootComponent);
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);

	CameraBoom->TargetArmLength = 500.0f;

	//CameraBoom->SetRelativeRotation(FRotator(-35.f, 0.f, 90.f));
	//GetMesh()->SetRelativeLocationAndRotation(
	//	FVector(0.f, 0.f, -88.f), FRotator(0.f, -90.f, 0.f));
	
	CameraBoom->bUsePawnControlRotation = true; 
	FollowCamera->bUsePawnControlRotation = false; 
}

// Called when the game starts or when spawned
void ATestCharacter::BeginPlay()
{
	UE_LOG(LogTemp, Log, TEXT("CHARACTER Spwan"));
	Super::BeginPlay();
	
}

// Called every frame
void ATestCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Warning, TEXT("Character Input Tick"));
}

// Called to bind functionality to input
void ATestCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ATestCharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ATestCharacter::StopJumping);

	PlayerInputComponent->BindAxis("Move Forward / Backward", this, &ATestCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Move Right / Left", this, &ATestCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn Right / Left Mouse", this, &ATestCharacter::Yaw);
	//PlayerInputComponent->BindAxis("Look Up / Down Mouse", this, &APawn::AddControllerPitchInput);
}

//void ATestCharacter::TurnAtRate(float Rate)
//{
//	// calculate delta for this frame from the rate information
//	AddControllerYawInput(Rate * TurnRateGamepad * GetWorld()->GetDeltaSeconds());
//}
//
//void ATestCharacter::LookUpAtRate(float Rate)
//{
//	// calculate delta for this frame from the rate information
//	AddControllerPitchInput(Rate * TurnRateGamepad * GetWorld()->GetDeltaSeconds());
//}

//void ATestCharacter::MoveForward(float value) 
//{
//	if ((Controller != nullptr) && (value != 0.0f))
//	{
//		//������ Ȯ���ϴ� �ڵ�
//		const FRotator Rotation = Controller->GetControlRotation();
//		const FRotator YawRotation(0, Rotation.Yaw, 0);
//		
//		//���� ���� �ޱ�
//		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
//		AddMovementInput(Direction, value);
//	}
//}
//
//
//void ATestCharacter::MoveRight(float value)
//{
//	if ((Controller != nullptr) && (value != 0.0f))
//	{
//		//GetControlRotation�� ��Ʈ�ѷ��� roation�� �����Ѵ�.
//		const FRotator Rotation = Controller->GetControlRotation();
//		const FRotator YawRotation(0, Rotation.Yaw, 0);
//
//		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
//		AddMovementInput(Direction, value);
//	}
//}


void ATestCharacter::Yaw(float value)
{
	AddControllerYawInput(value);
}