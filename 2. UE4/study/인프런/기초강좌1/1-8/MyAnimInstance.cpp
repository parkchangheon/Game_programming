// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/PawnMovementComponent.h"
#include "MyCharacter.h"

UMyAnimInstance::UMyAnimInstance()
{
	static ConstructorHelpers::FObjectFinder<UAnimMontage> AM(TEXT("AnimMontage'/Game/Animations/Revenant_Skeleton_Montage.Revenant_Skeleton_Montage'"));
	if (AM.Succeeded())
	{
		AttackMontage = AM.Object;
	}
}

void UMyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto Pawn = TryGetPawnOwner();
	if (IsValid(Pawn))
	{
		Speed = Pawn->GetVelocity().Size();
	}

	auto Character = Cast<AMyCharacter>(Pawn);
		if (Character)
		{
			isFalling = Character->GetMovementComponent()->IsFalling();
			Vertical = Character->UpDownValue;
			Horizontal = Character->LeftRightValue;
		}
}

//ĳ���Ϳ��� ������ ȣ����.
void UMyAnimInstance::PlayAttackMontage()
{
	//if (!Montage_IsPlaying(AttackMontage))//�ߺ� ���� ����. �̹� �������̸� �۵� x
	// ���� OnAttacking Ended�� ��������ν�, �ʿ䰡 ��������.

	Montage_Play(AttackMontage, 1.f); // ��Ÿ�� ���
}

void UMyAnimInstance::JumpToSection(int32 SectionIndex)
{
	FName Name = GetAttackMontageName(SectionIndex);
	Montage_JumpToSection(Name, AttackMontage);
}

FName UMyAnimInstance::GetAttackMontageName(int32 SectionIndex) //0 1 2 ��Ÿ�ְ� ���´�.
{
	return FName(*FString::Printf(TEXT("Attack%d"),SectionIndex));
}

void UMyAnimInstance::AnimNotify_AttackHit()
{
	UE_LOG(LogTemp, Warning, TEXT("NOTIFY"));
}
