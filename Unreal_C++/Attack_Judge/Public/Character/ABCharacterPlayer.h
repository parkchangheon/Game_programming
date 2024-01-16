// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/ABCharacter.h"
#include "InputActionValue.h"
#include "ABCharacterPlayer.generated.h"

/**
 * 
 */
UCLASS()
class TESTTT_API AABCharacterPlayer : public AABCharacter
{
	GENERATED_BODY()
	
public:
	AABCharacterPlayer();
	virtual void BeginPlay() override;	//MappingContext�� �Ҵ��ϴ� ������ ��.
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)override;	//�𸮾��� �Է½ý��ۿ��� �Է¾׼� (Move,Look �Լ�)�� ���� ���ν�����.


//Character Control Section
protected:
	void ChangeCharacterControl();
	void SetCharacterControl(ECharacterControlType NewCharacterControlType);
	virtual void SetCharacterControlData(const class UABChracterControlData* CharacterControlData) override;


//Camera Section
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, Meta=(AllowPrivateAccess = "true"))
	TObjectPtr<class USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, Meta=(AllowPrivateAccess = "true"))
	TObjectPtr<class UCameraComponent> FollowCamera;


// Input Section
protected:
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta=(AllowPrivateAccess = "true"))
	//TObjectPtr<class UInputMappingContext> DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta=(AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta=(AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> ChangeControlAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta=(AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> ShoulderMoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta=(AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> ShoulderLookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta=(AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> QuarterMoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta=(AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> AttackAction;

	void ShoulderMove(const FInputActionValue& Value);
	void ShoulderLook(const FInputActionValue& Value);

	void QuarterMove(const FInputActionValue& Value);

	void Attack();

	ECharacterControlType CurrentCharacterControlType;
};
