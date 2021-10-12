// Copyright Epic Games, Inc. All Rights Reserved.

#include "C_Plus_projectGameMode.h"
#include "C_Plus_projectCharacter.h"
#include "UObject/ConstructorHelpers.h"

void AC_Plus_projectGameMode::BeginPlay() {
	Super::BeginPlay();

	//�⺻���� UE_LOG �޽���
	// LogTemp�� �α� �޽����� �ӽ� �α׿� ǥ��  , LOG ���� warning�� ���� ��������� ǥ��,    �α� �޽��� ��ü�� ǥ���ϴ� �ؽ�Ʈ ���ڿ�(TEXT)

	UE_LOG(LogTemp, Warning, TEXT("Some warning message")); 

	int intVar = 5;
	float floatVar = 3.7f;
	FString fstringVar = "an fstring variable";
	UE_LOG(LogTemp, Warning, TEXT("Text, %d %f %s"), intVar, floatVar, *fstringVar);   // *�� �����Ͱ� ����Ű�� ���� ���� ����Ű����.


	FString name = "SEAN PARKER";
	int32 mana = 450;
	//FString string = FString::Printf(TEXT("NAME = %s  MANA=%d"), *name, mana); //FString::Printf�� ����ϴ� ���


	TArray<FStringFormatArg> args;
	args.Add(FStringFormatArg(name));
	args.Add(FStringFormatArg(mana));

	FString string = FString::Format(TEXT("NAME = {0}  MANA={1}"), args);
	UE_LOG(LogTemp, Warning, TEXT("Your String is %s"), *string);



	//�ν��Ͻ�ȭ�� UClass �̸��� ������ ���� GameMode ������Ʈ�� ��´�
	AC_Plus_projectGameMode* gm = Cast<AC_Plus_projectGameMode>(
	GetWorld()->GetAuthGameMode());
	if (gm)
	{
		UUserProfile* newobject = NewObject<UUserProfile>(
			(UObject*)GetTransientPackage(),
			UUserProfile::StaticClass());

		//������Ʈ �ı�
		if (newobject) {
			newobject->ConditionalBeginDestroy();  // ���� ���������� ��� �����ϴ� ���. ==> ���Ŀ��� ���̻� ������� �ʾƾ��Ѵ�.
			newobject = nullptr;
		}
	}
}



AC_Plus_projectGameMode::AC_Plus_projectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}


}




