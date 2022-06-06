// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyCharacter.h"

AMyGameModeBase::AMyGameModeBase()
{
	DefaultPawnClass = AMyCharacter::StaticClass();


	//BP�� ã�� ����ϰ� ������!
	static ConstructorHelpers::FClassFinder<ACharacter> BP_Char(TEXT("Blueprint'/Game/Blueprint/Character/BP_MyCharacter.BP_MyCharacter_C'"));

	if (BP_Char.Succeeded())
		DefaultPawnClass = BP_Char.Class;
}