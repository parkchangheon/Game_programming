// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/ABWidgetComponent.h"
#include "UI/ABUserWidget.h"

void UABWidgetComponent::InitWidget()
{
	Super::InitWidget();
	// �ش� ������ ���� �ν��Ͻ��� ���� ����.
	// ������ ���õ� UI ��ҵ��� ��� �غ� �Ǹ� NativeConstruct�� 

	UABUserWidget* ABUserWidget = Cast<UABUserWidget>(GetWidget());	//���� ������Ʈ�� ������ ������ ������
	if (ABUserWidget)
	{
		ABUserWidget->SetOwningActor(GetOwner());
	}

}