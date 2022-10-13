// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTCHASER_API UMyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;  //ĳ���� Ŭ�������� �ִ��ν��Ͻ��� ���ٺ���, �ִ��ν��Ͻ� -> ĳ���� Ŭ���� ������ ����.

	
public:
	/*UMyAnimInstance();*/
	/*void PlaySkillMontage();*/
	/*UAnimMontage* NoirSkillMontage;*/
private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	bool isFalling;

	
};
