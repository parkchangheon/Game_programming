// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/PawnMovementComponent.h"


//UMyAnimInstance::UMyAnimInstance()
//{
//	static ConstructorHelpers::FObjectFinder<UAnimMontage> AM(TEXT("AnimMontage'/Game/ProjectAsset/Character/Theif_Noir/Noir_Mixamo_Standing_Melee_Attack_360_High_Anim_Retargeted_Montage.Noir_Mixamo_Standing_Melee_Attack_360_High_Anim_Retargeted_Montage'"));
//	if (AM.Succeeded())
//	{
//		NoirSkillMontage = AM.Object;
//
//	}
//}


void UMyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)  //�����Ӹ��� ������.
{
	Super::NativeUpdateAnimation(DeltaSeconds); 
	
	auto pawn = TryGetPawnOwner();   //�� Ŭ������ �����ϰ� �ִ� Pawn�� �޾ƿͼ�
	if (IsValid(pawn)) {  //�ִٸ�
		Speed = pawn->GetVelocity().Size();   //Speed ������ pawn�� �ӵ��� �� �����Ӹ��� �������ش�.
	
		auto Character = Cast<ACharacter>(pawn);
		if (Character) {
			isFalling = Character->GetMovementComponent()->IsFalling();
		}
	}


}

//void UMyAnimInstance::PlaySkillMontage()
//{
//	if (!Montage_IsPlaying(NoirSkillMontage)) {
//		Montage_Play(NoirSkillMontage, 1.f);
//	}
//
//}

