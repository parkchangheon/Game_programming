// Copyright Epic Games, Inc. All Rights Reserved.


#include "tutorial_characterGameModeBase.h"
#include "ARPlayer.h" // include ���ش�.

Atutorial_characterGameModeBase::Atutorial_characterGameModeBase() {

	//���⼭object�� ���� ��ü�� class�� � Ŭ������ ���Ǹ� �ϴ°�.
	DefaultPawnClass = AARPlayer::StaticClass(); // �����ڷ� �Ͽ��� .. �� ĳ���ͷ� �������ش�.(�����ҋ�)
}