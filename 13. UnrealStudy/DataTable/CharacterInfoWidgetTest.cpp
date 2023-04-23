// Fill out your copyright notice in the Description page of Project Settings.


#include "../UI/CharacterInfoWidgetTest.h"
#include "Components/TextBlock.h"
#include "DataObject.h"
#include "../Data/DataManager.h"
#include "../Data/CharacterDataTables.h"
#include "Engine/DataTable.h"


void UCharacterInfoWidgetTest::NativeConstruct()
{
	const auto& data = UDataManager::Ptr->GetCharacterData(FName("1"));
	const auto& lv = FString::FromInt(data.Level);

	const auto& hp = FString::FromInt(data.MaxHP);
	const auto& atk = FString::FromInt(data.Attack);

	CharacterLevel->SetText(FText::FromString(lv)); //TODO : ���⿡ dataTable���� ������ �����͸� �־��ش�.
	CharacterHp->SetText(FText::FromString(hp));
	CharacterAttack->SetText(FText::FromString(atk));
}

